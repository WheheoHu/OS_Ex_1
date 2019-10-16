#include "SJF.h"
#include<algorithm>

double SJF::current_time = 0;

SJF::SJF(std::vector<Process> processes) :Process_Sch_Base(processes)
{
	outfile.open("outSJF", std::ios::out);
}

void SJF::start()
{
	outfile << "SJF here\n" << std::endl;
	std::sort(processes.begin(), processes.end(), cmp);


	//SJF
	auto &temp = processes[0];
	temp.End_time = temp.Arrival_time + temp.Service_time;
	temp.Turnaround_time = temp.End_time - temp.Service_time;
	temp.Weight_Turnaround_time = temp.Turnaround_time / temp.Service_time;

	for (int i = 1; i < Process_num; i++)
	{
	    current_time = processes.at(i - 1).End_time;
		std::sort(processes.begin()+i, processes.end(), cmp1);
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
		outfile << iter.getProcess_name() << "\t " << iter.getArrival_time() << " " << iter.getService_time() << " " << iter.getEnd_time() << " " << iter.getTurnaround_time() << " " << iter.getWeight_Turnaround_time() << std::endl;
	}


	outfile.close();
}

bool SJF::cmp(Process & a, Process & b)
{
	return a.Arrival_time < b.Arrival_time;
}
bool SJF::cmp1(Process & a, Process & b)
{

	return a.Service_time < b.Service_time && a.Arrival_time <= current_time;
}


SJF::~SJF()
{
}
