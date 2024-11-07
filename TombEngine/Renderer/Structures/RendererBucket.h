#pragma once

#include "Renderer/RendererEnums.h"
#include "Renderer/Structures/RendererPolygon.h"

namespace TEN::Renderer::Structures
{
	struct RendererBucket
	{
		int Texture;
		bool Animated;
		BlendMode BlendMode;
		int StartVertex;
		int StartIndex;
		int NumVertices;
		int NumIndices;
		Vector3 Centre;
		std::vector<RendererPolygon> Polygons;
	};
}
