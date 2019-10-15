#pragma once
#include <vector>
#include <fstream>
#include "Process.h"



class Process_Sch_Base
{
public:
	Process_Sch_Base();

	Process_Sch_Base(std::vector<Process> process);

	virtual void start();

	virtual ~Process_Sch_Base();



	std::vector<Process> processes;
	int Process_num;
	std::fstream  outfile;

private:


};

