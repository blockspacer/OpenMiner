/*
 * =====================================================================================
 *
 *       Filename:  Hotbar.hpp
 *
 *    Description:
 *
 *        Created:  20/06/2018 05:40:05
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef HOTBAR_HPP_
#define HOTBAR_HPP_

#include <vector>

#include "ItemWidget.hpp"
#include "SDLHeaders.hpp"

class Hotbar : public IDrawable {
	public:
		Hotbar();

		void onEvent(const SDL_Event &event);

		int cursorPos() const { return m_cursorPos; }

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		Image m_background;

		Image m_cursor;
		int m_cursorPos = 0;

		std::vector<ItemWidget> m_items;
};

#endif // HOTBAR_HPP_