#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int DP[a.length() + 5][b.length() + 5];
    memset(DP, 0, sizeof(DP));
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a.at(i - 1) == b.at(j - 1))
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << DP[a.length()][b.length()] << endl;
    return 0;
}