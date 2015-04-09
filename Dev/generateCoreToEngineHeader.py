import re
import codecs
import os
import os.path

def cd(path):
	os.chdir(path)

def cdToScript():
	cd(os.path.dirname(__file__))

class CreateHeader:
	def __init__(self):
		self.lines = []

	def append(self,s):
		self.lines.append(s)

	def readLines(self,path):
		f = codecs.open(path, 'r','utf-8_sig')
		line = f.readline()
		while line:
			if re.search('include( ?)\"', line) != None:
				line = f.readline()
				continue;

			if re.search('#pragma once', line) != None:
				line = f.readline()
				continue;

			if re.search('#include <Graphics/ace.', line) != None:
				line = f.readline()
				continue;

			if re.search('#include <Math/ace.', line) != None:
				line = f.readline()
				continue;

			self.lines.append(line)
			line = f.readline()
		self.lines.append('\r\n')
		f.close

	def output(self,path):
		f =  codecs.open(path, 'w','utf-8_sig')
		for line in self.lines:
			f.write(line)
		f.close()

cdToScript()

fromCoreToEngine = CreateHeader()
fromCoreToEngine.append('#pragma once')
fromCoreToEngine.append('\n#include <stdint.h>')
fromCoreToEngine.append('\n#include <ace.common.Base.h>')


fromCoreToEngine.readLines("ace_cpp/common/Math/ace.Vector2DI.h")
fromCoreToEngine.readLines("ace_cpp/common/Math/ace.Vector2DF.h")
fromCoreToEngine.readLines("ace_cpp/common/Math/ace.RectI.h")
fromCoreToEngine.readLines("ace_cpp/common/Math/ace.RectF.h")
fromCoreToEngine.append('namespace ace{ struct Vector3DF; }')
fromCoreToEngine.readLines("ace_cpp/common/Math/ace.Matrix44.h")
fromCoreToEngine.readLines("ace_cpp/common/Math/ace.Vector3DF.h")
fromCoreToEngine.readLines("ace_cpp/common/Math/ace.Vector4DF.h")
fromCoreToEngine.readLines("ace_cpp/common/Math/ace.Matrix33.h")

fromCoreToEngine.readLines("ace_cpp/common/Graphics/ace.Graphics.Common.h")
fromCoreToEngine.readLines("ace_cpp/common/Graphics/ace.Color.h")

fromCoreToEngine.readLines("ace_cpp/core/ace.Core.Base.h")
fromCoreToEngine.readLines("ace_cpp/core/ace.ReferenceObject.h")

fromCoreToEngine.readLines("ace_cpp/core/Input/ace.MouseButtonState.h")
fromCoreToEngine.readLines("ace_cpp/core/Input/ace.SideButton.h")
fromCoreToEngine.readLines("ace_cpp/core/Input/ace.MiddleButton.h")
fromCoreToEngine.readLines("ace_cpp/core/Input/ace.Mouse.h")
fromCoreToEngine.readLines("ace_cpp/core/Input/ace.Keyboard.h")
fromCoreToEngine.readLines("ace_cpp/core/Input/ace.Joystick.h")
fromCoreToEngine.readLines("ace_cpp/core/Input/ace.JoystickContainer.h")
fromCoreToEngine.readLines("ace_cpp/core/Log/ace.Log.h")
fromCoreToEngine.readLines("ace_cpp/core/Profiler/ace.Profiler.h")
                                                                       
fromCoreToEngine.readLines("ace_cpp/core/IO/ace.File.h")
fromCoreToEngine.readLines("ace_cpp/core/IO/ace.Path.h")
fromCoreToEngine.readLines("ace_cpp/core/IO/ace.StaticFile.h")
fromCoreToEngine.readLines("ace_cpp/core/IO/ace.StreamFile.h")

fromCoreToEngine.readLines("ace_cpp/core/Sound/ace.SoundSource.h")
fromCoreToEngine.readLines("ace_cpp/core/Sound/ace.Sound.h")

fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.Texture.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.Texture2D.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.RenderTexture2D.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.CubemapTexture.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.Shader2D.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.Shader3D.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.Material2D.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.Material3D.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.MaterialPropertyBlock.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.Font.h")

fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.ImagePackage.h")

fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.Chip2D.h")

fromCoreToEngine.readLines("ace_cpp/core/Graphics/Resource/ace.Effect.h")

fromCoreToEngine.readLines("ace_cpp/core/Graphics/3D/Resource/ace.Deformer.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/3D/Resource/ace.Mesh.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/3D/Resource/ace.Model.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/3D/Resource/ace.MassModel.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/3D/Resource/ace.Terrain3D.h")

fromCoreToEngine.readLines("ace_cpp/core/Graphics/3D/Resource/Animation/ace.KeyframeAnimation.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/3D/Resource/Animation/ace.AnimationSource.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/3D/Resource/Animation/ace.AnimationClip.h")
fromCoreToEngine.readLines("ace_cpp/core/Graphics/3D/Resource/Animation/ace.AnimationSystem.h")

fromCoreToEngine.readLines("ace_cpp/core/Graphics/ace.Graphics.h")

fromCoreToEngine.readLines("ace_cpp/core/Core/ace.Core.h")
fromCoreToEngine.readLines("ace_cpp/core/Core/ace.CreateCore.h")


fromCoreToEngine.readLines("ace_cpp/core/Shape/ace.ShapeType.h")
fromCoreToEngine.readLines("ace_cpp/core/Shape/ace.CoreShape.h")
fromCoreToEngine.readLines("ace_cpp/core/Shape/ace.CoreTriangleShape.h")
fromCoreToEngine.readLines("ace_cpp/core/Shape/ace.CoreCircleShape.h")
fromCoreToEngine.readLines("ace_cpp/core/Shape/ace.CoreArcShape.h")
fromCoreToEngine.readLines("ace_cpp/core/Shape/ace.CoreRectangleShape.h")
fromCoreToEngine.readLines("ace_cpp/core/Shape/ace.CoreLineShape.h")
fromCoreToEngine.readLines("ace_cpp/core/Shape/ace.CorePolygonShape.h")

fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/ace.ChildMode.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/ace.CoreLayer.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/ace.CoreScene.h')

fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/2D/ace.CoreObject2D.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/2D/ace.CoreTextureObject2D.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/2D/ace.CoreCameraObject2D.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/2D/ace.CoreTextObject2D.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/2D/ace.CoreEffectObject2D.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/2D/ace.CoreMapObject2D.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/2D/ace.CoreGeometryObject2D.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/2D/ace.CoreLayer2D.h')

fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/3D/ace.CoreObject3D.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/3D/ace.CoreModelObject3D.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/3D/ace.CoreDirectionalLightObject3D.h')
fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/3D/ace.CoreCameraObject3D.h')
fromCoreToEngine.readLines("ace_cpp/core/ObjectSystem/3D/ace.CoreEffectObject3D.h")
fromCoreToEngine.readLines("ace_cpp/core/ObjectSystem/3D/ace.CoreMassModelObject3D.h")
fromCoreToEngine.readLines("ace_cpp/core/ObjectSystem/3D/ace.CoreTerrainObject3D.h")

fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/3D/ace.CoreLayer3D.h')

fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/PostEffect/ace.CorePostEffect.h')

fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/Transition/ace.CoreTransition.h')

fromCoreToEngine.readLines('ace_cpp/core/ObjectSystem/ace.ObjectSystemFactory.h')

fromCoreToEngine.output('ace_cpp/engine/ace.CoreToEngine.h')
