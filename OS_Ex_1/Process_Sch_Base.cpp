#include "Process_Sch_Base.h"



Process_Sch_Base::Process_Sch_Base()
{
	
}

Process_Sch_Base::Process_Sch_Base(std::vector<Process> processes)
{
	this->processes = processes;
	this->Process_num = processes.size();
	
	Process_Sch_Base();
}


void Process_Sch_Base::start()
{
	
}

Process_Sch_Base::~Process_Sch_Base()
{
	
}
