#pragma once
#include "yeet_drawable.h"
#include "yeet_math.h"





















namespace yeet {
	namespace objects {
		class yeet_text : public yeet_drawable {
		public:
			inline yeet_text(yeetvec2 p_position = yeetvec2(0,0), std::string p_text = "", ImU32 p_color = 0xFFFFFFFF) : m_position(p_position), m_text(p_text), m_color(p_color) {}

			yeetvec2 m_position;
			std::string m_text = "";
			ImU32 m_color = 0xFFFFFFFF;


			// Inherited via yeet_drawable
			virtual void draw() override;
		};
	}
}