#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n], dp[n][n];
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = a[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}