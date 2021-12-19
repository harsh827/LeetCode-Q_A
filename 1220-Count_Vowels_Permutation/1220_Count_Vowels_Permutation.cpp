
#include <bits/stdc++.h>
using namespace std;

class Solution
{ // 28 ms ~ beat 54.50%
public:
    static const int a = 0, e = 1, i = 2, o = 3, u = 4, s = 5, MOD = 1e9 + 7;
    const vector<vector<int>> mapping = {{e},              // a ->
                                         {a, i},           // e ->
                                         {a, e, o, u},     // i ->
                                         {i, u},           // o ->
                                         {a},              // u ->
                                         {a, e, i, u, o}}; // s ->
    int dp[20001][6] = {};
    int countVowelPermutation(int n, int last = s)
    {
        if (n == 0)
            return 1;
        if (dp[n][last])
            return dp[n][last];
        int ans = 0;
        for (int nxt : mapping[last])
        {
            ans = (ans + countVowelPermutation(n - 1, nxt)) % MOD;
        }
        return dp[n][last] = ans;
    }
};

// Driver Code
int main()
{
    int N; //how many strings of length n can be formed under the following rules:
    int result;

    cin >> N;

    Solution obj1;

    result = obj1.countVowelPermutation(N);

    cout << result;

    // Function Call
    //findMinimumW(arr);

    return 0;
}

/* 
Complexity:

Time: O(N)
Space: O(N)
*/
