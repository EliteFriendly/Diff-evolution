#pragma once
#include<iostream>
#include<vector>
using namespace std;

class IndividualDiffEvolution
{
private:
	vector<double> coordinats ;//���������� ��������
	vector <double> limitsDimension;//����������� �� ������ ���
	double acc;//�������� ������ �����
	double fitness;//�������� �����������
	double (*func)(vector<double>);
	string aim;

	void calcFitness() {
		if (aim == "max") {
			fitness = func(coordinats);
		}
		if (aim == "min") {
			fitness = 1 / (func(coordinats) + 1);
		}
	}

public:
	IndividualDiffEvolution(const IndividualDiffEvolution&);
	IndividualDiffEvolution() { fitness = -99999999; }
	IndividualDiffEvolution(vector <double> limitsDimension, double(*func)(vector<double>), double acc, string aim);
	void replaceCoordinats(vector<double> repCoord) {
		coordinats = repCoord;

		calcFitness();
	}
	double getFitness() {return fitness;}
	vector<double> getCoordinats() { return coordinats; }





	
	bool operator <(const IndividualDiffEvolution&);
	bool operator >(const IndividualDiffEvolution&);
	bool operator ==(const IndividualDiffEvolution&);
	IndividualDiffEvolution operator +(const IndividualDiffEvolution&);
	IndividualDiffEvolution operator -(const IndividualDiffEvolution&);
	//IndividualDiffEvolution operator =(const IndividualDiffEvolution&);
	IndividualDiffEvolution operator *(double);
};

