#include <iostream>

using namespace std;

int* stack;
int stack_size;
int counter = -1;

int push(int value) {
	if (counter == (stack_size - 1)) {
		return 0;
	}
	counter++;
	stack[counter] = value;
	return 1;
}

int pop() {
	if (counter == -1) {
		return 0;
	}
	stack[counter] = NULL;
	counter--;
	return 1; //You can return counter value, but you need to change "if (result == 0)" to "if (result == -1)"
}

void show() {
	if (counter != -1) {
		for (int i = counter; i >= 0; i--)
		{
			cout << "\nStack [" << i << "] : " << stack[i];
		}
	}
	else {
		cout << "Stack is empty";
	}
	
}


int main() {

	cout << "Enter Stack Size: ";
	cin >> stack_size;
	stack = new int[stack_size];

	int command;
	int value;
	int result;
	while (true)
	{
		cout << "\n\nFor Push Enter 1 \nFor Pop Enter 2 \nFor Show Enter 3 \nFor Exit Enter 4 \n";
		cin >> command;
		switch (command)
		{
		case 1:
			cout << "Enter Value:";
			cin >> value;
			result = push(value);
			if (result == 0) {
				cout << "Stack is full";
			}
			else
			{
				cout << "Push successful";
			}
			break;
		case 2:
			result = pop();
			if (result == 0) {
				cout << "Stack is empty";
			}
			else
			{
				cout << "Pop successful";
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

