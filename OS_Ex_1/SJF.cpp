#include "SJF.h"
#include<algorithm>
#include <iomanip>
double SJF::current_time = 0;

SJF::SJF(std::vector<Process> processes) :Process_Sch_Base(processes)
{
	outfile.open("outSJF", std::ios::out);
}

void SJF::start()
{
	outfile << "SJF here\n" << std::endl;
	std::sort(processes.begin(), processes.end(), cmp_arrival_time);


	//SJF
	auto &temp = processes[0];
	temp.End_time = temp.Arrival_time + temp.Service_time;
	temp.Turnaround_time = temp.End_time - temp.Service_time;
	temp.Weight_Turnaround_time = temp.Turnaround_time / temp.Service_time;

	for (int i = 1; i < Process_num; i++)
	{
	    current_time = processes.at(i - 1).End_time;
		std::sort(processes.begin()+i, processes.end(), cmp_servicetime_prio);
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

	double sum_ta_time = 0;
	double sum_wta_time = 0;

	for (auto iter : processes)
	{
		outfile << std::setw(6)<< iter.getProcess_name()
			<< std::setw(6) << iter.getArrival_time() 
			<< std::setw(6) << iter.getService_time()
			<< std::setw(6) << iter.getEnd_time() 
			<< std::setw(6) << iter.getTurnaround_time()
			<< std::setw(10) << iter.getWeight_Turnaround_time() 
			 << std::endl;
		sum_ta_time += iter.getArrival_time();
		sum_wta_time += iter.getWeight_Turnaround_time();
	}

	outfile << "Avg turnaound time : "<<sum_ta_time/Process_num<<std::endl;
	outfile << "Avg weight turnaound time : " << sum_wta_time / Process_num << std::endl;

	outfile.close();
}

bool SJF::cmp_arrival_time(Process & a, Process & b)
{
	return a.Arrival_time < b.Arrival_time;
}
bool SJF::cmp_servicetime_prio(Process & a, Process & b)
{

	return a.Service_time < b.Service_time && a.Arrival_time <= current_time;
}


SJF::~SJF()
{
}
