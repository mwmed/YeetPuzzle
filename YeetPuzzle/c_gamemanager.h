#pragma once
#include "imyeet.h"
#include "c_puzzleuimanager.h"
#include "c_objectmanager.h"
#include "c_userinputmanager.h"












namespace puzzle {
	class c_gamemanager {
	public:
		c_gamemanager()
		{
			m_drawmanager = new yeet::imyeet();
			m_puzzleuimanager = new puzzle::game::c_puzzleuimanager();
			m_objectmanager = new puzzle::c_objectmanager();
			m_inputmanager = new puzzle::c_userinputmanager();
		}
		~c_gamemanager(){}

		bool is_active = true;
		HWND m_basewindow = 0;

		yeet::imyeet* m_drawmanager = nullptr;
		puzzle::c_objectmanager* m_objectmanager = nullptr;
		puzzle::game::c_puzzleuimanager* m_puzzleuimanager = nullptr;
		puzzle::c_userinputmanager* m_inputmanager = nullptr;



		void on_update();
	};
}