#pragma once
#include "yeet_drawable.h"
#include "yeet_math.h"













namespace yeet {
	class imyeet {
	public:
		inline imyeet(){}


		void add_rect(yeetvec4 m_rectangle, ImU32 m_color, bool is_filled);
		void add_text(yeetvec2 m_pos, std::string m_text, ImU32 m_color);

		void on_update();


	private:
		std::deque<objects::yeet_drawable*> m_objects;
	};
}