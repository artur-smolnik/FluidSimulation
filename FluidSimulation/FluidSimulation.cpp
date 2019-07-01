// FluidSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <iostream>
#include "FluidCube.h"
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h> 
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	int size = 2;
	FluidCube fluidCube(size, 0.2, 4, 0.0000001);
	fluidCube.FluidCubeAddDensity(rand() % size, rand() % size, rand() % size, (rand() % 2));

	fluidCube.FluidCubeAddVelocity(rand() % size, rand() % size, rand() % size, 0.2,0.2, 0.2);
	while (true)
	{
		/*fluidCube.FluidCubeAddDensity(rand() % size, rand() % size, rand() % size, (rand() % 2));

		fluidCube.FluidCubeAddVelocity(rand() % size, rand() % size, rand() % size, 0.2, 0.2, 0.2);*/

		fluidCube.FluidCubeStep();
		
		for (int i = 0; i < size * size * size; i++)
		{
			std::cout << *(fluidCube.getDensityArray() + i)<< " ";
		}
		std::cout << std::endl;
		Sleep(1);
	}
	
		

	return 0;
}

