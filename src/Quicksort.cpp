#include<iostream>
#include<ctime>

using namespace	std;

void quickSort(int theArray[], int first, int last);
void quickSortLast(int theArray[], int first, int last);
void sortFirstMiddleLast(int theArray[], int first, int mid, int last);
int partition(int theArray[], int first, int last);
void insertionSort(int theArray[], int first, int last);
void swap(int theArray[], int x, int y);

int comparisons = 0;

int main()
{
	int n[] = { 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 8192, 16384 };
	int arr[16384];
	clock_t finish, start;
	double overallTime;


	for (int j = 0; j < 13; j++) {
		//Create an unsorted array
		for (int i = 0; i < n[j]; i++) {
			arr[i] = (n[j] - i);

		}

		//Normal Quicksort Sort
		comparisons = 0;
		start = clock();
		quickSort(arr, 0, n[j] - 1);
		finish = clock();
		overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
		cout << "Normal Quicksort:\n";
		printf("Size: %d\t Comparisons: %d\t", n[j], comparisons);
		printf("Time: % .4f seconds\n", overallTime);

		//Create an unsorted array
		for (int i = 0; i < n[j]; i++) {
			arr[i] = (n[j] - i);
		}
		cout << endl;

		// Quicksort with last array element as pivot
		comparisons = 0;
		start = clock();
		quickSortLast(arr, 0, n[j]-1);
		finish = clock();
		overallTime = static_cast<double>(finish - start) / CLOCKS_PER_SEC;
		cout << "Quicksort last as pivot:\n";
		printf("Size: %d\t Comparisons: %d\t", n[j], comparisons);
		printf("Time: % .4f seconds\n\n", overallTime);

	}
	system("pause");
	return 0;
}

void quickSort(int theArray[], int first, int last)
{
	if (last - first + 1 < 10)
	{
		insertionSort(theArray, first, last);
	}
	else
	{
		// sort first, mid, and last
		sortFirstMiddleLast(theArray, first, (first + last) / 2, last);

		//partition step
		int pivotIndex = partition(theArray, first, last);
		// quicksort subarrays
		quickSort(theArray, first, pivotIndex - 1);
		quickSort(theArray, pivotIndex + 1, last);
	}
}


void quickSortLast(int theArray[], int first, int last)
{
	if (last - first + 1 < 10)
	{
		insertionSort(theArray, first, last);
	}
	else
	{
		//partition step
		int pivotIndex = partition(theArray, first, last);
		
		// quicksort subarrays
		quickSort(theArray, first, pivotIndex - 1);
		quickSort(theArray, pivotIndex + 1, last);
	}
}

void sortFirstMiddleLast(int theArray[], int first, int mid, int last) {
	if (theArray[first] > theArray[mid]) {
		swap(theArray, first, mid);
	}
	if (theArray[mid] > theArray[last]) {
		swap(theArray, mid, last);
	}
	if (theArray[first] > theArray[mid]) {
		swap(theArray, first, last);
	}
}

int partition(int theArray[], int low, int high)
{
	int pivot = theArray[high];    // pivot 
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		comparisons++;
		// swap elements at i and j if j bigger than pivot
		if (theArray[j] <= pivot)
		{
			comparisons++;
			// increment index of smaller value
			i++;
			swap(theArray, i, j);
		}
	}
	// move pivot to correct spot
	swap(theArray, i + 1, high);
	// return final pivot index
	return (i + 1);
}

// Insertion sort for last sort step of Quicksort algorithm
void insertionSort(int theArray[], int first, int last)
{
	for (int unsorted = first + 1; unsorted <= last; unsorted++)
	{
		comparisons++;
		int nextItem = theArray[unsorted];
		int loc = unsorted;

		//Shift sorted array
		while ((loc > 0) && (theArray[loc - 1] > nextItem))
		{
			comparisons += 2;
			theArray[loc] = theArray[loc - 1];
			loc--;
		}
		theArray[loc] = nextItem;
		loc--;
	}
}


void swap(int theArray[], int x, int y) {
	// Swaps the values in the array based on index position
	int temp = theArray[x];
	theArray[x] = theArray[y];
	theArray[y] = temp;
}
