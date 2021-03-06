﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using FontGenerator.swig;
using System.IO;

namespace FontGenerator
{
	class Program
	{
		static void Main(string[] args)
		{
			var gen = new DLL();

			Console.WriteLine("使用するフォントファイルを指定してください。");
			gen.SetFontName(ReadFileName());

			Console.WriteLine("\n使用するテキストファイルのパスを指定してください。");
			gen.SetTextFilePath(ReadFileName());

			Console.WriteLine("\n出力先のファイル名(拡張子除く)を指定してください。");
			Console.Write("> ");
			gen.SetExportPath(Console.ReadLine());

			Console.WriteLine("\nフォントサイズを指定してください。");
			gen.SetFontSize(ReadInt());

			Console.WriteLine("\n画像のサイズを指定してください。");
			gen.SetSheetSize(ReadInt());

			Console.WriteLine("\nフォントの色を指定してください[0-255]");
			Console.Write("  Red> ");
			var r = ReadByte();
			Console.Write("Green> ");
			var g = ReadByte();
			Console.Write(" Blue> ");
			var b = ReadByte();
			Console.Write("Alpha> ");
			var a = ReadByte();
			gen.SetFontColor(r, g, b, a);

			Console.WriteLine("\nフォント生成中…");
			gen.Run();

			Console.WriteLine("生成しました。");
			Console.ReadKey();
		}

		private	static int ReadInt()
		{
			while(true)
			{
				Console.Write("> ");
				int i;
				var result = int.TryParse(Console.ReadLine(), out i);
				if(result)
				{
					return i;
				}
			}
		}

		private static byte ReadByte()
		{
			while(true)
			{
				byte b;
				var result = byte.TryParse(Console.ReadLine(), out b);
				if(result)
				{
					return b;
				}
			}
		}

		static string ReadFileName()
		{
			while(true)
			{
				Console.Write("> ");
				string str = Console.ReadLine();
				if(File.Exists(str))
				{
					return str;
				}
				else
				{
					Console.WriteLine("ファイルが存在しません。");
				}
			}
		}
	}
}
