#include <bits/stdc++.h>
using namespace std;
void search_matrix(int mat[4][5],int n,int x)
{
    if(n==0){
    return;
    }
    int smallest=mat[0][0]  , largest=mat[n-1][n-1];
    if(x<smallest || x>largest){
    return;
    }
    int i=0, j=n-1;
    while(i<n && j>=0)
    {
        if (mat[i][j]==x)
        {
            cout<<"Element found at "<<i<<","<<j;
        }
        if (mat[i][j] > x){ 
        j--;
        }
        else{
        i++;
    }
}
}
int main()
{
    int mat[4][5]= { {-4,-3,-1,3,5},{-3,-2,2,4,6},{-1,1,3,5,8},{3,4,7,8,9} };
    search_matrix(mat,4,3);
    return 0;
}
