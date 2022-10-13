#include <iostream>
using namespace std;

class Queue
{
private:
	float* queueArray;
	int queueSize;
	int front;
	int rear;
	int numItems;
public:
	Queue(int);
	void enqueue(float);
	void dequeue();
	bool isEmpty();
	bool isFull();
	void display();
};

int main()
{
	Queue q(10);

	char c = ' ';
	while (c != 'q') {
		cout << "Enter 'a' to add number to queue, 'd' to dequeue, 's' to show queue contents, 'q' to quit: " << endl;
		cin >> c;

		switch (c) {

		case 'q':
			break;

		case 'a':
			float n;
			cout << "Enter value(float) to add to queue: ";
			cin >> n;
			q.enqueue(n);
			break;

		case 's':
			q.display();
			break;

		case 'd':
			q.dequeue();
			break;

		default:
			cout << "Invalid character" << endl << endl;
		}
	}

	return 0;
}

Queue::Queue(int x) {
	queueSize = x;
	queueArray = new float[x];
	numItems = 0;
	front = -1;
	rear = -1;
}
void Queue::enqueue(float x) {
	if (isFull())
		cout << "Queue is full" << endl << endl;
	else {
		cout << "Enqueueing " << x << endl << endl;
		rear++;
		numItems++;
		queueArray[rear % queueSize] = x;

	}
}
void Queue::dequeue() {
	if (isEmpty())
		cout << "Queue is empty" << endl << endl;
	else {
		front++;
		cout << queueArray[front] << " is dequeued" << endl << endl;
		numItems--;
	}
}
bool Queue::isEmpty() {
	return numItems <= 0;
}
bool Queue::isFull() {
	return numItems >= queueSize;
}
void Queue::display() {
	cout << "Displaying queue contents from front to back: " << endl;
	for (int i = 1; i <= numItems; i++) {
		cout << queueArray[(front + i) % queueSize];
		cout << endl;
	}
	cout << endl;
}
