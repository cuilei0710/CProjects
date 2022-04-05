#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int, int);

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

bool cmp(int a, int b)
{
    return a < b;
}