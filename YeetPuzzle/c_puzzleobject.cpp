#include "c_puzzleobject.h"
#include "puzzle_globals.h"
void puzzle::game::c_puzzleobject::on_key_up(int key)
{
	switch (key) {
	case VK_LBUTTON:
	{
		auto puzzle_ui_manager = m_gamemanager->m_puzzleuimanager;
		if (is_hovering_v) {
			if (!puzzle_ui_manager->displayed_objects.empty()) {
				if (puzzle_ui_manager->displayed_objects.size() < 2) {
					m_canvas.b_drawtext = true;
					puzzle_ui_manager->displayed_objects.push_back(this);
					puzzle_ui_manager->displayobject_timer.tick();
				}
			}
			else {
				m_canvas.b_drawtext = true;
				puzzle_ui_manager->displayed_objects.push_back(this);
			}
		}
		break;
	}
	default:
		break;
	}
}

void puzzle::game::c_puzzleobject::on_key_down(int key)
{
}

void puzzle::game::c_puzzleobject::create()
{
	m_canvas.m_objidtext = std::to_string(m_itemid);
}

void puzzle::game::c_puzzleobject::update()
{
	if(!b_ismatched)
		m_canvas.update();


}

void puzzle::game::c_puzzleobject::destroy()
{
}

void puzzle::game::c_puzzleobject::calc_new_pos(std::uint8_t m_index)
{
	yeet::yeetvec4 m_rect;

	// ToDo calc rect size with window size factor
	m_rect.z = 50;// width;
	m_rect.w = 50; // height;

	auto obj_height_factor = (float)m_index / 5.0f;
	auto obj_width_factor = (((int)(obj_height_factor)+1) * 5) - m_index;

	m_rect.y = (int)obj_height_factor * 55 + 5;
	m_rect.x = obj_width_factor * 55 + 5;
	m_rect.z += m_rect.x;
	m_rect.w += m_rect.y;

	m_canvas.m_rectangle = m_rect;
}

bool puzzle::game::c_puzzleobject::is_hovering(POINT p)
{
	return m_canvas.is_hovering(p);
}


void puzzle::game::c_puzzleobject::on_enter_hover() 
{
	//spdlog::info("c_puzzleobject::on_enter_hover objid={}", m_objid);

	m_canvas.m_color = 0xFFFFFFFF;
}

void puzzle::game::c_puzzleobject::on_leave_hover()
{
	//spdlog::info("c_puzzleobject::on_leave_hover objid={}", m_objid);

	m_canvas.m_color = 0xFFFFFF00;
}