#include <bits/stdc++.h>
#include<stack>
using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> arr) {
    long long n = arr.size();
    stack<long long> S;
    long long top;
    long maxarea=0;
    long long area;
    int i = 0;
    while(i<n)
    {
        if(S.empty() || arr[S.top()]<=arr[i])
        {
            S.push(i++);
        }
        else
        {
            top = S.top();
            S.pop();
            
            area = arr[top]*( S.empty()? i : (i-S.top()-1) );
            
            if(maxarea<area)
            {
                maxarea=area;
            }
        }
        
    }
    
    while(!S.empty())
    {
        top = S.top();
        S.pop();
        
        area = arr[top]*( S.empty()? i : (i-S.top()-1));
            
        if(maxarea<area)
        {
            maxarea=area;
        }
    }
    
    return maxarea;



}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
