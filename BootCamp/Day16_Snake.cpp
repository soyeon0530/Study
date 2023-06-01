#include <iostream>
#include <queue>
using namespace std;
#define MAXN (100)
int N;
int K;
int R[MAXN+10];
int C[MAXN+10];
int L;
int X[MAXN+10];
char CMD[MAXN+10];
 
#define MAXT ((int)1e4)
int map[MAXN+10][MAXN+10];
int order[MAXT+10];
struct QUE{
    int r, c;
};
queue <QUE> que;
 
int Solve(){
    int dr[]={0, 1, 0, -1};//동남서북
    int dc[]={1, 0, -1, 0};
    //0.초기화
    que = {};
    //1.과일 지도에 표시
    for (int i=0; i<K; i++){
        map[R[i]][C[i]] = 1;
    }
    //2.뱀 이동경로 order 배열에 표시
    for (int i=0; i<L; i++){
        order[X[i]] = (CMD[i] == 'D') ? 1 : -1;
    }
    //3.시뮬레이션
    que.push({1, 1}); map[1][1]=2;
    int cur_r=1, cur_c=1, cur_dir=0;
    for (int t=0; ; t++){
        cur_dir = (cur_dir + 4 + order[t]) % 4;
        cur_r += dr[cur_dir];
        cur_c += dc[cur_dir];
        if ((cur_r < 1) || (cur_r > N) || (cur_c < 1) || (cur_c > N)) return t+1;//범위 벗어남, 벽에 부딪혀 죽음
        if (map[cur_r][cur_c] == 2) return t+1;//자기 몸통에 부딪혀 죽음
        if (map[cur_r][cur_c] == 0) {
            QUE tail = que.front();
            map[tail.r][tail.c] = 0;
            que.pop();//사과 없으므로 꼬리 제거
        }
        que.push({cur_r, cur_c}); map[cur_r][cur_c]=2;
    }
}
 
void InputData(){
    cin >> N;
    cin >> K;
    for (int i=0; i<K; i++){
        cin >> R[i] >> C[i];
    }
    cin >> L;
    for (int i=0; i<L; i++){
        cin >> X[i] >> CMD[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
 
    InputData();//입력받는 부분
 
    ans = Solve();//여기서부터 작성
 
    cout << ans << "\n";//출력하는 부분
    return 0;
}
