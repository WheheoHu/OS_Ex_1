#include "SJF.h"



SJF::SJF()
{
}

SJF::SJF(std::vector<Process> processes):Process_Sch_Base(processes)
{
	outfile.open("outSJF", std::ios::out);
}

void SJF::start()
{
	outfile << "SJF here" << std::endl;
	outfile.close();
}


SJF::~SJF()
{
}
