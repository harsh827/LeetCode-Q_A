// C++ program for Minimum number of Water to Land conversion to make two islands connected in a Grid

#include <bits/stdc++.h>
using namespace std;

// Determine the distance between two
// coordinates
int dist(pair<int, int> &p1,
         pair<int, int> &p2)
{

    return abs(p1.first - p2.first) + abs(p2.second - p1.second) - 1;
}

// Function to implement floodfill algorithm
void floodfill(set<pair<int, int>> &hash,
               int i, int j,
               vector<vector<char>> &A)
{

    // Base Case
    if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] != 'L')
    {
        return;
    }

    // Mark the current node visited
    A[i][j] = 'V';

    // Store the coordinates of in the
    // hash set
    hash.insert(make_pair(i, j));

    // Recursively iterate for the next
    // four directions
    floodfill(hash, i - 1, j, A);
    floodfill(hash, i + 1, j, A);
    floodfill(hash, i, j - 1, A);
    floodfill(hash, i, j + 1, A);
}

// Function to find the minimum 'W' to flipped
void findMinimumW(vector<vector<char>> &A)
{

    // Base Case
    if (A.size() == 0)
        return;

    // Two sets to store the coordinates of
    // connected island
    set<pair<int, int>> hash1, hash2;

    // Traversing the given grid[][]
    for (int i = 0; i < A.size(); i++)
    {

        for (int j = 0; j < A[0].size(); j++)
        {

            // If an island is found
            if (A[i][j] == 'L')
            {

                // Floodfill Algorithm for
                // the first island
                if (hash1.empty())
                {
                    floodfill(hash1, i, j, A);
                }

                // Floodfill Algorithm for
                // the second island
                if (hash2.empty() && !hash1.count({i, j}))
                {
                    floodfill(hash2, i, j, A);
                }
            }
        }
    }

    // To store the minimum count of 'W'
    int ans = INT_MAX;

    // Traverse both pairs of hashes
    for (auto i : hash1)
    {
        for (auto j : hash2)
        {
            ans = min(ans, dist(i, j));
        }
    }

    // Print the final answer
    cout << ans << endl;
}

// Driver Code
int main()
{

    // Given grid of land and water
    vector<vector<char>> arr;
    arr = {{'W', 'L'}, {'L', 'W'}};

    // Function Call
    findMinimumW(arr);
    return 0;
}

/* 
Time Complexity: O(N^2 * log(N^2)) 
Auxiliary Space: O(N^2)

DFS is O(m * n) and BFS is also O(m * n) 
so total O(m * n) and space complexity is 
also O(m * n ) for queue and visited set

*/
