#include<bits/stdc++.h>
using namespace std;
bool isSafe(int arr[][5],int n ,int x,int y){
    if(x<n && y<n && arr[x][y]==1){
        return 1;
    }
    return 0;
}
bool ratInMaze(int arr[][5],int n,int x,int y,int solArr[][5]){
    if(x==n-1 && y==n-1){
        solArr[x][y]=1;
        return 1;
    }
    if(isSafe(arr,n,x,y)){
        solArr[x][y]=1;
        if(ratInMaze(arr,n,x+1,y,solArr)){
            return true;
        }
        if(ratInMaze(arr,n,x,y+1,solArr)){
            return true;
        }
        solArr[x][y]=0;
        return false;
    }
    return false;
}

int main(){
    int arr[5][5]={
        {1,0,1,0,1},{1,1,1,1,1},{0,1,0,1,0},{1,0,0,1,1},{1,1,1,0,1}
    };
    int solArr[5][5]={{0},{0},{0},{0},{0}};
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         cout<<solArr[i][j]<<" ";
    //     }cout<<'\n';
    // }
    ratInMaze(arr,5,0,0,solArr);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<solArr[i][j]<<" ";
        }cout<<'\n';
    }
    return 0;
}