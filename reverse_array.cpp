#include <bits/stdc++.h>
using namespace std;
void f(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    f(arr,l + 1, r - 1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    
    f(arr, 0, 6);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
}