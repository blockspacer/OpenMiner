/*
 * =====================================================================================
 *
 *       Filename:  SettingsMenuState.hpp
 *
 *    Description:
 *
 *        Created:  29/06/2018 06:11:43
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SETTINGSMENUSTATE_HPP_
#define SETTINGSMENUSTATE_HPP_

#include <gk/graphics/RectangleShape.hpp>

#include "GameKey.hpp"
#include "InterfaceState.hpp"
#include "MenuWidget.hpp"

class SettingsMenuState : public InterfaceState {
	public:
		SettingsMenuState(gk::ApplicationState *parent = nullptr);

		void onEvent(const SDL_Event &event) override;

		void update() override;

	private:
		void addMainButtons();
		void addGameplayButtons();
		void addGraphicsButtons();
		void addInputButtons();

		void addToggleButton(const std::string &text, bool &configOption, bool worldReloadRequested = false);

		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		gk::RectangleShape m_background;

		MenuWidget m_menuWidget;
		TextButton m_doneButton;

		u8 m_currentKey = GameKey::Undefined;
		TextButton *m_currentKeyButton = nullptr;
};

#endif // SETTINGSMENUSTATE_HPP_
