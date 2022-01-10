#include<bits/stdc++.h>
using namespace std;
// Class for performing Merge Sort of a vector
class MergeSort{
    public:     
     void merge(vector<int> &v,int l,int r,int m){
        vector<int> vec;
        int i = l;
        int j = m+1;
        while(i<=m && j<=r){
           if(v[i]<=v[j]){
               vec.push_back(v[i]);
               i++;
           }else{
               vec.push_back(v[j]);
               j++;
           }
        }
        while(i<=m){
            vec.push_back(v[i]);
            i++;
        }
        while(j<=r){
            vec.push_back(v[j]);
            j++;
        }

        i = l;
        j = 0;
        while(i<=r){
            v[i] = vec[j];
            i++;
            j++;
        }
     }

     void M_sort(vector<int> &v,int l,int r){
          if(l<r){
              int m =  l + (r-l)/2;
              M_sort(v,l,m);
              M_sort(v,m+1,r);
              merge(v,l,r,m);         
            }
     }
};
int main(){
    MergeSort M;
    vector<int> vec;
    int p;
    int n ;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p;
        vec.push_back(p);
    }
    M.M_sort(vec,0,n-1);
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
}