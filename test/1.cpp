#include <iostream>

using namespace std;

void isLeap(int);

int months[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int year, month, day;
    int week = 6, sum = 0;
    for (year = 2000; year <= 2020; year++)
    {
        isLeap(year);
        for (month = 1; month <= 12; month++)
        {
            for (day = 1; day <= months[month]; day++)
            {
                sum++;
                if (week == 8)
                {
                    week = 1;
                }
                if (week == 1 || day == 1)
                {
                    sum++;
                }
                week++;
                if (year == 2020 && month == 10 && day == 1)
                {
                    cout << sum << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

void isLeap(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        months[2] = 29;
    else
        months[2] = 28;
}