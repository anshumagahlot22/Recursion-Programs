/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that
no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. 
You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space, respectively.*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe1(int row,int col,vector<string> board, int n)
    {
        int duprow=row;
        int dupcol=col;
        
        //upperdiagonal check
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        row=duprow;
        col=dupcol;
        
        //left side check
        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }
        
        row=duprow;
        col=dupcol;
        
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        
        return true;
    }
    void solve(int col,vector<string>& board,vector<vector<string>>& ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe1(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        
        solve(0,board,ans,n);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<string>> vec;
    vec=s.solveNQueens(4);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
    
}