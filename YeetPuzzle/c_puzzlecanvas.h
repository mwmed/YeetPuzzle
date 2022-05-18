#pragma once
#include "yeet_includes.h"
#include "yeet_math.h"













namespace puzzle {
	namespace game {
		class c_puzzlecanvas {
		public:
			inline c_puzzlecanvas(){}

			yeet::yeetvec4 m_rectangle;
			std::string m_objidtext = "";
			ImU32 m_color = 0xFFFFFFFF;

			bool b_drawtext = false;

			void update();
			bool is_hovering(POINT p);


		};
	}
}