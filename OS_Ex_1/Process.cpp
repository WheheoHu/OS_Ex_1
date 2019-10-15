#include "Process.h"



Process::Process()
{
	std::cout << "Process start!\n";
}

Process::Process(std::string ProcessName, double Arrival_time, double Service_time)
{
	this->Process_name = ProcessName;
	this->Arrival_time = Arrival_time;
	this->Service_time = Service_time;
	Process();
}


Process::~Process()
{
}

int Process::getpos()
{
	return this->pos;
}

std::string Process::getProcess_name()
{

	return this->Process_name;
}

double Process::getArrival_time()
{
	return this->Arrival_time;
}

double Process::getService_time()
{
	return this->Service_time;
}

double Process::getStart_time()
{
	return this->Start_time;
}

double Process::getEnd_time()
{
	return this->End_time;
}

double Process::getTurnaround_time()
{
	return this->Turnaround_time;

}

double Process::getWeight_Turnaround_time()
{
	return this->Weight_Turnaround_time;
}
