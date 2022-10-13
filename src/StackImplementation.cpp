#include "iostream"
using namespace std;

class Stack
{
private:
	float* stackArray;
	int stackSize;
	int top;

public:
	Stack(int);
	void push(float);
	void pop();
	bool isFull();
	bool isEmpty();
	void display();
};

int main()
{
	Stack myStack(10);


	char c = ' ';
	while (c != 'q') {
		cout << "Enter 'a' to add number to stack, 'p' to pop, 'd' to display stack, 'q' to quit: " << endl;
		cin >> c;
		
		switch (c) {
		
		case 'q':
			break;
		
		case 'a':
			float n;
			cout << "Enter value(float) to push to stack: ";
			cin >> n;
			myStack.push(n);
			break;

		case 'd':
			myStack.display();
			break;

		case 'p':
			myStack.pop();
			break;

		default:
			cout << "Invalid character" << endl << endl;;
		}
	}


	return 0;
}

Stack::Stack(int x) {
	stackArray = new float[x];
	stackSize = x;
	top = -1;
}
void Stack::push(float x) {
	if (isFull()) {
		cout << "The stack is full" << endl << endl;
	}
	else {
		top++;
		cout << "Pushing " << x << endl << endl;
		stackArray[top] = x;

	}

}
void Stack::pop() {
	if (isEmpty()) {
		cout << "The stack is empty\n";
	}
	else {
		cout << "Popping " << stackArray[top] << endl << endl;
		top--;
	}
}
bool Stack::isFull() {
	return top >= stackSize - 1;
}
bool Stack::isEmpty() {
	return top <= -1;
}
void Stack::display() {
	cout << "Displaying stack contents from top to bottom: " << endl;
	for (int i = top; i >= 0; i--)
		cout << stackArray[i] << " ";
	cout << endl << endl;
}
