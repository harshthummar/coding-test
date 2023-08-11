#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& boards,int k,long long maxTime)
{
    int painters =1;
    long long currentTime = 0;

    for(int board : boards)
    {
        if(board>maxTime)
        {
            return false;
        }
        if(currentTime + board > maxTime)
        {
            painters++;
            currentTime = 0;

        }
        currentTime+= board;

        if(painters>k)
        {
            return false;
        }
    }
    return true;
}

long long minTimeToPaint(vector<int>& boards,int k)
{
    long long left =*max_element(boards.begin(),boards.end());
    long long right = accumulate(boards.begin(),boards.end(),0LL);
    long long res = right;

    while(left<=right)
    {
        long long mid =left + (right-left)/2;
        if(isPossible(boards,k,mid))
        {
            res=mid;
            right = mid -1;

        }
        else{
            left = mid +1;
        }
    }
    return res;
}


int main()
{
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;

    long long minTime = minTimeToPaint(arr,k);
    cout<<minTime;
}