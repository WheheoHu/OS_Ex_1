#include "FCFS.h"
//#include <iostream>
#include <algorithm>
#include <iomanip>

FCFS::FCFS(std::vector<Process> processes) :Process_Sch_Base(processes)
{
	outfile.open("outFCFS", std::ios::out);
}


void FCFS::start()
{
	outfile << "FCFS here\n" << std::endl;
	std::sort(processes.begin(), processes.end(), cmp);
	auto &temp = processes[0];

	temp.End_time = temp.Arrival_time + temp.Service_time;
	temp.Turnaround_time = temp.End_time - temp.Service_time;
	temp.Weight_Turnaround_time = temp.Turnaround_time / temp.Service_time;

	for (auto iter = processes.begin() + 1; iter != processes.end(); iter++)
	{
		auto temp = (--iter)->End_time;
		++iter;

		iter->End_time = temp + iter->Service_time;

		iter->Turnaround_time = iter->End_time - iter->Arrival_time;
		iter->Weight_Turnaround_time = iter->Turnaround_time / iter->Service_time;
	}


	//Output to file 

	double sum_ta_time = 0;
	double sum_wta_time = 0;

	for (auto iter : processes)
	{
		outfile << std::setw(6) << iter.getProcess_name()
			<< std::setw(6) << iter.getArrival_time()
			<< std::setw(6) << iter.getService_time()
			<< std::setw(6) << iter.getEnd_time()
			<< std::setw(6) << iter.getTurnaround_time()
			<< std::setw(10) << iter.getWeight_Turnaround_time()
			<< std::endl;
		sum_ta_time += iter.getArrival_time();
		sum_wta_time += iter.getWeight_Turnaround_time();
	}

	outfile << "Avg turnaound time : " << sum_ta_time / Process_num << std::endl;
	outfile << "Avg weight turnaound time : " << sum_wta_time / Process_num << std::endl;

	outfile.close();
}

FCFS::~FCFS()
{

}

bool FCFS::cmp(Process & _a, Process & _b)
{
	return _a.Arrival_time<_b.Arrival_time;
}
