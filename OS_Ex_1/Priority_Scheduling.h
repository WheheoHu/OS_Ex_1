#pragma once
#include "Process_Sch_Base.h"
class Priority_Scheduling :
	public Process_Sch_Base
{
public:
	Priority_Scheduling(std::vector<Process> processes);

	void start();
	static bool cmp_arrival_time(Process &, Process &);
	static bool cmp_priority(Process &,Process&);
	static double current_time;


	~Priority_Scheduling();

	
};

