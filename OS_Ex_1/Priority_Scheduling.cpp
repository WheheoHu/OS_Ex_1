#include "Priority_Scheduling.h"
#include <algorithm>
#include <iomanip>

double Priority_Scheduling::current_time = 0;


Priority_Scheduling::Priority_Scheduling(std::vector<Process> processes):Process_Sch_Base(processes)
{
	outfile.open("outPrioritySch", std::ios::out);
}

void Priority_Scheduling::start()
{

	outfile << "Prioritysch here\n" << std::endl;
	std::sort(processes.begin(), processes.end(), cmp_arrival_time);



	//SJF
	auto &temp = processes[0];
	temp.End_time = temp.Arrival_time + temp.Service_time;
	temp.Turnaround_time = temp.End_time - temp.Service_time;
	temp.Weight_Turnaround_time = temp.Turnaround_time / temp.Service_time;

	for (int i = 1; i < Process_num; i++)
	{
		current_time = processes.at(i - 1).End_time;
		std::sort(processes.begin() + i, processes.end(), cmp_priority);
		if (processes[i - 1].End_time < processes[i].Arrival_time)
		{
			processes[i].End_time = processes[i - 1].End_time + processes[i].Service_time + (processes[i].Arrival_time - processes[i - 1].End_time);
		}
		else
		{

			processes[i].End_time = processes[i - 1].End_time + processes[i].Service_time;

		}
		processes[i].Turnaround_time = processes[i].End_time - processes[i].Arrival_time;
		processes[i].Weight_Turnaround_time = processes[i].Turnaround_time / processes[i].Service_time;

	}




	//Output to file 
	for (auto iter : processes)
	{
		outfile << std::setw(6) << iter.getProcess_name()
			<< std::setw(6) << iter.getArrival_time()
			<< std::setw(6) << iter.getService_time()
			<< std::setw(6) << iter.getEnd_time()
			<< std::setw(6) << iter.getTurnaround_time()
			<< std::setw(10) << iter.getWeight_Turnaround_time()
			<< std::setw(6) << iter.getWeight() << std::endl;
	}
	outfile.close();
}

bool Priority_Scheduling::cmp_arrival_time(Process & _a, Process &_b)
{
	return _a.Arrival_time < _b.Arrival_time;
}

bool Priority_Scheduling::cmp_priority(Process & _a, Process & _b)
{
	return _a.getWeight() < _b.getWeight()&&  _a.getArrival_time() <= current_time;
}


Priority_Scheduling::~Priority_Scheduling()
{
}
