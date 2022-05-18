#include "yeet_timer.h"

void yeet::yeet_timer::tick()
{
	m_starttime = GetTickCount64();
}

DWORD64 yeet::yeet_timer::get_elapsed_time()
{
	return GetTickCount64() - m_starttime;
}
