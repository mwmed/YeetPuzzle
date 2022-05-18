#pragma once
#include "c_puzzleobject.h"
#include "yeet_timer.h"



















namespace puzzle {
	namespace game {
		class c_puzzleuimanager : public objects::c_gameobject {
		public:
			inline c_puzzleuimanager() {}


			 void on_create_newgame(std::uint8_t maxobjcount);
			 c_puzzleobject* on_create_newobject(std::uint8_t m_index, std::uint64_t m_itemid);
		
			 std::deque<c_puzzleobject*> displayed_objects;

			 yeet::yeet_timer displayobject_timer;


		private:
			std::unordered_map<std::uint64_t, c_puzzleobject*> m_objects;
			std::uint8_t m_maxcount = 0;
			std::vector<c_puzzleobject*> m_objects_randomized;
		public:
			// Inherited via c_gameobject
			virtual void create() override;

			virtual void update() override;

			virtual void destroy() override;

		};
	}
}