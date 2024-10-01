#pragma once
#include<iostream>
#include<vector>
#include <functional>
using namespace std;

class IndividualDiffEvolution
{
private:
	vector<double> coordinats ;//���������� ��������
	vector <double> limitsDimension;//����������� �� ������ ���
	double acc;//�������� ������ �����
	double fitness;//�������� �����������
	function<double(vector<double>)> func;
	string aim;

	

public:
	IndividualDiffEvolution(const IndividualDiffEvolution&);
	IndividualDiffEvolution() { fitness = -99999999; }
	IndividualDiffEvolution(vector <double> limitsDimension, function<double(vector<double>)> func, double acc, string aim);
	void replaceCoordinats(vector<double> repCoord) {
		coordinats = repCoord;
	}
	double getFitness() {return fitness;}
	vector<double> getCoordinats() { return coordinats; }


	void calcFitness() {
		
		if (aim == "max") {
			fitness = func(coordinats);
		}
		if (aim == "min") {
			fitness = 1 / (func(coordinats) + 1);
		}
	}


	
	bool operator <(const IndividualDiffEvolution&);
	bool operator >(const IndividualDiffEvolution&);
	bool operator ==(const IndividualDiffEvolution&);
	IndividualDiffEvolution operator +(const IndividualDiffEvolution&);
	IndividualDiffEvolution operator -(const IndividualDiffEvolution&);
	//IndividualDiffEvolution operator =(const IndividualDiffEvolution&);
	IndividualDiffEvolution operator *(double);
};

