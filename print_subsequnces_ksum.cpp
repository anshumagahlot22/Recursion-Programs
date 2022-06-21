//cpp program to print all subsequences with a given target sum
#include<bits/stdc++.h>
using namespace std;
void print_subsequences(int ind,int s,int sum,vector<int> &ds,vector <int> arr)
{
    int n=arr.size();
    if(ind==n)
    {
        if(s==sum)
        {
        for(auto it:ds)
        cout<<it<<" ";
        cout<<endl;
        }
        return ;
    }
    s+=arr[ind];
    ds.push_back(arr[ind]);
    print_subsequences(ind+1,s,sum,ds,arr);

    ds.pop_back();
    s-=arr[ind];
    print_subsequences(ind+1,s,sum,ds,arr);
}
int main()
{
    vector<int> arr={10,1,2,7,6,1,5};
    vector<int>ds;

    print_subsequences(0,0,8,ds,arr);
}