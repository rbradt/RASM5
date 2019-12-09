#ifndef RASM5_H_
#define RASM5_H_

#include <fstream>
#include <cstdlib>
#include <chrono>

using namespace std;

class RASM5
{
private:
	// Variable Declarations
	int count;			//	number of integers generated
	int* arr_unsorted;	//	array of unsorted integers
	int* arr_toSort;	//	array of integers to be sorted by the algorithm being tested

	void generate_file() {
		ofstream file;
		file.open("integers.txt");

		for(int i = 0; i < count; i++) {
			arr_unsorted[i] = rand();
			file << arr_unsorted[i] << "\n";
		}

		file.close();

		return;
	}

public:
	// Constructors
	RASM5(): count{200000}, arr_unsorted{new int[count]}, arr_toSort{nullptr} {generate_file();}
	RASM5(int _count): count{_count}, arr_unsorted{new int[count]}, arr_toSort{nullptr} {generate_file();}

	double time_algorithm(void (*sort)(int, int*))
	{
		// fill array with unsorted integers
		if(arr_toSort != nullptr)
			delete[] arr_toSort;

		arr_toSort = new int[count];

		for(int i = 0; i < count; i++)
			arr_toSort[i] = arr_unsorted[i];


		// sort array of unsorted integers with the algorithm passed
		auto initial = chrono::high_resolution_clock::now(); // get initial time
		(*sort)(count, arr_toSort);							 // call sort algorithm
		auto final = chrono::high_resolution_clock::now();   // get final time


		return chrono::duration_cast<chrono::milliseconds>(final - initial).count() / 1000.0;
	}

	void print_integers(string filename)
	{
		ofstream file;
		file.open(filename);

		if(arr_toSort != nullptr)
			for(int i = 0; i < count; i++)
				file << arr_toSort[i] << "\n";

		file.close();

		return;
	}

	// Destructor
	~RASM5() {
		delete[] arr_unsorted;
		delete[] arr_toSort;
	}
};


#endif /* RASM5_H_ */
