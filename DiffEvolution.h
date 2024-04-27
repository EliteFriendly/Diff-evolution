#pragma once
#include "IndividualDiffEvolution.h"
#include <vector>
#include<iostream>
#include <algorithm>
#include<thread>
#include "DiffMutation.h"
#include<ctime>

using namespace std;

class DiffEvolution
{
private:
	double (*func)(vector<double>);
	vector <double> limitsDimension;//����������� ������ ���
	double F;//�������������� ������
	double Cr;//����������� �����������
	int N;//���������� ���������
	int generations;//���������� ���������
	vector<IndividualDiffEvolution> arrIndividuals;//������ ���������� ������� �������
	IndividualDiffEvolution best;//������ ��������� �������
	DiffMutation mutation;
	string aim;//���� ������

	IndividualDiffEvolution crossover(IndividualDiffEvolution);
	void surviveCrossover(IndividualDiffEvolution);
	void saveBest();
public:
	DiffEvolution(double(*func)(vector<double>), vector<double> limitsDimension, string typeMut, string aim) :func(func),
		limitsDimension(limitsDimension), aim(aim)
	{
		mutation.setType(typeMut);
		mutation.setLimits(limitsDimension);
	}
	void startSearch(double acc,double F, double Cr, int N,int generation);

	double getBest() {
		return func(best.getCoordinats());
	}


};

