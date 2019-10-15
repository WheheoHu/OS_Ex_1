#include "FCFS.h"



FCFS::FCFS(std::vector<Process> processes):Process_Sch_Base(processes)
{
	
}


void FCFS::start()
{
	std::cout << "start" << std::endl;
	std::cout << Process_num << std::endl;
}

FCFS::~FCFS()
{
}
