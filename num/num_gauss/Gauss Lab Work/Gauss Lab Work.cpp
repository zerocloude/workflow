#include <iostream>
#include <iomanip>
#include "Vector2D.h"
#include "Gauss.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const float epsValue = 0.001; 
	  
	cMatrix linSysA = {
		{8.2, -3.2, 14.2, 14.8},
		{5.6, -12, 15, -6.4,},
		{5.7, 3.6, -12.4, -2.3},
		{6.8, 13.2, -6.3, -8.7}};
	cVector linSysB = { -8.4, 4.5, 3.3, 14.3 };
	/*cMatrix linSysA = {
		{1.1, 11.2, 11.1, -13.1},
		{-3.3, 1.1, 30.1, -20.1},
		{7.5, 1.3, 1.1, 10.0},
		{1.7, 7.5, -1.8, 2.1}};
	cVector linSysB = { 1.3, 1.1, 20.0, 1.1 };*/
	/*cMatrix linSysA = { 
		{4.3, -12.1, 23.2, -14.1},
		{2.4, -4.4, 3.5, 5.5},
		{5.4, 8.3, -7.4, -12.7},
		{6.3, -7.6, 1.34, 3.7}};
	cVector linSysB = { 15.5, 2.5, 8.6, 12.1 };*/

	size_t cSize = linSysA.size();
	
	
	cVector linSysResult = mathGauss(linSysA, linSysB);
	cVector linSysResidual = mathResidual(linSysA, linSysB, linSysResult);
	

	while (compareResidualValues(linSysResidual, epsValue) != 1) {
		cout << "Please wait!" << endl;
		cVector linSysTest = mathGauss(linSysA, linSysResidual);
		
		for (size_t i = 0; i < linSysTest.size(); i++) {
			linSysResult[i] = linSysResult[i] + linSysTest[i];
		}
		linSysResidual = mathResidual(linSysA, linSysB, linSysResult);
	}


	cout << "\n" << "Система уравнений:" << endl;
	printLinSys(linSysA, linSysB);

	cout << "\n" << "Результат:" << endl;
	printArray(linSysResult);

	cout << "\n" << "Вектор невязки:" << endl;
	for (auto item : linSysResidual) {
		cout << fixed << setprecision(8);
		cout << " "<< item << endl;
	}

}


