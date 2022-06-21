//cpp program to print all subsequences of an array
#include<bits/stdc++.h>
using namespace std;
void print_subsequences(int ind,vector<int> &ds,vector <int> arr)
{
    int n=arr.size();
    if(ind==n)
    {
        for(auto it:ds)
        cout<<it<<" ";

        if(ds.size()==0)
        cout<<"{}";

        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    print_subsequences(ind+1,ds,arr);
    ds.pop_back();
    print_subsequences(ind+1,ds,arr);
}
int main()
{
    vector<int> arr={2,3,4};
    vector<int>ds;
    print_subsequences(0,ds,arr);
}