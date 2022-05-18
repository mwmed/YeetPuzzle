#pragma once
#include "yeet_drawable.h"
#include "yeet_math.h"





















namespace yeet {
	namespace objects {
		class yeet_rectangle : public yeet_drawable {
		public:
			inline yeet_rectangle(yeetvec4 p_rectangle = yeetvec4(0, 0, 0, 0), ImU32 col = 0xFFFFFFFF, bool filled = true) : m_rectangle(p_rectangle), m_filled(filled), m_color(col) {}


			yeetvec4 m_rectangle;
			ImU32 m_color = 0xFFFFFFFF;
			bool m_filled = false;

			bool is_hovering(POINT p);
			// Inherited via yeet_drawable
			virtual void draw() override;
		};
	}
}