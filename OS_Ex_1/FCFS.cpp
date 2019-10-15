#include "FCFS.h"
#include <iostream>


FCFS::FCFS(std::vector<Process> processes):Process_Sch_Base(processes)
{
	outfile.open("outFCFS", std::ios::out);
}


void FCFS::start()
{
	auto &temp = processes[0];
	
	temp.End_time = temp.Arrival_time + temp.Service_time;
	temp.Turnaround_time = temp.End_time - temp.Service_time;
	temp.Weight_Turnaround_time = temp.Turnaround_time / temp.Service_time;

	//std::vector<Process>::iterator iter = processes.begin();
	for (auto iter = processes.begin()+1; iter != processes.end(); iter++)
	{
		auto temp = (--iter)->End_time;
		++iter;

		iter->End_time = temp + iter->Service_time;
		
		iter->Turnaround_time = iter->End_time - iter->Arrival_time;
		iter->Weight_Turnaround_time = iter->Turnaround_time / iter->Service_time;
	}


	outfile << "进程名 " << "到达时间 " << "服务时间 " << "完成时间 " << "周转时间 "<<"带权周转时间"<<std::endl;
	for (auto iter = processes.begin(); iter != processes.end(); iter++)
	{
		outfile << iter->getProcess_name() <<" "<< iter->getArrival_time() << " " << iter->getService_time() << " " << iter->getEnd_time() << " " << iter->getTurnaround_time() << " " << iter->getWeight_Turnaround_time() << std::endl;
	}
	
	outfile.close();
}

FCFS::~FCFS()
{
	
}
