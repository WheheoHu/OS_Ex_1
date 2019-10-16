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
	static bool cmp(Process &a, Process &b);
	~SJF();
};

