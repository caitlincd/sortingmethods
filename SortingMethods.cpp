// This program displays several methods of sorting an array of integers and compares the time each takes

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

//use bubble sorting method and print the time it takes
float bub_sort(int a[], int size) {
	clock_t t;
	t = clock();
	bool sorted = false;

	//starting at the beginning of the list, if i is not the last item and it is not sorted yet
	for (int i = 0; i < size - 1 && !sorted; i++) {
		sorted = true; //it will now be sorted
		//starting at the end of the list, if j is after i
		for (int j = size - 1; j > i; j--) {
			//compare compare the number in the jth position with the one before it
			if (a[j] < a[j-1]) {
				//if the jth value should be before the (j-1)th value, swap them
				swap(a[j], a[j - 1]);
				sorted = false; //reset boolean
			}
		}
	}

	t = clock() - t;

	return (float)t / CLOCKS_PER_SEC;
}

float sel_sort(int a[], int size) {
	clock_t t;
	t = clock();
	int min;
	//start at beginning of list
	for (int i = 0; i < size - 1; i++) {
		min = a[i]; //minimum will start as the first value in the unsorted portion of the list
		//iterate through the remaining items on the list searching for the smallest value
		for (int j = size - 1; j > i; j--) {
			if (a[j] < min) //if a value smaller than the current min is reached
				min = a[j];
		}
		//swap the first number of the unsorted portion of the list with the min and move to the next number to compare
		swap(a[i], min);
	}

	t = clock() - t;

	return (float)t / CLOCKS_PER_SEC;
}

float ins_sort(int a[], int size) {
	clock_t t;
	t = clock();
	int temp;
	int j;
	//start with 2nd element in list as the first element represents the "sorted" list
	for (int i = 1; i < size; i++) {
		temp = a[i];
		for (j = i; j > 0 && a[j] > temp; j--)
			a[j] = a[j - 1];
		a[j] = temp;
	}
	t = clock() - t;

	return (float)t / CLOCKS_PER_SEC;
}


int main()
{
	//ARRAY OF 100 RANDOM NUMBERS
	int array_100[100];

	for (int i = 0; i < 100; i++) {
		array_100[i] = rand();
		cout << array_100[i] << " ";
	}

	cout << "To sort an array of 100 numbers, it takes:\n";
	
	int bub_100 = bub_sort(array_100, 100);
	cout << bub_100 << " seconds using bubble sort\n";
	
	for (int i = 0; i < 100; i++)
		array_100[i] = rand();
	
	int sel_100 = sel_sort(array_100, 100);
	cout << sel_100 << " seconds using selection sort\n";

	for (int i = 0; i < 100; i++)
		array_100[i] = rand();

	int ins_100 = ins_sort(array_100, 100);
	cout << ins_100 << " seconds using insertion sort\n\n";

	//ARRAY OF 1000 RANDOM NUMBERS
	int array_1000[1000];

	for (int i = 0; i < 1000; i++)
		array_1000[i] = rand();
	
	cout << "To sort an array of 1000 numbers, it takes:\n";

	int bub_1000 = bub_sort(array_1000, 1000);
	cout << bub_1000 << " seconds using bubble sort\n";

	for (int i = 0; i < 1000; i++)
		array_1000[i] = rand();
	
	int sel_1000 = sel_sort(array_1000, 1000);
	cout << sel_1000 << " seconds using selection sort\n";

	for (int i = 0; i < 1000; i++)
		array_1000[i] = rand();

	int ins_1000 = ins_sort(array_1000, 1000);
	cout << ins_1000 << " seconds using insertion sort\n\n";
	
	//ARRAY OF 20000 RANDOM NUMBERS
	int array_20000[20000];

	for (int i = 0; i < 20000; i++)
		array_20000[i] = rand();
	
	cout << "To sort an array of 20000 numbers, it takes:\n";

	int bub_20000 = bub_sort(array_20000, 20000);
	cout << bub_20000 << " seconds using bubble sort\n";
	
	for (int i = 0; i < 20000; i++)
		array_20000[i] = rand();

	int sel_20000 = sel_sort(array_20000, 20000);
	cout << sel_20000 << " seconds using selection sort\n";

	for (int i = 0; i < 20000; i++)
		array_20000[i] = rand();

	int ins_20000 = ins_sort(array_20000, 20000);
	cout << ins_20000 << " seconds using insertion sort\n\n";
	
	
	cout << "\tbubble(sec) \tselection(sec) \tinsertion(sec)\n";
	cout << "100\t" << bub_100 << "\t\t" << sel_100 << "\t\t" << ins_100 << endl;
	cout << "1000\t" << bub_1000 << "\t\t" << sel_1000 << "\t\t" << ins_1000 << endl;
	cout << "20000\t" << bub_20000 << "\t\t" << sel_20000 << "\t\t" << ins_20000 << endl;
	

	return 0;
}
