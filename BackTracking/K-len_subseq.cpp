//https://www.geeksforgeeks.org/print-all-possible-k-length-subsequences-of-first-n-natural-numbers-with-sum-n/
#include <bits/stdc++.h>
using namespace std;
string ans;
vector<string> nums;
int z, y;
void get_list(int n, int k)
{
    if (ans.length() == k)
    {
        if (n == 0)
        {
            nums.push_back(ans);
        }
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (n - i >= 0)
            {
                ans += (char(i) + 48);
                get_list(n - i, k);
            }
            ans.pop_back();
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    ans = "";
    z = k;
    y = n;
    get_list(n, k);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
}