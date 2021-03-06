
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
    int N;
    int result;

    cout << "enter number of element in array \n";
    cin >> N;

    vector<int> vec(N);

    for (int i = 0; i < N; i++)
        cin >> vec[i];

    for (int k = 0; k < vec.size(); k++)
        cout << vec[k] << " ";

    Solution obj1;

    result = obj1.maxProduct(vec);

    cout << '\n'
         << result;

    return 0;
}

/* 
Complexity:
for solution class
Time: O(n)
Space: O(1)

to do --when input size not known of array
*/
