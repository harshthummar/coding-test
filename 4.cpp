#include<bits/stdc++.h>
using namespace std;

int makePalindrome(string str)
{
    int n = str.length();
    int left = 0,right = n-1;
    int count = 0;

   while ((left<right))
   {
        if(str[left] == str[right])
        {
            ++left;
            --right;
        }
        else{
            ++count;
            --right;
        }
   }
  
   

    return count;
}


int main()
{
    string str;
    cin>>str;
    int minChars = makePalindrome(str);
    cout<<minChars;
    return 0;
}