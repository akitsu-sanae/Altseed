﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace sample_cs
{
	class Program
	{
		static void Main(string[] args)
		{
			ISample[] samples = 
			{
				new Window.Empty(),
				new Window.EmptyExternal(),

				new Log(),

                new Input.Keyboard(),
                new Input.Mouse(),
                new Input.Joystick(),

				new Sound.Sound(),

				new Graphics._2D.EffectObject2D(),

				new Graphics.PostEffect.PostEffect(),
				new Graphics.PostEffect.CustomPostEffect(),
			};

			var cui = new SampleGuide( samples );
			cui.Show();
		}
	}
}
