#include <iostream>

using namespace std;

int main()
{
    int n, ans = -1;
    cin >> n;
    int a[n], DP[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    DP[0] = 1;
    for (int i = 1; i < n; i++)
    {
        DP[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] >= a[j])
            {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        ans = max(ans, DP[i]);
    }
    cout << ans << endl;
    return 0;
}