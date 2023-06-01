#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN ((int)1e3)
using namespace std;
 
int A, B, C, D;
 
bool visited[MAXN + 1][MAXN + 1];
struct QUE {
    int a, b, t;
};
queue <QUE> que;
int BFS() {
    que = {};
    memset(visited, 0, sizeof(visited));
    que.push({ 0, 0, 0 });
    visited[0][0] = true;
    while (!que.empty()) {
        QUE cur = que.front(); que.pop();
        if (cur.a == C && cur.b == D) return cur.t;
        //A Full
        if (!visited[A][cur.b]) {
            visited[A][cur.b] = true;
            que.push({ A, cur.b, cur.t + 1 });
        }
        //B Full
        if (!visited[cur.a][B]) {
            visited[cur.a][B] = true;
            que.push({ cur.a, B, cur.t + 1 });
        }
        //A Empty
        if (!visited[0][cur.b]) {
            visited[0][cur.b] = true;
            que.push({ 0, cur.b, cur.t + 1 });
        }
        //B Empty
        if (!visited[cur.a][0]) {
            visited[cur.a][0] = true;
            que.push({ cur.a, 0, cur.t + 1 });
        }
        //Move a=>b
        int move = B - cur.b;
        if (move > cur.a) move = cur.a;
        if (!visited[cur.a - move][cur.b + move]) {
            visited[cur.a - move][cur.b + move] = true;
            que.push({ cur.a - move, cur.b + move, cur.t + 1 });
        }
        //Move b=>a
        move = A - cur.a;
        if (move > cur.b) move = cur.b;
        if (!visited[cur.a + move][cur.b - move]) {
            visited[cur.a + move][cur.b - move] = true;
            que.push({ cur.a + move, cur.b - move, cur.t + 1 });
        }
    }
    return -1;
}
 
void InputData() {
    cin >> A >> B >> C >> D;
}
int main() {
    int ans = -2;
    InputData();//입력받는 부분
 
    ans = BFS();// 여기서부터 작성
 
    cout << ans << "\n";// 출력하는 부분
    return 0;
}
