#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool customCompare(const int a, const int b)
    {
        int x = bitset<32>(a).count();
        int y = bitset<32>(b).count();
        if (x != y)
            return x < y;
        return a < b;
    }

    vector<int> sortByBits(vector<int> arr)
    {
        sort(arr.begin(), arr.end(), customCompare);

        for (int k = 0; k < arr.size(); k++)
            cout << arr[k] << " ";

        return arr;
    }
};

// Driver Code
int main()
{
    int N;

    cout << "enter number of element in array \n";
    cin >> N;

    vector<int> vec(N);

    for (int i = 0; i < N; i++)
        cin >> vec[i];

    Solution obj1;

    obj1.sortByBits(vec);

    return 0;
}

/* 
Complexity:
for solution class
Time: O(nlogn)
Space: O(1)

to do --when input size not known of array
*/
