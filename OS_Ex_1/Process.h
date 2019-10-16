#pragma once
#include<iostream>
#include <string>
class Process
{
public:
	Process();

	//无优先级调度进程构造函数
	Process(std::string ProcessName, double Arrival_time, double Service_time);

	//优先级相关调度进程构造函数
	Process(std::string ProcessName, double Arrival_time, double Service_time, int Weight);

	~Process();
	int getpos();
	std::string getProcess_name();
	double getArrival_time();
	double getService_time();

	double getEnd_time();
	double getTurnaround_time();
	double getWeight_Turnaround_time();
	int getWeight();
	bool operator < (const Process &a)const {
		return Service_time <= a.Service_time&&Arrival_time < a.Arrival_time;
	}
	std::string Process_name;
	double Arrival_time;
	double Service_time;

	double End_time;
	double Turnaround_time;//周转时间
	double Weight_Turnaround_time;//带权周转时间

	int Weight;//优先级
	int pos;

	bool isfinished;
private:


};

