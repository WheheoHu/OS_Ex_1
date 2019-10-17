#include "RR.h"

#include <algorithm>
#include <iomanip>


RR::RR(std::vector<Process> processes, int q):Process_Sch_Base(processes)
{
	this->q = q;
	outfile.open("outRR", std::ios::out);
}

void RR::start()
{

	outfile << "RR here\n" << std::endl;
	std::sort(processes.begin(), processes.end(), cmp_arrival_time);

	//RR here


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

bool RR::cmp_arrival_time(Process & _a, Process & _b)
{
	return _a.getArrival_time() < _b.getArrival_time();
}


RR::~RR()
{
}
