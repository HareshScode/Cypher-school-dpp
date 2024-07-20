#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Queue(int s)
    {
        arr = new int[s];
        size = s;
        front = -1;
        rear = -1;
    }
    
    void enqueue(int n)
    {
        if (front == -1)
        {
            front++;
            rear++;
            arr[front] = n;
        }
        else
        {
            rear++;
            arr[rear] = n;
        }
    }
    
    void show_front()
    {
        cout << arr[front];
    }
    
    void show_rear()
    {
        cout << arr[rear];
    }
    
    int dequeue()
    {
        front++;
        size--;
        return arr[front - 1];
    }
    
    bool is_empty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n{};
    cin >> n;
    Queue o(n);
    for (int i = 0; i < n; i++)
    {
        int value{};
        cin >> value;
        o.enqueue(value);
    }
    
    int rev{};
    cin >> rev;
    int a[rev];
    for (int i = 0; i < rev; i++)
    {
        a[i] = o.dequeue();
    }
    for (int i = rev - 1; i >= 0; i--)
    {
        cout << a[i] << " ";
    }
    while (!o.is_empty())
    {
        cout << o.dequeue() << " ";
    }
    return 0;
}
