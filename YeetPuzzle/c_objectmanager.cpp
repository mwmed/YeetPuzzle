#include "c_objectmanager.h"

void puzzle::c_objectmanager::on_input_broadcast(int m_key, input_type type)
{
	for (auto object : m_inputobjects) {
		switch (type) {
		case input_type::down:
			object->on_key_down(m_key);
			break;
		case input_type::up:
			object->on_key_up(m_key);
			break;
		}
	}
}

void puzzle::c_objectmanager::on_update_interactables(POINT m_point)
{
	for (auto m_interactable : m_interactables) {
		if (m_interactable->is_hovering(m_point)) {
			if (!m_interactable->is_hovering_v) {
				m_interactable->is_hovering_v = true;
				m_interactable->on_enter_hover();
			}
		}
		else {
			if (m_interactable->is_hovering_v) {
				m_interactable->is_hovering_v = false;
				m_interactable->on_leave_hover();
			}
		}
	}
}
