#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void swap(vector<int> &a,int x ,int b){
    int temp = a[x];
    a[x]=a[b];
    a[b]=temp;
    return;
}
void permute(vector<int> &a,int idx){
    if(idx==a.size()){
        ans.push_back(a);
        return ;
    }
    for(int i=idx;i<a.size();i++){
        if(i!=idx and a[i]==a[idx] ){
            continue;
        }
        swap(a,idx,i);
        permute(a,idx+1);
        // swap(a,idx,i);
    }
}
int main(){
    vector<int>a;
    for(int i=0;i<3;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    permute(a,0);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<'\n';
    }
}