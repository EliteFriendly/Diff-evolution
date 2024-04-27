#include <iostream>
#include <vector>
#include <thread>
#include "DiffEvolution.h"
#include <fstream>
#include <mutex>
#include <ctime>
using namespace std;

const double PI = 3.1415926535897932;

int dimension = 2;
mutex mtx;


double funcSphere(vector<double> x) {
	double y = 0;
	for (int i = 0; i < dimension; i++) {
		y += x[i] * x[i];
	}
	return y;
}

double funcElliptic(vector<double> x) {
	double y = 0;
	for (int i = 0; i < dimension; i++) {
		y += pow(10, 6 * ((i - 1) / (dimension - 1))) * x[i] * x[i];
	}
	return y;

}
double funcRastrigin(vector<double> x) {
	double y = 0;
	for (int i = 0; i < dimension; i++) {
		y += (pow(x[i], 2) - 10 * cos(2 * PI * x[i]) + 10);
	}
	return y;
}
double funcRosenbrock(vector<double> x) {
	double y = 0;
	for (int i = 0; i < dimension-1; i++) {
		y += (100*pow(pow(x[i],2)-x[i+1],2)+pow(x[i]-1,2));
	}
	return y;
}
double funcSchwefel(vector<double> x) {
	double y = 0,y2=0;

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < i; j++)
			y2 += x[i];
		y += pow(y2,2);
	}
	return y;
}

void foo(int i) {
	cout << i << endl;
}




void main() {
	vector<double> in(2);
	ofstream out("Out.txt");
	for (double i = -2; i <= 2; i += 0.1) {
		for (double j = -2; j <= 2; j += 0.1) {
			in[0] = i;
			in[1] = j;
			out << in[0] << "\t" << in[1] << "\t" << funcSphere(in) << endl;
		}
	}
}




//void main() {
//	vector<double> limitsdimension(2 * dimension);
//	srand(time(0));
//
//	vector<string> mutations = { "rand1","rand2","best1","best2","targetToRand1" ,"targetToBest1" };
//	
//	for (int i = 0; i < dimension*2; i++) {
//		if (i % 2 == 0) {
//			limitsdimension[i] = -2;
//		}
//		else {
//			limitsdimension[i] = 2;
//		}
//
//	}
//	vector<double (*)(vector<double>)>arrfunc = { funcSphere,funcElliptic,funcRastrigin,funcRosenbrock,funcSchwefel };
//	vector <int> individuals = { 50,50,50,100 };
//	vector<int> generations = { 30,50,100,100 };
//	vector<int> arrdim = { 3,5,10,15 };
//	ofstream file("Results.txt");
//	file << "\t" << "3" << "\t" << "5" << "\t" << "10" << "\t" << "15"<<endl;
//
//	for (int mut = 0; mut < 6; mut++) {
//		file << mutations[mut] << '\t';
//		
//		for (int dim = 0; dim < 4; dim++) {
//			dimension = arrdim[dim];//Выбор количества измерений
//			cout << mutations[mut] << '\t' << dimension << endl;//Для отслеживания прогресса
//			for (int i = 0; i < dimension * 2; i++) {//Создание ограничений на каждую ось
//				if (i % 2 == 0) {
//					limitsdimension[i] = -3;
//				}
//				else {
//					limitsdimension[i] = 3;
//				}
//
//			}
//			double reliability = 0;
//			for (int fun = 0; fun < 5; fun++) {//Выбор функции из представленных
//
//				int succesfull = 0;//Количество успешных прогонов
//				for (int run = 0; run < 50; run++) {//Прогоны
//
//					DiffEvolution proba(arrfunc[fun], limitsdimension, mutations[mut], "min");
//					proba.startSearch(0.01, 0.5, 0.5, individuals[dim], generations[dim]);
//					double a = proba.getBest();
//					if (abs(a - 0.1) < 0.1) {
//						succesfull++;
//					}
//
//
//				}
//				reliability += succesfull / 50.0;
//
//
//
//			}
//			file << reliability / 6 << '\t';
//			
//
//
//
//		}
//
//
//		
//		
//		file << endl;
//	}
//
//	
//	/*for (int i = 0; i < 6; i++) {
//		thr[i].join();
//	}*/
//	cout << clock();
//	//DiffEvolution proba(func, limitsdimension, mutations[5], "min");
//	//proba.startSearch(0.0001, 0.5, 0.5, 50, 100);
//	
//	/*srand(time(0));
//	DiffEvolution proba(funcElliptic, limitsdimension, mutations[i], "min");
//	proba.startSearch(0.01, 0.5, 0.5, 100, 100);
//	cout << proba.getBest() << endl;*/
//}