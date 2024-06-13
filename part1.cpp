#include<bits/stdc++.h>
using namespace std;
bool check_sort(int arr[],int n){
    if(n==1 || n==0){
        return 1;
    }
    return  check_sort(arr+1,n-1) && (arr[0]<arr[1]);
}
string reverse_strin(string s){
    if(s.size()==0 || s.size()==1){
        return s;
    }
    char temp = s[0];
    return reverse_strin(s.substr(1))+temp;
}
string replacePi(string s){
    if(s.size()==1|| s.size()==0){
        return s;
    }
    if(s[0]=='P' && s[1]=='i'){
        return "3.14" + replacePi(s.substr(2));
    }
    return s[0]+replacePi(s.substr(1));
}
string remove_dup(string s){
    if(s.size()==1|| s.size()==0){
        return s;
    }
    if(s[0]==s[1]){
        return remove_dup(s.substr(1));
    }
    return s[0] + remove_dup(s.substr(1));
}
string move_x(string s){
    if(s.size()==1|| s.size()==0){
        return s;
    }
    if(s[0]=='x'){
        return move_x(s.substr(1))+'x';
    }
    return s[0]+move_x(s.substr(1));
}
void print_substring(string s , string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    print_substring(s.substr(1),ans);
    print_substring(s.substr(1),ans+s[0]);
    
}
void generate_permutation(string s,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
      generate_permutation(s.substr(0,i)+s.substr(i+1),ans+s[i]);
    }
}
int count_path(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count =0;
    for(int i=1;i<=6;i++){
       count += count_path(s+i,e);
    }
    return count;
}
int coutMazePath(int n,int i,int j){
    if(n-1==i && n-1==j){
        return 1;
    }
    int ans1=0,ans2=0;
    if(i==n-1){
        ans2 = coutMazePath(n,i,j+1);
    }else if(j==n-1){ 
    ans1 = coutMazePath(n,i+1,j);
    }else{
        ans1 = coutMazePath(n,i+1,j);
        ans2 = coutMazePath(n,i,j+1);
    }
    return ans1+ans2;
}
int tillingProb(int n){
    if(n==0 || n==1){
        return n;
    }
    return tillingProb(n-1)+tillingProb(n-2);
}
int findPairs(int n){
    if(n==1 || n==0 ||n==2){
        return n;
    }
    return findPairs(n-1)+findPairs(n-2)*(n-1);
}
int knapsack(int w[],int v[],int n,int cap){
    if(n==0){
        return 0;
    }
    if(w[0]>cap){
        return knapsack(w+1,v+1,n-1,cap);
    }
    return max(knapsack(w+1,v+1,n-1,cap),knapsack(w+1,v+1,n-1,cap-w[0])+v[0]);
}
int main(){
    int n=3;
    int w[n]={100,50,10};
    int v[n]={9,2,3};
    cout<<knapsack(w,v,3,0);
    return 0;
}