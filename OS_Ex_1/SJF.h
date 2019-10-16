#pragma once
#include "Process_Sch_Base.h"
//#include <fstream>
//#include <vector>

class SJF :
	public Process_Sch_Base
{
public:
	SJF();
	SJF(std::vector<Process> processes);
	void start();
	~SJF();
};

