
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &a)
    {

        int i, max1, max2;
        max1 = max2 = INT_MIN;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > max1)
            {
                max2 = max1;
                max1 = a[i];
            }
            else if (a[i] > max2)
            {
                max2 = a[i];
            }
        }
        int ans = (max1 - 1) * (max2 - 1);
        return ans;
    }
};

// Driver Code
int main()
{
    int N; //how many strings of length n can be formed under the following rules:
    int result;

    vector<int> getc()
    {
        char c;
        vector<int> cl;
        std::cin >> std::noskipws;
        while (std::cin >> c && c != '\n')
        {
            cl.push_back(c);
            std::cin >> c;
        }
        return cl;
    }

    cin >> N;

    Solution obj1;

    result = obj1.countVowelPermutation(N);

    cout << result;

    // Function Call
    //findMinimumW(arr);

    return 0;
}
