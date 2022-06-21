/*Given an array nums of distinct integers, 
return all the possible permutations. 
You can return the answer in any order..*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans,int freq[])
    {
        if(ds.size()==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(freq[i]==0)
            {
            ds.push_back(nums[i]);
            freq[i]=1;
            f(nums,ds,ans,freq);
            freq[i]=0;
            ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)
            freq[i]=0;
        
        f(nums,ds,ans,freq);
        
        return ans;
        
    }
};
int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> vec;
    Solution s;
    vec = s.permute(arr);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}