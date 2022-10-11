#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t;
    cin>>t;
    while(t--)
    {
        int d;
        cin >> d;
        int sum = 0;
        int jump = 1;
        int count = 0;
        while(sum < d)
        {
            sum += jump;
            jump++;
            count++;
        }
        int j = count + 1;
        if( (sum-1) == d )
            cout << j << endl;
        else 
            cout << count << endl;

    }
}