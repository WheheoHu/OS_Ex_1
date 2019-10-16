#pragma once
#include<iostream>
#include <string>
class Process
{
public:
	Process();

	//�����ȼ����Ƚ��̹��캯��
	Process(std::string ProcessName, double Arrival_time, double Service_time);

	//���ȼ���ص��Ƚ��̹��캯��
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
	double Turnaround_time;//��תʱ��
	double Weight_Turnaround_time;//��Ȩ��תʱ��

	int Weight;//���ȼ�
	int pos;

	bool isfinished;
private:


};

