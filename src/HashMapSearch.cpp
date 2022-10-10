#include<iostream>

using namespace	std;

const int  CAPACITY = 10;

void initTable(int data[]);
void printTable(int data[]);
int hash_function(int key);
void hashInsert(int data[], int key);
bool find_key(int data[], int search_key);



int main()
{
	int hashTable[CAPACITY];
	// Initial array initialzation;
	int arr[] = { 10, 22, 11, 31, 24, 88, 38, 21 };

	initTable(hashTable);

	for (int i = 0; i < 8; i++) {
		hashInsert(hashTable, arr[i]);
	}

	cout << "Hash table:\n";
	printTable(hashTable);

	int search_key = -99;
	while (true) {
		cout << "\nEnter value to search for: (negative number to quit)\n";
		cin >> search_key;
		
		if (search_key < 0) {
			break;
		}

		find_key(hashTable, search_key);
	}

	return 0;
}

// Initialize hash table with -1 being empty spot
void initTable(int data[]) {
	for (int i = 0; i < CAPACITY; i++) {
		data[i] = -1;
	}
}

void printTable(int data[]) {
	for (int i = 0; i < CAPACITY; i++) {
		cout << data[i] << ' ';
	}
	cout << endl;
}

int hash_function(int key)
{
	return (key % CAPACITY);
}

void hashInsert(int data[], int key) {
	int i = 0;
	while (true) {
		int x = (hash_function(key) + i * i) % CAPACITY;
		if (data[x] == -1) {

			data[x] = key;
			return;
		}
		i++;
	}
}

bool find_key(int data[], int search_key) {
	int i = 0;
	while (true) {
		int x = (hash_function(search_key) + i * i) % CAPACITY;

		if (data[x] == search_key) {
			cout << search_key << " is found\n";
			return true;
		}
		else if (data[x] == -1) {
			cout << search_key << " is not found\n";
			return false;
		}
		i++;
	}
}
