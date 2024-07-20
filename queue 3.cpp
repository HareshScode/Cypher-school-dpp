#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int rear;
    int size;
    int extra;
    
    public:
    Queue(int s, int m)
    {
        size = s;
        extra = m;
        arr = new int[s + m];
        front = -1;
        rear = -1;
    }
    
    void enqueue(int value)
    {
        if (front == -1)
        {
            front++;
            rear++;
            arr[front] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
    }
    
    void show_front()
    {
        cout << arr[front] << " ";
    }
    
    void operation1()
    {
        rear++;
        arr[rear] = arr[front];
        front++;
    }
    
    void operation0()
    {
        front++;
        size--;
    }
    
    void display()
    {
        while (size != 0)
        {
            show_front();
            operation0();
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n{}, m{};
    cin >> n >> m;
    
    Queue q(n, m);
    for (int i = 0; i < n; i++)
    {
        int value{};
        cin >> value;
        q.enqueue(value);
    }
    
    for (int i = 0; i < m; i++)
    {
        int option{};
        cin >> option;
        if (option == 1)
        {
            q.operation1();
        }
        else
        {
            q.operation0();
        }
    }
    q.display();
}
