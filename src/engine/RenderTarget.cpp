#include "RenderTarget.h"

RenderTarget::RenderTarget(RenderTargetType type /*= RT_Color*/)
{
	glGenFramebuffers(1, &m_fbo);
}

RenderTarget::~RenderTarget()
{
	if (m_fbo > 0)
	{
		glDeleteBuffers(1, &m_fbo);
	}
}

bool RenderTarget::BindFrameBuffer(GLenum target)
{
	if (m_fbo <= 0)
	{
		return false;
	}

	m_bind_target = target;
	glBindFramebuffer(target, m_fbo);
	return true;
}

void RenderTarget::UnBindFrameBuffer()
{
	if (m_bind_target <= 0)
		return;

	m_bind_target = 0;
	glBindFramebuffer(m_bind_target, 0);
}
