/*
 * =====================================================================================
 *
 *  OpenMiner
 *
 *  Copyright (C) 2018-2020 Unarelith, Quentin Bazin <openminer@unarelith.net>
 *  Copyright (C) 2019-2020 the OpenMiner contributors (see CONTRIBUTORS.md)
 *
 *  This file is part of OpenMiner.
 *
 *  OpenMiner is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  OpenMiner is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with OpenMiner; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <gk/core/Box.hpp>

#include "Inventory.hpp"
#include "ISerializable.hpp"

class Player : public ISerializable {
	public:
		Player();

		void serialize(sf::Packet &packet) const override;
		void deserialize(sf::Packet &packet) override;

		double x() const { return m_x; }
		double y() const { return m_y; }
		double z() const { return m_z; }

		u16 dimension() const { return m_dimension; }

		u16 clientID() const { return m_clientID; }

		Inventory &inventory() { return m_inventory; }

		void setPosition(double x, double y, double z) { m_x = x; m_y = y; m_z = z; }
		void setDimension(u16 dimension) { m_dimension = dimension; }
		void setClientID(u16 clientID) { m_clientID = clientID; }

		const gk::FloatBox &hitbox() const { return m_hitbox; }

	protected:
		double m_x = 0;
		double m_y = 0;
		double m_z = 0;

		u16 m_dimension = 0;

		u16 m_clientID = 0;

		Inventory m_inventory{9, 4};

		gk::FloatBox m_hitbox;
};

#endif // PLAYER_HPP_
