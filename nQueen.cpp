#include<bits/stdc++.h>
using namespace std;
bool isSafe(int arr[][4],int row,int col){
    for(int i=row;i>=0;i--){
        if(arr[i][col]){
            return false;
        }
    }
    int i=row,j=col;
    while (i>=0 && j>=0)
    {
        if(arr[i][j]){
            return 0;
        }
        i--;
        j--;
    }
    i=row,j=col;
    while (i>=0 && j<4)
    {
        if(arr[i][j]){
            return 0;
        }
        i--;
        j++;
    }
    return true;
}
bool nQueen(int arr[][4],int idx){
    if(idx>=4){
        return 1;
    }
    for(int i=0;i<4;i++){
        if(isSafe(arr,idx,i)){
            arr[idx][i]=1;
            if(nQueen(arr,idx+1)){
                return true;
            }
            arr[idx][i]=0;
        }
    }
    return false;
}
int main(){
    int arr[4][4]={{0},{0},{0},{0}};
    nQueen(arr,0);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<'\n';
    }
    return 0;
}