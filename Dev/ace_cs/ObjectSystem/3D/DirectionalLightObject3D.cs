﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ace
{
	public class DirectionalLightObject3D : Object3D
	{
		swig.CoreDirectionalLightObject3D coreObject = null;

		public DirectionalLightObject3D()
		{
			coreObject = Engine.ObjectSystemFactory.CreateDirectionalLightObject3D();
			GC.Object3Ds.AddObject(coreObject.GetPtr(), this);
			commonObject = coreObject;
		}

		public override void Destroy()
		{
			coreObject = null;
			base.Destroy();
		}

		protected override void OnStart() { }
		protected override void OnUpdate() { }
		internal protected override void OnDrawAdditionally() { }

		public Color Color 
		{
			get { return coreObject.GetColor(); }
			set { coreObject.SetColor(ref value); }
		}
	}
}
