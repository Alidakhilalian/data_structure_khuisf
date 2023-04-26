#include <iostream>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    //Constructor | سازنده
    Node(int value)
    { 
        prev = NULL;
        data = value; 
        next = NULL;
    }
};

Node* head = NULL;
int len = 0;

void append(int value) {

    Node* new_node = new Node(value);

    if (head == NULL) {
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
        len++;
    }
    else
    {
        Node* last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = NULL;
        new_node->prev = last;
        len++;
    }
}

void push(int value) {

    Node* new_node = new Node(value);

    if (head == NULL) {
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
        len++;
    }
    else
    {
        Node* temp = head;
        new_node->next = temp;
        new_node->prev = NULL;
        temp->prev = new_node;
        head = new_node;
        len++;
    }
}

void insert(int value, int index) {

    Node* new_node = new Node(value);

    if (head == NULL) {
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
        len++;
    }
    else
    {
        if (index >= 1 && index <= len) {
            Node* temp = head;
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }
            new_node->next = temp;
            
            if (temp->prev != NULL) {
                new_node->prev = temp->prev;
                temp->prev->next = new_node;
            }
            else 
            {
                head = new_node;
                new_node->prev = NULL;
            }
                
            temp->prev = new_node;
            len++;
        }
        else
        {
            cout << "\nIndex Invalid\n";
        }
        
    }
}

void update(int index, int value) {
    Node* temp = head;
    if (temp == NULL) {
        cout << "\nLinked List Is Empty\n";
    }
    else
    {
        if (index >= 1 && index <= len) 
        {
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }
            temp->data = value;
        }
        else
        {
            cout << "\nIndex Invalid\n";
        }
        

    }
}

void remove(int index) {

    Node* temp = head;
    if (temp == NULL) {
        cout << "\nLinked List Is Empty\n";
    }
    else
    {
        if (index >= 1 && index <= len) {
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }
            if (temp->next == NULL && temp->prev == NULL)
            {
                head = NULL;
            }
            else if (temp->next == NULL) {
                temp->prev->next = NULL;
            }
            else if (temp->prev == NULL) {
                head = temp->next;
                head->prev = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            len--;
            delete(temp);
        }
        else
        {
            cout << "\nIndex Invalid\n";
        }
        
       
    }
}

void removeItem(int item) {
    Node* temp = head;
    if (temp == NULL) {
        cout << "\nLinked List Is Empty\n";
    }
    else
    {
        int number_of_item = 0;
        for (int i = 1; i < len; i++)
        {
            if (temp->data == item) {
                number_of_item++;
            }
            temp = temp->next;
        }

        int counter;
        for (int i = 0; i < number_of_item; i++)
        {

            counter = 1;
            temp = head;
            while (counter <= len)
            {
                if (temp->data == item) {
                    remove(counter);
                    break;
                }
                counter++;
                temp = temp->next;

            }

        }
    }
}

void show() {
    
    Node* temp = head;
    if (temp == NULL) {
        cout << "\nLinked List Is Empty\n";
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            cout << endl << "[" << i + 1 << "] " << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
        
}

int main() {

    int sw_input, value1, value2;
    bool menu = true;
    while (menu)
    {
        cout << "\nAdd Item First (1)\nAdd Item End (2)\nAdd Item Manual Index (3)\nDelete With Index (4)\nDelete With Value (5)\nUpdate Item Value (6)\nShow List (7)\nExit (8)\n";
        cin >> sw_input;
        switch (sw_input)
        {
        case 1:
            cout << "\nEnter Value:";
            cin >> value1;
            push(value1);
            break;
        case 2:
            cout << "\nEnter Value:";
            cin >> value1;
            append(value1);
            break;
        case 3:
            cout << "\nEnter Value:";
            cin >> value1;
            cout << "\nEnter Index:";
            cin >> value2;
            insert(value1, value2);
            break;
        case 4:
            cout << "\nEnter Index:";
            cin >> value1;
            remove(value1);
            break;
        case 5:
            cout << "\nEnter Value:";
            cin >> value1;
            removeItem(value1);
            break;
        case 6:
            cout << "\nEnter Index:";
            cin >> value1;
            cout << "\nEnter Value:";
            cin >> value2;
            update(value1, value2);
            break;
        case 7:
            show();
            break;
        case 8:
            menu = false;
            break;
        default:
            cout << "\nInput Not Correct\n";
            break;
        }
    }

    return 0;
}