#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int dp[105][105];

int solve(int r, int c, vector<vector<char>> &m, int i, int j){
    
    if(i == r - 1 and j == c - 1 and m[i][j] != '*'){
        return 1;
    }
    if(i < 0 or j < 0 or j >= c or i >= r or m[i][j] == '*') return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    
    int right  = solve(r,c,m,i,j+1);
    int down = solve(r,c,m,i+1,j);
    
    int ans = right + down;
    
    
    return dp[i][j] = ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    while(n--){
        int r , c;
        cin >> r >> c;

        vector<vector<char> > maze(r,vector<char>(c));

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> maze[i][j];
            }
        }
       
        memset(dp,-1,sizeof dp);
        cout <<  solve(r,c,maze,0,0) << endl;
        
    }
    return 0;
}
