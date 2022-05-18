#include "imyeet.h"
#include "yeet_rectangle.h"
#include "yeet_text.h"

void yeet::imyeet::add_rect(yeetvec4 m_rectangle, ImU32 m_color, bool is_filled)
{
	auto m_rect = new objects::yeet_rectangle(m_rectangle, m_color, is_filled);

	m_objects.push_back(m_rect);
}

void yeet::imyeet::add_text(yeetvec2 m_pos, std::string m_text, ImU32 m_color)
{
	auto m_textobj = new objects::yeet_text(m_pos, m_text, m_color);
	m_objects.push_back(m_textobj);
}

void yeet::imyeet::on_update()
{
	while (!m_objects.empty()) {
		auto next = m_objects.front();

		if(next)
		next->draw();

		m_objects.pop_front();

		delete next;
		next = nullptr;
	}
}
