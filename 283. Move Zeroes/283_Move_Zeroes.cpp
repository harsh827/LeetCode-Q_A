#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Counting zeroes

    // Make all non-zero elements retain their original order.

    // Move all zeroes to the end

    void moveZeroes(vector<int> nums)
    {

        if (nums.empty() == true || nums.size() == 0)
        {
            return;
        }

        int current = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[current++] = nums[i];
            }
        }

        for (int i = current; i < nums.size(); ++i)
        {

            nums[i] = 0;
        }

        /* for (int k = 0; k < nums.size(); k++)
            cout << nums[k] << " ";   
        old fomat loop
        */

        cout << '\n';

        for (auto &nu3 : nums)
            cout << nu3 << " ";
    }
};

int main()
{
    int N;

    //int result;

    cout << "enter number of element in array \n";
    cin >> N;
    vector<int> vec(N);

    for (auto &it : vec)
        cin >> it;

    Solution obj1;

    obj1.moveZeroes(vec);

    return 0;
}

/* 
Complexity:
for solution class
Time: O(n) n= no of element in input array
Space: O(1)

to do --when input size not known of array
*/
