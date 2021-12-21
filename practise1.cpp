
#include <bits/stdc++.h>
using namespace std;

int main()
{

    char c;
    vector<int> cl;
    string line;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> c)
    {
        cl.push_back(c);
    }

    for (int i = 0; i < cl.size(); i++)
        cout << cl[i] << " ";

    return 0;
}
