// Will Hooker CS317-02
// Program 1 - QuickSort Algorithm


#include <iostream>
#include <fstream>

using namespace std;

bool lesser_than(double a, double b, int &comparisons) { //Comparison function. Increments the number of comparisons made
	
	comparisons++;
	if (a < b) return true;
	else return false;

}

int partition(double arr[], int left, int right, int &comparisons) { //Partition function
	
	int index = left;

	for (int i = left; i < right; i++) {
		
		if (lesser_than(arr[i], arr[right], comparisons)) {
			
			swap(arr[i], arr[index]);
			index++;
		}
	}

	swap(arr[right], arr[index]); //Places the pivot element where it belongs

	return index;

}

void quickSort(double arr[], int left, int right, int &comparisons) { //Quicksort function

	if (left < right) {

		int pivot = partition(arr, left, right, comparisons); //Determines the pivot 

		quickSort(arr, left, pivot - 1, comparisons); //Recursively calls quicksort on the left half
		quickSort(arr, pivot + 1, right, comparisons); //Recursively calls quicksort on the right half
	}

	return;

}

int main() {
	
	int comparisons = 0;
	int size = 0;

	ifstream fin("input.txt");  //Creating the file input and output variables
	ofstream fout("wjh0011.txt");

	fin >> size;  //Reading in array size

	double* array = new double[size];  //Dynamically created array of type double

	for (int i = 0; i < size; i++) { //Reading in the array elements
		fin >> array[i];
	}
	
	quickSort(array, 0, size - 1, comparisons); //Calling the QuickSort algorithm

	for (int i = 0; i < size; i++) { //Outputting the sorted array elements to the output file
		fout << array[i] << endl;
	}

	fout << comparisons << " comparisons made.";

	
	delete[] array; //De-allocating the array memory and closing the text files
	fin.close();
	fout.close();
	return 0;

}

