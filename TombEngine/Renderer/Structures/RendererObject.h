#pragma once

#include "Renderer/RendererEnums.h"
#include "Renderer/Structures/RendererBone.h"
#include "Renderer/Structures/RendererMesh.h"

namespace TEN::Renderer::Structures
{
	struct RendererObject
	{
		int Id;
		int Type;
		std::vector<RendererMesh*> ObjectMeshes;
		RendererBone* Skeleton;
		std::vector<Matrix> AnimationTransforms;
		std::vector<Matrix> BindPoseTransforms;
		std::vector<RendererBone*> LinearizedBones;
		bool DoNotDraw;
		ShadowMode ShadowType;

		~RendererObject()
		{
			for (int i = 0; i < LinearizedBones.size(); i++)
				delete LinearizedBones[i];
		}
	};
}
