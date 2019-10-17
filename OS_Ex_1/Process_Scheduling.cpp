#include "Process.h"
#include <iostream>
#include <vector>
#include <fstream>

#include"FCFS.h"
#include "SJF.h"
#include "Priority_Scheduling.h"
//Global
static int Process_Num = 0;
std::vector<Process> All_Process;

void fcfstest();
void sjftest();
void priorityschtest();


int main() {

	fcfstest();
	sjftest();
	priorityschtest();
	//system("pause");
	return 0;
}



void fcfstest() {
	std::fstream infile("inFCFS", std::ios::in);
	infile >> Process_Num;
	std::cout << Process_Num << std::endl;



	for (int i = 0; i < Process_Num; i++)
	{
		std::string temp_process_name;
		double temp_arrival_time;
		double temp_service_time;
		infile >> temp_process_name >> temp_arrival_time >> temp_service_time;
		All_Process.push_back(Process(temp_process_name, temp_arrival_time, temp_service_time));
	}

	FCFS fcfs(All_Process);
	fcfs.start();

	All_Process.clear();
	infile.close();
}

void sjftest()
{
	std::fstream infile("inSJF", std::ios::in);
	infile >> Process_Num;
	std::cout << Process_Num << std::endl;

	for (int i = 0; i < Process_Num; i++)
	{
		std::string temp_process_name;
		double temp_arrival_time;
		double temp_service_time;
		infile >> temp_process_name >> temp_arrival_time >> temp_service_time;
		All_Process.push_back(Process(temp_process_name, temp_arrival_time, temp_service_time));
	}

	SJF sjf(All_Process);
	sjf.start();

	All_Process.clear();
	infile.close();

}

void priorityschtest() {
	std::fstream infile("inPrioritySch", std::ios::in);
	infile >> Process_Num;
	std::cout << Process_Num << std::endl;

	for (int i = 0; i < Process_Num; i++)
	{
		std::string temp_process_name;
		double temp_arrival_time;
		double temp_service_time;
		int temp_weight;
		infile >> temp_process_name >> temp_arrival_time >> temp_service_time >> temp_weight;
		All_Process.push_back(Process(temp_process_name, temp_arrival_time, temp_service_time,temp_weight));
	}

	Priority_Scheduling pri(All_Process);
	pri.start();
	All_Process.clear();
	infile.close();
}

