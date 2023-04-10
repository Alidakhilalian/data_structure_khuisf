
//Circle Queue

#include <iostream>

using namespace std;

int* queue;
int queue_size;
int front = 1;
int rear = 1;

int enqueue(int value) {
	if (front == (rear - 1)) {
		return 0;
	}
	front++;
	front = front % queue_size;
	queue[front] = value;
	return 1;
}

int dequeue() {
	if (rear == front) {
		return 0;
	}
	rear++;
	rear = rear % queue_size;
	queue[rear] = NULL;
	return 1;
}

void show() {

	for (int i = 0; i < queue_size; i++)
	{
		cout << "\nqueue [" << i << "] : " << queue[i];
	}
	
	
}


int main() {

	cout << "Enter queue Size: ";
	cin >> queue_size;
	queue = new int[queue_size];

	int command;
	int value;
	int result;
	while (true)
	{
		cout << "\n\nFor Enqueue Enter 1 \nFor Dequeue Enter 2 \nFor Show Enter 3 \nFor Exit Enter 4 \n";
		cin >> command;
		switch (command)
		{
		case 1:
			cout << "Enter Value:";
			cin >> value;
			result = enqueue(value);
			if (result == 0) {
				cout << "queue is full";
			}
			else
			{
				cout << "Enqueue successful";
			}
			break;
		case 2:
			result = dequeue();
			if (result == 0) {
				cout << "queue is empty";
			}
			else
			{
				cout << "Dequeue successful";
			}
			break;
		case 3:
			show();
			break;
		case 4:
			return 0;
			break;
		default:
			cout << "Input not correct";
			break;
		}
	}
}

