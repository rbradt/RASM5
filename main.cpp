#include <stdio.h>
#include <iostream>
#include <string>

#include "RASM5.h"

using namespace std;

extern "C" void aInsertionSort(int, int*);
extern "C" void aBubbleSort(int, int*);
void cInsertionSort(int, int*);
void cBubbleSort(int, int*);


int main()
{
	char choice;
	int fileSize = 0;
	double times[4] = {0};
	RASM5* rasm5 = nullptr;
	const char* menuf = "                 RASM5 C++ vs Assembly\n"
						 "File Element Count: %d\n"
						 "------------------------------------------------\n"
						 "C bubbleSort Time: %f seconds\n"
						 "Assembly bubbleSort Time: %f seconds\n"
						 "C insertionSort Time: %f seconds\n"
						 "Assembly insertionSort Time: %f seconds\n"
						 "------------------------------------------------\n"
						 "<1> Load input file (integers)\n"
						 "<2> Sort using C bubbleSort algorithm\n"
						 "<3> Sort using Assembly bubbleSort algorithm\n"
						 "<4> Sort using C insertionSort algorithm\n"
						 "<5> Sort using Assembly insertionSort algorithm\n"
						 "<6> Quit\nChoice: ";

	do {
		printf(menuf, fileSize, times[0], times[1], times[2], times[3]);
		cin >> choice;
		cin.ignore(1000, '\n');

		switch(choice) {
		/* ----- Load Input File ----- */
		case '1':
			fileSize = 200000;

			if(rasm5 != nullptr)
				delete rasm5;
			rasm5 = new RASM5(fileSize);

			printf("File loaded with %d integers.\n", fileSize);
			break;


		/* ----- C++ bubble sort ----- */
		case '2':
			if(rasm5 != nullptr) {
				times[0] = rasm5->time_algorithm(&cBubbleSort);
				rasm5->print_integers("bSortC.txt");
				printf("C++ bubble sort completed in %f seconds.\n", times[0]);
			}
			else
				printf("ERROR - Input file must be loaded before any tests can be done.\n");

			break;


		/* ----- Assembly bubble sort ----- */
		case '3':
			if(rasm5 != nullptr) {
				times[1] = rasm5->time_algorithm(&aBubbleSort);
				rasm5->print_integers("bSortA.txt");
				printf("Assembly bubble sort completed in %f seconds.\n", times[1]);
			}
			else
				printf("ERROR - Input file must be loaded before any tests can be done.\n");

			break;


		/* ----- C++ insertion sort ----- */
		case '4':
			if(rasm5 != nullptr) {
				times[2] = rasm5->time_algorithm(&cInsertionSort);
				rasm5->print_integers("iSortC.txt");
				printf("C++ insertion sort completed in %f seconds.\n", times[2]);
			}
			else
				printf("ERROR - Input file must be loaded before any tests can be done.\n");

			break;


		/* ----- Assembly insertion sort ----- */
		case '5':
			if(rasm5 != nullptr) {
				times[3] = rasm5->time_algorithm(&aInsertionSort);
				rasm5->print_integers("iSortA.txt");
				printf("Assembly insertion sort completed in %f seconds.\n", times[3]);
			}
			else
				printf("ERROR - Input file must be loaded before any tests can be done.\n");


		/* ----- Exit ----- */
		case '6':
			break;

		default:
			printf("ERROR - Invalid character entered!\n");
			break;
		}

		if(choice != '6') {
			printf("Continue? ");
			cin.ignore(10, '\n');
		}
	} while(choice != '6');

	delete rasm5;

	return 0;
}

// C++ insertion sort
void cInsertionSort(int count, int* array) {
	for(int i = 1; i < count; i++) {
		int temp = array[i];
		int j = i - 1;

		for(; j >= 0; j--)
			if(temp < array[j])
				array[j+1] = array[j];
			else
				break;

		array[j+1] = temp;
	}

	return;
}

// C++ bubble sort
void cBubbleSort(int count, int* array) {
	for(int i = count - 1; i >= 2; i--)
		for(int j = 0; j < i; j++)
			if(array[j] > array[j+1]) {
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}

	return;
}

