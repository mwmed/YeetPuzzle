#pragma once
#include "yeet_includes.h"













namespace yeet {
	class yeet_timer {
	public:
		inline yeet_timer(){}

		void tick();
		DWORD64 get_elapsed_time();

	private:
		DWORD64 m_starttime = 0;
	};
}