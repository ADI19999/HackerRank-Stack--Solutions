#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string S;
    stack<string> s;
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            string W;
            cin>>W;
            s.push(S);
            S = S + W;
        }
        else if(t==2)
        {
            int k;
            cin>>k;
            s.push(S);
            S.erase(S.size()-k);

        }
        else if(t==3)
        {
            int f;
            cin>>f;
            cout<<S[f-1]<<endl;
        }
        else if(t==4)
        {
            S=s.top();
            s.pop();
        }
    }  
    return 0;
}
