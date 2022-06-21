//cpp program to print any subsequence with a target sum
#include <bits/stdc++.h>
using namespace std;
bool print_subsequences(int ind, int s, vector<int> &ds, int sum, vector<int> arr)
{
    int n = arr.size();
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];
    if (print_subsequences(ind + 1, s, ds, sum, arr) == true)
        return true;

    ds.pop_back();
    s -= arr[ind];
    if (print_subsequences(ind + 1, s, ds, sum, arr) == true)
        return true;

    return false;
}
int main()
{
    vector<int> arr = {3, 1,1};
    vector<int> ds;
    print_subsequences(0, 0,ds,2, arr);
}