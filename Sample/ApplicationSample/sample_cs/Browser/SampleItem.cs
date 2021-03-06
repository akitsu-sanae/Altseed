﻿

class SampleItem : asd.TextureObject2D
{
	public static readonly asd.Vector2DF Size = new asd.Vector2DF(150, 112.5f);
	public static int TitleMaxLength = 9;

	private asd.RectangleShape shape_;
	private asd.TextureObject2D frame { get; set; }

	public ISample Sample { get; private set; }
	public asd.RectangleShape Shape
	{
		get
		{
			if(shape_ == null)
			{
				shape_ = GetArea();
			}
			return shape_;
		}
	}
	public asd.TextObject2D Title { get; private set; }

	public new asd.Vector2DF Position
	{
		get { return base.Position; }
		set
		{
			base.Position = value;
			shape_ = null;
		}
	}

	public SampleItem(ISample sample, asd.Font font)
	{
		Sample = sample;

		Texture = asd.Engine.Graphics.CreateTexture2D("Data/Browser/" + sample.ClassName + ".png");
		TextureFilterType = asd.TextureFilterType.Linear;
		if(Texture == null)
		{
			Texture = asd.Engine.Graphics.CreateTexture2D("Data/Browser/Default.png");
		}
		Scale = Size / Texture.Size.To2DF();

		string text = "";
		if(sample.Title != "")
		{
			text = sample.Title;
		}
		else
		{
			text = sample.ClassName;
		}

		Title = new asd.TextObject2D();
		Title.Text = GetWrappedString(font, text);
		Title.Font = font;
		Title.Position = new asd.Vector2DF(0, 115);
		Title.DrawingPriority = 1;

		frame = new asd.TextureObject2D();
		frame.Texture = asd.Engine.Graphics.CreateTexture2D("Data/Browser/Frame.png");
		frame.Position = new asd.Vector2DF(-3, -3);
	}

	public asd.RectangleShape GetArea()
	{
		var area = new asd.RectangleShape();
		area.DrawingArea = new asd.RectF(Position.X, Position.Y, Size.X, Size.Y);
		return area;
	}

	private string GetWrappedString(asd.Font font, string title)
	{
		string result = title;
		if(font.CalcTextureSize(result, asd.WritingDirection.Horizontal).X <= Size.X)
		{
			return result;
		}
		while(font.CalcTextureSize(result + "…", asd.WritingDirection.Horizontal).X > Size.X)
		{
			result = result.Substring(0, result.Length - 1);
		}
		return result + "…";
	}

	protected override void OnAdded()
	{
		Layer.AddObject(Title);
		Layer.AddObject(frame);

		AddChild(Title, asd.ChildManagementMode.Nothing, asd.ChildTransformingMode.Position);
		AddChild(frame, asd.ChildManagementMode.Nothing, asd.ChildTransformingMode.Position);
	}

	protected override void OnDispose()
	{
		Title.Dispose();
		frame.Dispose();
	}

	public void Activate()
	{
		frame.Texture = asd.Engine.Graphics.CreateTexture2D("Data/Browser/FrameActive.png");
	}

	public void Disactivate()
	{
		frame.Texture = asd.Engine.Graphics.CreateTexture2D("Data/Browser/Frame.png");
	}
}