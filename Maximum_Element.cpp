#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<stack>

int main() 
{
    stack<int> s;    
    int n,j,k;
    cin >> n;
    while(n--)
    {
        cin >> j;
        if(j == 1)
        {
            cin >> k;
            s.push(max(k, s.size()>0?s.top():k));
        }
        else if(j == 2)
            s.pop();
        else if(j == 3)
            cout << s.top() << '\n';
    }
    return 0;
}
