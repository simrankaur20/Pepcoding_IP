#include<bits/stdc++.h>
using namespace std;
int reversal(string s)
{
    stack<char> st;
    for(int i =0 ;i < s.length() ;i++)
    {
        if(s[i]=='}' && (st.empty() || st.top() == '}'))
        {
            st.push(s[i]);
        }
        else if(s[i] == '{')
            {
                /*while(!st.empty() && st.top()!='}')
                {
                    st.pop();
                }
                if(!st.empty())
                    st.pop();*/
                st.push(s[i]);
            }
            else
            {
               st.pop();
            }
    }

    int oc = 0;int cc =0 ;
    while(!st.empty())
    {
        if(st.top()=='}')
            oc++;
        else
            cc++;
        st.pop();
    }
    return ceil(oc) + ceil(cc/2);
}
int main()
{
    string s;
    cin>>s;
    cout<<reversal(s);
}
