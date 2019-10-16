#include "SJF.h"
#include<algorithm>

SJF::SJF(std::vector<Process> processes):Process_Sch_Base(processes)
{
	outfile.open("outSJF", std::ios::out);
}

void SJF::start()
{
	outfile << "SJF here" << std::endl;
	std::sort(processes.begin(), processes.end(), cmp);
	/*for (auto iter :processes )
	{

		outfile << iter.Process_name<<" "<<iter.Arrival_time << std::endl;
	}*/


	outfile.close();
}

bool SJF::cmp(Process & a, Process & b)
{
	return a.Arrival_time < b.Arrival_time;
}


SJF::~SJF()
{
}
