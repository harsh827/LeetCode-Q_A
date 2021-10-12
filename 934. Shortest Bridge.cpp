class Solution 
{
public:
    int dx[4] = {-1, 1, 0, 0}; //dx[] and dy[] are used to move into 4 directions
    int dy[4] = {0, 0, -1, 1};
    queue <pair <int, int>> positions; //here we will store the positions of the 1st islands
    vector <vector <bool>> visited; // mark visited positions
    
    bool isSafe(vector <vector <int>>& A, int row, int col) //check if the position is valid or not
    {
        return ((row>=0) && (row<A.size()) && (col>=0) && (col<A[0].size()) && (!visited[row][col]));
    }
    
    void DFS(vector <vector <int>>& A, int row, int col) //DFS to store 1st island's positions in a queue
    {
        visited[row][col] = true;
        positions.push({row, col});
        for(int i=0; i<4; i++)
        {
            int x = row+dx[i];
            int y = col+dy[i];    
            if(isSafe(A, x, y) && (A[x][y] == 1))
                DFS(A, x, y);
        }
    }
    
    
    int shortestBridge(vector<vector<int>>& A) 
    {
        int row = A.size();
        int col = A[0].size();
        visited.assign(row, vector <bool>(col, false));
        bool found = false;
        for(int i=0; i<row; i++)
        {
            if(found)
                break;
            for(int j=0; j<col; j++)
            {
                if(A[i][j] == 1)
                {
                    DFS(A, i, j);
                    found = true;
                    break;
                }
            }
        }
        int bridge = 0;
        while(!positions.empty()) // BFS to expand until it touches the other island
        {
            int size = positions.size();
            for(int i=0; i<size; i++)
            {
                auto temp = positions.front();
                positions.pop();
                for(int k=0; k<4; k++)
                {
                    int x = temp.first+dx[k];
                    int y = temp.second+dy[k];
                    if(isSafe(A, x, y))
                    {
                        if(A[x][y] == 1)
                            return bridge;
                        visited[x][y] = true;
                        positions.push({x, y});
                    }
                }
            }
            bridge++;
        }
        return -1;
    }
};
