#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], DP[n][n], prefix[n];
    memset(DP, 0x3f, sizeof(DP));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
        DP[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n; i++)
        {
            int j = i + len - 1;
            if (j > n)
                break;
            for (int k = i; k < j; k++)
            {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + (prefix[j] - prefix[i - 1]));
            }
        }
    }
    cout << DP[1][n] << endl;
    return 0;
}