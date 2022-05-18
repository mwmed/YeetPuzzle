#include "yeet_text.h"

void yeet::objects::yeet_text::draw()
{
	auto m_drawlist = ImGui::GetForegroundDrawList();

	m_drawlist->AddText(ImVec2(m_position.x, m_position.y), m_color, m_text.c_str());
}
