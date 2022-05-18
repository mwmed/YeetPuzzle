#pragma once
#include "c_gameobject.h"
#include "c_inputobject.h"
#include "c_interactableobject.h"
#include "c_puzzlecanvas.h"


















namespace puzzle {
	namespace game {
		class c_puzzleobject : public objects::c_gameobject, public objects::c_inputobject, public objects::c_interactableobject
		{
		public:
			inline c_puzzleobject(std::uint16_t p_objid, std::uint64_t p_itemid, yeet::yeetvec4 rect, ImU32 col)
			{
				m_objid = p_objid;
				m_itemid = p_itemid;

				m_canvas.m_rectangle = rect;
				m_canvas.m_color = col;
			}

			std::uint16_t m_objid = 0;
			std::uint64_t m_itemid = 0;
			c_puzzlecanvas m_canvas;


			bool b_ismatched = false;


		public:
			void calc_new_pos(std::uint8_t m_index);


			// Inherited via c_inputobject
			virtual void on_key_up(int key) override;

			virtual void on_key_down(int key) override;


			// Inherited via c_gameobject
			virtual void create() override;

			virtual void update() override;

			virtual void destroy() override;


			// Inherited via c_interactableobject
			virtual void on_enter_hover() override;

			virtual void on_leave_hover() override;

			virtual bool is_hovering(POINT p) override;

		};
	}
}