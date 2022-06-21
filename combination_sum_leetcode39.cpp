/*Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates where the chosen numbers sum to target.
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique
if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150
combinations for the given input.*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void findcombinations(int ind, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (ind == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
                return;
            }
            else
                return;
        }

        if (candidates[ind] <= target)
        {
            ds.push_back(candidates[ind]);
            findcombinations(ind, target - candidates[ind], candidates, ds, ans);
            ds.pop_back();
        }

        findcombinations(ind + 1, target, candidates, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombinations(0, target, candidates, ds, ans);

        return ans;
    }
};

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    vector<vector<int>> vec;
    Solution s;
    vec = s.combinationSum(arr, 7);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}