#include<bits/stdc++.h>
using namespace std;
 
// A utility function to multiply two matrices
// a[][] and b[][].  Multiplication result is
// stored back in b[][]
void multiply(int a[3][3], int b[3][3])
{
    // Creating an auxiliary matrix to store elements
    // of the multiplication matrix
    int mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] = (mul[i][j] + (a[i][k]*b[k][j])%1000000007)%1000000007;
        }
    }
 
    // storing the multiplication result in a[][]
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j];  // Updating our matrix
}
 
// Function to compute F raise to power n-2.
int power(int F[3][3], int n)
{
    int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
 
    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    if (n==1)
        return F[0][0] + F[0][1];
 
    power(F, n/2);
 
    multiply(F, F);
 
    if (n%2 != 0)
        multiply(F, M);
 
   
    return F[0][0] + F[0][1] ;
}
 

int findNthTerm(int n)
{
 
    int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
 
    //Base cases
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;
 
    return power(F, n-2);
}
 
// Driver code
int main()
{
   int n = 50;
 
   cout << "F(5) is " << findNthTerm(n)%1000000007;
 
   return 0;
}