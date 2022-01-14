#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        int len = prices.size();

        if (prices.empty() == true)
            return 0;

        while (i < len - 1)
        {
            while (i < len - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < len - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};

// Driver Code
int main()
{
    int N;
    int result = 0;

    cout << "enter number of element in array \n";
    cin >> N;

    vector<int> vec(N);

    for (int i = 0; i < N; i++)
        cin >> vec[i];

    Solution obj1;

    result = obj1.maxProfit(vec);

    cout << '\n'
         << result;

    return 0;
}

/* 
Complexity:
for solution class
Time: O(N) .n=size of array
Space: O(1)


*/
