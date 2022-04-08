#include <iostream>
#include <stack>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define DIR 4

using namespace std;

void DFS(int, int);
bool check(int, int);

char map[MAX_ROW][MAX_COL];
bool vis[MAX_ROW][MAX_COL];

int count = 0, res = 0;
int direct[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}};

struct node
{
    int x, y;
    node() : x(), y(){};
    node(int x, int y) : x(x), y(y){};
};

int main()
{
    memset(vis, false, sizeof(vis));
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (map[i][j] == '#' && !vis[i][j])
            {
                DFS(i, j);
                count++;
            }
        }
    }
    cout << count - res << endl;
    return 0;
}

void DFS(int x, int y)
{
    int flag = 0, vt = 0;
    stack<node> s;
    s.push(node(x, y));
    vis[x][y] = true;
    while (!s.empty())
    {
        node nowNode = s.top();
        s.pop();
        for (size_t i = 0; i < DIR; i++)
        {
            int xx = nowNode.x + direct[i][0];
            int yy = nowNode.y + direct[i][1];
            if (check(xx, yy) && map[xx][yy] == '#')
            {
                flag++;
                if (!vis[xx][yy])
                {
                    vis[xx][yy] = true;
                    s.push(node(xx, yy));
                }
            }
        }
        if (flag == 4)
            vt = 1;
    }
    res += vt;
}

bool check(int x, int y)
{
    return ((x >= 0 && x < MAX_ROW) && (y >= 0 && y < MAX_COL));
}