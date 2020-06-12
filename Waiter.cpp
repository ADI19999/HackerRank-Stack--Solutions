#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the waiter function below.
 */
vector<int> GetPrimes(int n)
{
    vector<int> primes(n);
    int i = 0;
    int k = 2;
    bool isPrime;
    while (i < n) {
        isPrime = true;
        for (int i_k = 2; i_k <= sqrt(k); i_k++) {
            if (k % i_k == 0)
                isPrime = false;
        }
        if (isPrime)
            primes[i++] = k;
        k++;
    }
    return primes;
} 
vector<int> waiter(vector<int> number, int q) {
    /*
     * Write your code here.
     */
    vector<int> primes = GetPrimes(q);
    vector<int> output;
    vector<int> A = number;
    vector<int> B;
    vector<int> A1;
    int prime;
    for(int i=0;i<q;i++)
    {
        prime = primes[i];
        A1 = {};
        if(A.size()==0)
        break;

        while(!A.empty())
        {
            if(A.back() % prime == 0)
            {
                B.push_back(A.back());
            }
            else
            {
                A1.push_back(A.back());
            }
            A.pop_back();
        }
        A=A1;

        while(!B.empty())
        {
            output.push_back(B.back());
            B.pop_back();
        }
    }

    while(!A1.empty())
    {
        output.push_back(A1.back());
        A1.pop_back();
    }
    
    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split_string(number_temp_temp);

    vector<int> number(n);

    for (int number_itr = 0; number_itr < n; number_itr++) {
        int number_item = stoi(number_temp[number_itr]);

        number[number_itr] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
