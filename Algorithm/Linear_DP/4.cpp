#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int a[100], DP[100];
    for (int i = 0; '\n' != cin.get(); i++)
    {
        cin >> a[i];
        n++;
    }
    DP[0] = 0;
    for (int i = 1; i < n; i++)
    {
        DP[i] = max(a[i], DP[i - 1] + a[i]);
    }
    cout << *max_element(DP, DP + n) << endl;
    return 0;
}