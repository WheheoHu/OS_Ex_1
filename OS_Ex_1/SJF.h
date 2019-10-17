#pragma once
#include "Process_Sch_Base.h"
//#include <fstream>
//#include <vector>

class SJF :
	public Process_Sch_Base
{
public:
	SJF(std::vector<Process> processes);
	void start();
	static bool cmp_arrival_time(Process &a, Process &b);
	static bool cmp_servicetime_prio(Process &a, Process &b);
	static double current_time;
	~SJF();

};

