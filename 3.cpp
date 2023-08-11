#include<bits/stdc++.h>
using namespace std;

int squareSumOfDigits(int n)
{
    int sum = 0; 
    while(n>0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    unordered_set<int> s;
    while(n!=1 && s.find(n) == s.end())
    {
        s.insert(n);
        n= squareSumOfDigits(n);
    }
    return n==1;
}

int nextHappyNumber(int n)
{
    while(true)
    {
        n++;
        if(isHappy(n))
        {
            return n;
        }
    }
}


int main()
{
    int N;
    cin>>N;
    int nextHappy = nextHappyNumber(N);
    cout<<nextHappy;
}