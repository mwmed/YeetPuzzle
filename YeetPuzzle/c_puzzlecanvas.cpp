#include "c_puzzlecanvas.h"
#include "yeet_rectangle.h"
#include "puzzle_globals.h"

void puzzle::game::c_puzzlecanvas::update()
{
	m_gamemanager->m_drawmanager->add_rect(m_rectangle, m_color, false);
	if(b_drawtext)
	m_gamemanager->m_drawmanager->add_text(yeet::yeetvec2((m_rectangle.x + m_rectangle.z) / 2, (m_rectangle.y + m_rectangle.w) / 2),m_objidtext, m_color);
}

bool puzzle::game::c_puzzlecanvas::is_hovering(POINT p)
{
	auto rectangle = yeet::objects::yeet_rectangle(m_rectangle);
	return rectangle.is_hovering(p);
}
