
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int a = INT_MAX, b = INT_MAX;
        for (auto n : nums)
        {
            if (n <= a)
            {
                a = n;
            }
            else if (n <= b)
            {
                b = n;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int N;
    bool result{false};

    cout << "enter number of element in array \n";
    cin >> N;

    vector<int> vec(N);

    for (int i = 0; i < N; i++)
        cin >> vec[i];

    for (int k = 0; k < vec.size(); k++)
        cout << vec[k] << " ";

    Solution obj1;

    result = obj1.increasingTriplet(vec);

    std::cout << std::boolalpha; // print bools as true or false

    cout << '\n'
         << result;

    return 0;
}

/* 
Complexity:
for solution class
Time: O(1)
Space: O()

to do --when input size not known of array
*/
