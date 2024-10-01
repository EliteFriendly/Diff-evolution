#include "F:\Visual Studio\repos\Diff evolution\DiffEvolution.h"


IndividualDiffEvolution DiffEvolution::crossover(IndividualDiffEvolution donor)
{
	
	int ammount=0;//���������� ��� ����� ��������� ������
	int number = rand() % arrIndividuals.size();//����� ��������
	double rep;//����������� �������� ����������
	vector<double> coordinates = donor.getCoordinats();

	//������� ��������� ����
	for (int i = 0; i < (limitsDimension.size() / 2); i++) {
		rep = rand() % 1000 / 1000.0;
		if (rep < Cr) {
			coordinates[i] = arrIndividuals[number].getCoordinats()[i];
			ammount++;
		}
	}
	if (ammount == 0) {//� ������ ���� ��� �� ���� �� ���������
		int ran = rand() % (limitsDimension.size() / 2);
		coordinates[ran] = arrIndividuals[number].getCoordinats()[ran];
	}
	donor.replaceCoordinats(coordinates);
	return donor;
}

void DiffEvolution::surviveCrossover(IndividualDiffEvolution trial)
{
	for (int i = 0; i < N; i++) {
		if (arrIndividuals[i] < trial) {
			arrIndividuals[i] = trial;
			break;
		}
	}
}

void DiffEvolution::saveBest()
{
	for (int i = 0; i < N; i++) {
		if (best < arrIndividuals[i]) {
			best = arrIndividuals[i];
		}
	}
}

void DiffEvolution::startSearch(double acc, double F, double Cr, int N, int generations) {
	DiffEvolution::F = F;
	DiffEvolution::Cr = Cr;
	DiffEvolution::N = N;
	DiffEvolution::generations = generations;
	mutation.setF(F);//���������� ��� ���������� ������ �������

	arrIndividuals.resize(N);

	
	

	//std::sort(arrIndividuals.begin(), arrIndividuals.end());
	//��������� ������ ���������
	for (int i = 0; i < N; i++) {
		//IndividualDiffEvolution ind(limitsDimension, func, acc, aim);
		arrIndividuals[i] = IndividualDiffEvolution (limitsDimension, func, acc, aim);
		arrIndividuals[i].calcFitness();
	}

	
	saveBest();


	//������ ������ �������� ����� ���������
	IndividualDiffEvolution newInd;
	for (int i = 0; i < generations; i++)
	{
		clock_t start = clock();
		for (int j = 0; j < N; j++) {
			
			newInd = mutation.getDonor(arrIndividuals,best);
			//newInd = crossover(newInd);
			//newInd.calcFitness();
			//surviveCrossover(newInd);
			if (j == 10 and i == 0) {
				clock_t end = clock();
				cout << "Work time in thr = " << &thread::get_id << " time = " << double(end - start) /*/ CLOCKS_PER_SEC*/ << endl;

			}
		}

		


		saveBest();
	}
	
	


	/*for (int i = 0; i < (limitsDimension.size() / 2); i++) {
		cout << "x =" << best.getCoordinats()[i] << endl;
	}
	cout << func(best.getCoordinats());*/

}
