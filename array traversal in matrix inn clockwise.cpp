#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m{}, n{};
    cin >> m >> n;
    int arr[m][n];
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    int row{}, col{};
    while (row < m && col < n)
    {
        for (int i = col; i < n; i++)
        {
            cout << arr[row][i] << " ";
        }
        row++;
        
        for (int i = row; i < m; i++)
        {
            cout << arr[i][n - 1] << " ";
        }
        n--;
        
        if (row < m)
        {
            for (int i = n - 1; i >= col; i--)
            {
                cout << arr[m - 1][i] << " ";
            }
            m--;
        }
        
        if (col < n)
        {
           for (int i = m - 1; i >= row; i--)
           {
               cout << arr[i][col] << " ";
           }
           col++;
        }
    }
    return 0;
}
