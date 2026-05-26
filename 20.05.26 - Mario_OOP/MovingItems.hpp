#pragma once 
#include "BaseObject.hpp"

namespace pav {
	class MovingItem : public MovingObject {
	public:
		MovingItem(
			const float xPos,
			const float yPos,
			const float oWidth,
			const float oHeight,
			const char inType
		)
			: MovingObject(
				xPos,
				yPos,
				oWidth,
				oHeight,
				inType
			) {}

		~MovingItem() override = default;

		void update(Game& game) override;
	};

}