﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace asd.Particular
{
	class Define
	{
#if __MonoCS__
		public const string DLL = "Altseed_core";
#else
#if DEBUG
		public const string DLL = "Altseed_core_Debug";
#else
		public const string DLL = "Altseed_core";
#endif
#endif
	}
}
