#include <iostream>
using namespace std;

//there's a problem in this code:
// - if we want to enqueue element there's a case when we can't so:
// 0 means empty, dequeued element
// F - front
// R - rear
// 0 0 1 2 3
//     ^   ^
//     F   R
// In this situation the queue is "full" but in fact it isn't. So i suggest that in enqueue method we should compare
// count with size and if count < size we should move elements to the right(but maybe it's not efficient)

class Queue
{
public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (rear == -1 && front == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if (rear == 4) //arr(size) - 1
            return true;
        return false; 
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
    }


    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty " << endl;
            return 0;
        }
        else if (front == rear)
        {
            int temp = arr[front];
            //arr[front] = 0 i think that this is unnecessary   
            front = rear = -1;
            return temp;
        }
        else
        {
            int temp = arr[front];
            //arr[front] = 0;
            front++;
            return temp;
        }
    }

     
    int count()
    {
        if (isEmpty())
            return 0;
        return rear - front + 1;
    }

    void display()
    {
        cout << "Values in the Queue are:\n";
        for (int i = front; i <= rear; i++)
        {
            if (i == -1)
                cout << "Queue is Empty\n";
            else
                cout << arr[i] << endl;
        }
    }

    //i don't use approach which Simple Snippets gave because in my realization you will write all elements(including the mess that i've not cleaned)
    void displayAll()
    {
        cout << "All values in the Queue are:\n";
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << endl;
        }
    }


private:
    int arr[5]{};
    int front;
    int rear;

};


int main()
{
    Queue queue;


    int option, value;

    do
    {
        cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to exit.\n"
            << "1. Enqueue(value)\n"
            << "2. Dequeue\n"
            << "3. isEmpty()\n"
            << "4. isFull()\n"
            << "5. count()\n"
            << "6. display()\n"
            << "7. Clear screen\n\n";

        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enqueue operation\nEnter item to Enqueue in the Queue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            cout << "Dequeue Operation\nDequeued Value: " << queue.dequeue() << endl;
            break;
        case 3:
            if (queue.isEmpty())
                cout << "Queue is Empty\n";
            else
                cout << "Queue is NOT Empty\n";
            break;
        case 4:
            if (queue.isFull())
                cout << "Queue is Full\n";
            else
                cout << "Queue is NOT Full\n";
            break;
        case 5:
            cout << "Count Operation\nCount of items in Queue: " << queue.count() << endl;
            break;
        case 6:
            cout << "Display Function Called - " << endl;
            queue.display();
            cout << endl;
            queue.displayAll();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter proper option number" << endl;
            break;
        }

    } while (option != 0);
}


