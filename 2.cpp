#include<bits/stdc++.h>
using namespace std;
#define N 9

bool isSafe(vector<vector<int>>& board,int r,int c,int num)
{
     for(int i=0;i<N;i++)
     {
        if(board[i][r] == num || board[i][c]==num || board[r + (i/3)][c + (i%3)] == num)
        {
            return false;
        }
     }
     return true;
}

bool findUnassignedLocation(vector<vector<int>>& board,int& r,int& c)
{
    for(r=0;r<N;r++)
    {
        for(c=0;c<N;c++)
        {
            if(board[r][c]==0)
            {
                return true;
            }
        }    
    }
    return false;
}


bool solveSudoku(vector<vector<int>>& board)
{
    int r,c;
    if(!findUnassignedLocation(board,r,c))
    {
        return true;
    }

    for(int num =1 ;num<=N; num++)
    {
        if(isSafe(board,r,c,num))
        {
            board[r][c]=num;
            if(solveSudoku(board))
            {
                return true;
            }

            board[r][c] = 0;
        }
    }
    return false;
}



int main()
{
    vector<vector<int>> board(N,vector<int>(N));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>board[i][j];
        }
    }

    if(solveSudoku(board))
    {
         for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    cout<<board[i][j];
                }
                cout<<endl;
            }
    }
    else{
        cout<<"No solution exists";
    }
    return 0;
}