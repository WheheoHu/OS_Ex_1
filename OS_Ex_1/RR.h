#pragma once
#include "Process_Sch_Base.h"
class RR :
	public Process_Sch_Base
{
public:
	RR(std::vector<Process> processes,int q);
	void start();
	static bool cmp_arrival_time(Process &, Process &);
	int q;
	~RR();
};

