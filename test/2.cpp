#include <iostream>
#include <stack>

#define MAX_ROW 1000
#define MAX_COL 1000
#define DIR 4

using namespace std;

void DFS();
bool check(int, int);

char map[MAX_ROW][MAX_COL];
bool vis{MAX_ROW}[MAX_COL];

int direct[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}};

struct node
{
    int x, y, count;
    node() : x(), y(), count(){};
    node(int x, int y, int count) : x(x), y(y), count(count){};
};

stack<node> s;

int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '#')
            {
                s.push(node(i, j, 0));
            }
        }
    }
    DFS();
    return 0;
}

void DFS()
{
    int len = s.size();
    int res = 0;
    while (!s.empty())
    {
        node nowNode = s.top();
        for (size_t i = 0; i < DIR; i++)
        {
            int xx = nowNode.x + direct[i][0];
            int yy = nowNode.y + direct[i][1];
            if (check(xx, yy) && map[xx][yy] != '#')
            {
                nowNode.count += 1;
            }
        }
        if (nowNode.count == 0)
        {
            res += 1;
        }
        s.pop();
    }
    cout << res << endl;
}

bool check(int x, int y)
{
    return ((x >= 0 && x < MAX_ROW) && (y >= 0 && y < MAX_COL));
}