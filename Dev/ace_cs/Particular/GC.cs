﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ace.Particular
{
	class GC
	{
		public static void SuppressFinalize(object obj)
		{
			System.GC.SuppressFinalize(obj);
		}
	}
}
