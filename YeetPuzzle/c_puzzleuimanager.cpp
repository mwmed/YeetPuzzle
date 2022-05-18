#include "c_puzzleuimanager.h"
#include "puzzle_globals.h"
#include "yeet_util.h"
void puzzle::game::c_puzzleuimanager::on_create_newgame(std::uint8_t maxobjcount)
{
	for (auto tree : m_objects) {
		auto obj = tree.second;
		delete obj;
		obj = nullptr;
	}

	m_objects.clear();
	m_maxcount = maxobjcount;

	int m_targetcounts = maxobjcount / 2;
	std::vector<int> m_targetids;
	for (int i = 0; i < m_targetcounts; i++) {
		m_targetids.push_back(i * 100);
	}

	int m_currentitemid = -1;
	for (int i = 0; i < m_maxcount; i++) {
		auto m_object = on_create_newobject(i,0);

		m_gamemanager->m_objectmanager->m_inputobjects.push_back(m_object);
		m_gamemanager->m_objectmanager->m_interactables.push_back(m_object);

		if (m_currentitemid == -1) {
			auto m_cid = yeet::rand_int(0, m_targetids.size() - 1);
			m_currentitemid = m_targetids[m_cid];

			m_object->m_itemid = m_currentitemid;

			auto it = m_targetids.begin();
			std::advance(it, m_cid);
			m_targetids.erase(it);
		}
		else {
			m_object->m_itemid = m_currentitemid;
			m_currentitemid = -1;
		}
		m_object->create();

	}

	std::vector<c_puzzleobject*> pobjects;
	for (auto m_obj : m_objects)
		pobjects.push_back(m_obj.second);

	for (int i = 0; i < m_maxcount; i++) {
		auto m_index = yeet::rand_int(0, pobjects.size() - 1);
		auto m_pobj = pobjects[m_index];

		m_pobj->calc_new_pos(i);

		m_objects_randomized.push_back(m_pobj);

		auto it = pobjects.begin();
		std::advance(it, m_index);
		pobjects.erase(it);
	}

}

puzzle::game::c_puzzleobject* puzzle::game::c_puzzleuimanager::on_create_newobject(std::uint8_t m_index, std::uint64_t m_itemid)
{
	yeet::yeetvec4 m_rect;

	// ToDo calc rect size with window size factor
	m_rect.z = 50;// width;
	m_rect.w = 50; // height;

	auto obj_height_factor = (float)m_index / 5.0f;
	auto obj_width_factor = (((int)(obj_height_factor) + 1) * 5) - m_index;

	m_rect.y = (int)obj_height_factor * 55 + 5;
	m_rect.x = obj_width_factor * 55 + 5;
	m_rect.z += m_rect.x;
	m_rect.w += m_rect.y;


	spdlog::info("Created new game object[{}] m_rect({}, {}, {}, {})",m_index, m_rect.x, m_rect.y, m_rect.z, m_rect.w);


	auto m_obj = new c_puzzleobject(m_itemid, m_itemid, m_rect, 0xFFFFFFFF);

	m_objects[m_index] = m_obj;
	return m_obj;
}

void puzzle::game::c_puzzleuimanager::create()
{
}

void puzzle::game::c_puzzleuimanager::update()
{
	for (auto m_obj : m_objects_randomized) {
	//	m_gamemanager->m_drawmanager->add_rect(m_obj.second->m_canvas.m_rectangle, 0xFFFFFF00, false);

		m_obj->update();
	}

	if (displayed_objects.size() > 1) {
		if (displayobject_timer.get_elapsed_time() >= 750) {

			bool is_matched = false;
			if (displayed_objects[0]->m_itemid == displayed_objects[1]->m_itemid)
				is_matched = true;
			while (!displayed_objects.empty()) {
				auto next = displayed_objects.front();

				next->m_canvas.b_drawtext = false;

				if (is_matched)
					next->b_ismatched = is_matched;
				displayed_objects.pop_front();
			}
		}
	}
}

void puzzle::game::c_puzzleuimanager::destroy()
{
}
