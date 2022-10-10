#include<iostream>

using namespace	std;

int getParent(int index);
int getLeftChild(int index);
int getRightChild(int index);
void swap(int& item1, int& item2);
void heapify(int A[], int index, int size);
void build_heap(int A[], int size);
void printArray(int A[], int size);
void heapInsert(int A[], int& size, int Item);

int main()
{
	int A[50] = { 4,1,3,2,16,9,10,14,8,7 };
	int size = 10;
	
	cout << "Array: " << endl;
	printArray(A, size);
	cout << endl;

	cout << "The parent of node 5 is node " << getParent(5) << endl;
	cout << "The left child of node 3 is node " << getLeftChild(3) << endl;
	cout << "The right child of node 3 is node " << getRightChild(3) << endl << endl;

	// Convert array to a heap
	cout << "Array after build heap:" << endl;
	build_heap(A, size);
	printArray(A, size);
	cout << endl;
	
	int value = 0;
	while (true) {
		cout << "Enter a number > 0 to add to heap (-99 to quit):";
		cin >> value;
		
		if (value == -99) {
			break;
		}

		cout << "Array after inserting " << value  << ":" << endl;
		heapInsert(A, size, value);
		printArray(A, size);
		cout << endl;
	}

	return 0;
}

int getParent(int index) {
	return (index - 1) / 2;
}

int getLeftChild(int index) {
	return (index * 2) + 1;
}

int getRightChild(int index) {
	return (index * 2) + 2;
}

void swap(int& item1, int& item2) {
	int temp = item1;
	item1 = item2;
	item2 = temp;
}

// Adds number to correct position in heap
void heapify(int A[], int index, int size) {
	int largest = index;
	int l = getLeftChild(index);
	int r = getRightChild(index);

	if (l < size && A[l] > A[index])
		largest = l;

	if (r < size && A[r] > A[largest])
		largest = r;

	if (largest != index) {
		swap(A[index], A[largest]);
		heapify(A, largest, size);
	}

}
void build_heap(int A[], int size) {
	for (int i = (size / 2) - 1; i >= 0; i--) {
		heapify(A, i, size);
	}
}
void printArray(int A[], int size) {
	for (int i = 0; i < size - 1; i++)
		cout << A[i] << ", ";
	cout << A[size - 1] << endl;
}

void heapInsert(int A[], int& size, int Item) {
	size++;
	int index = size - 1;
	while (index > 0 && A[getParent(index)] < Item) {
		A[index] = A[getParent(index)];
		index = getParent(index);
	}
	A[index] = Item;
}
