#include "c_gamemanager.h"
void puzzle::c_gamemanager::on_update()
{
	m_inputmanager->on_update();

	m_puzzleuimanager->update();

	m_drawmanager->on_update();
}
