#pragma once
#include "Process_Sch_Base.h"
#include <iostream>
#include <vector>
class FCFS :
	public Process_Sch_Base
{
public:
	FCFS(std::vector<Process> processes);
	
	void start();

	~FCFS();
};

