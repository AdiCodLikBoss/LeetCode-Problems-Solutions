#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i,n = s.length();
        for(i=0;i<n;i++){
            if(s[i]=='c'){
                if(st.empty()||st.size()==1)
                    return false;
                else{
                    char p = st.top();
                    st.pop();
                    char q = st.top();
                    st.pop();
                    if(p=='b' && q=='a')
                        continue;
                    else
                        return false;
                }
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
    
};