/*
 * =====================================================================================
 *
 *       Filename:  InterfaceState.hpp
 *
 *    Description:
 *
 *        Created:  08/04/2019 18:26:23
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef INTERFACESTATE_HPP_
#define INTERFACESTATE_HPP_

#include <gk/core/ApplicationState.hpp>
#include <gk/gl/Shader.hpp>

class InterfaceState : public gk::ApplicationState {
	public:
		InterfaceState(gk::ApplicationState *parent = nullptr);

	protected:
		void prepareDraw(gk::RenderTarget &target, gk::RenderStates &states) const;

	private:
		gk::Shader m_shader;
		// gk::View m_view;

		glm::mat4 m_projectionMatrix;
};

#endif // INTERFACESTATE_HPP_
