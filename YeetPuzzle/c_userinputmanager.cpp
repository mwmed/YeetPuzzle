#include "c_userinputmanager.h"
#include "puzzle_globals.h"

void puzzle::c_userinputmanager::on_update()
{
    if (GetKeyboardState(kbkeys)) {
        for (int i = 0; i < 256; i++) {
            if (kbkeys[i] & 0x80) {
                down_keys[i] = true;

                m_gamemanager->m_objectmanager->on_input_broadcast(i, input_type::down);
            }
            else if (down_keys[i]) {
                down_keys[i] = false;
                m_gamemanager->m_objectmanager->on_input_broadcast(i, input_type::up);
            }
        }
    }


    m_previouscs = m_currentcs;
    GetCursorPos(&m_currentcs);
    ScreenToClient(m_gamemanager->m_basewindow, &m_currentcs);

    if (m_previouscs.x != m_currentcs.x || m_previouscs.y != m_currentcs.y) {
        m_gamemanager->m_objectmanager->on_update_interactables(m_currentcs);
    }
}

POINT puzzle::c_userinputmanager::get_cs()
{
    return m_currentcs;
}
