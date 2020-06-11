#include <bits/stdc++.h>
#include<stack>
using namespace std;

// Complete the isBalanced function below.
bool ArePair(char opening,char closing)
{
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    return false;
}
string isBalanced(string x) {
    string c="";
    stack<char> S;
    int n = x.length();
    for(int i=0;i<n;i++)
    {
        if(x[i]=='(' || x[i]=='{' || x[i]=='[')
        {
            S.push(x[i]);
        }
        else if(x[i]==')' || x[i]=='}' || x[i]==']')
        {
            if(S.empty()==true || !ArePair(S.top(),x[i]))
            {
                return c=c+"NO";
            }
            else
            {
                S.pop();
            }
        }
    }
    if(S.empty())
    {
        return c=c+"YES";
    }
    else
    {
        return c=c+"NO";
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
