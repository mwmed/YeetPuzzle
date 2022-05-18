#pragma once
#include "c_inputobject.h"
#include "c_interactableobject.h"

#include "puzzleconstants.h"













namespace puzzle {
	class c_objectmanager {
	public:

		std::vector<objects::c_inputobject*> m_inputobjects;
		std::vector<objects::c_interactableobject*> m_interactables;


		void on_input_broadcast(int m_key, input_type type);

		void on_update_interactables(POINT m_point);
	};
}