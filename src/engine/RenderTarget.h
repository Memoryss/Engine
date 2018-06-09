#pragma once

#if defined(GLES2)
#include <GLES2/gl2.h>
#elif defined(GLES3)
#include <GLES3/gl3.h>
#else
#include <GL/glew.h>
#endif

enum RenderTargetType
{
	RT_Color = 0,
	RT_Depth,
};

class RenderTarget
{
public:
	RenderTarget(RenderTargetType type = RT_Color);

	~RenderTarget();

	bool BindFrameBuffer(GLenum target);

	void UnBindFrameBuffer();

private:
	RenderTargetType m_rt_type{ RT_Color };

	GLuint m_fbo{ 0 };			//frame buffer object

	GLenum m_bind_target{ 0 };
};