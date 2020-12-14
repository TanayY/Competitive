//https://www.geeksforgeeks.org/count-subsets-having-product-divisible-by-k/
#include <bits/stdc++.h>
using namespace std;

string ans;
int ctr = 0;
void generate_sets(int n, vector<int> arr, int k)
{
    if (ans.size() != 0)
    {
        int a = 1;
        for (int i = 0; i < ans.size(); i++)
            a *= (int(ans[i]) - 48);
        if (a % k == 0)
            ctr++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(char(arr[i]) + 48);
        vector<int> new_arr;
        for (int j = i + 1; j < arr.size(); j++)
            new_arr.push_back(arr[j]);

        generate_sets(n - 1, new_arr, k);
        ans.pop_back();
    }
}

int main()
{
    int n, k;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cin >> k;

    generate_sets(n, arr, k);

    cout << ctr;
}