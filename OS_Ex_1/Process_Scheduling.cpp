#include "Process.h"
#include <iostream>
#include <vector>
#include <fstream>

#include"FCFS.h"
//Global
static int Process_Num = 0;
void fcfstest();
void sjftest();

int main() {

	fcfstest();
	


	system("pause");
	return 0;
}
void fcfstest() {
	std::fstream infile("inFCFS", std::ios::in);
	infile >> Process_Num;
	std::cout << Process_Num << std::endl;


	std::vector<Process> All_Process;
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

	infile.close();
}

void sjftest()
{

}


