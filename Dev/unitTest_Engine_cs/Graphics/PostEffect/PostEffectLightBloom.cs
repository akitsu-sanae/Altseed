﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace unitTest_Engine_cs.Graphics.PostEffect
{
	class PostEffectLightBloom : EngineTest
	{
		public PostEffectLightBloom()
			: base(10)
		{
		}

		protected override void OnStart()
		{
			var scene = new asd.Scene();
			var layer = new asd.Layer2D();
			var obj = new asd.TextureObject2D();
			scene.AddLayer(layer);
			layer.AddObject(obj);
			asd.Engine.ChangeScene(scene);

			var g = asd.Engine.Graphics;
			var texture = g.CreateTexture2D("Data/Texture/Sample1.png");
			obj.Texture = texture;
			obj.Scale = new asd.Vector2DF(1, 1);

			var pe = new asd.PostEffectLightBloom();
			pe.Intensity = 5.0f;
			pe.Threshold = 0.3f;
			pe.Exposure = 2.0f;
			layer.AddPostEffect(pe);
		}
	}
}
