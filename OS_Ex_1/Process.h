#pragma once
#include<iostream>
#include <string>
class Process
{
public:
	Process();
	Process(std::string ProcessName, double Arrival_time, double Service_time);
	~Process();
	int getpos();
	std::string getProcess_name();
	double getArrival_time();
	double getService_time();
	double getStart_time();
	double getEnd_time();
	double getTurnaround_time();
	double getWeight_Turnaround_time();
	bool operator < (const Process &a)const {
		if (Service_time == a.Service_time)
			return Arrival_time > a.Arrival_time;
		return Service_time > a.Service_time;
	}
private:
	int pos;
	std::string Process_name;
	double Arrival_time;
	double Service_time;
	double Start_time;
	double End_time;
	double Turnaround_time;
	double Weight_Turnaround_time;
};

