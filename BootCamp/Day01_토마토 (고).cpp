#include <iostream>
#include <queue>
 
using namespace std;
#define MAXN ((int)1e3)
int M, N;//상자의 가로, 세로 칸 수
int map[MAXN+10][MAXN+10];//토마토 정보
int visited[MAXN+10][MAXN+10];
int day;
struct pos{
    int y;
    int x;
};
 
 
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
queue<pos> q;
//q = {};
 
// 1: 익은 토마토, 0: 익지 않은 토마토, -1: 토마토 없음
// 모든토마토 익음: 0 ; 모든 토마토 익지 못함: -1
void InputData(){
    cin >> M >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> map[i][j];
             
             
        }
    }
}
 
 
 
void Solve(){
 
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (map[i][j]==1)q.push({i, j});
        }
         
    }
    while (!q.empty())  {
        pos cur = q.front(); 
        q.pop();
 
        for (int i=0; i<4; i++){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            // 1: 익은 토마토, 0: 익지 않은 토마토, -1: 토마토 없음
 
            if (0<=nx && nx<M && 0<=ny && ny<N){
                if (map[ny][nx] == 0){
                    map[ny][nx] = map[cur.y][cur.x]+1;
                    q.push({ny, nx});
                }
            }
        }
    }
     
//     // check 
 
    }
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();//입력
     
    Solve();
 
 
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            //cout << map[i][j] << "\n";
            if (map[i][j]==0){
                cout << -1 <<"\n";
                return 0;
            }
             
            if (day < map[i][j]){
                day = map[i][j];
            }
        }
    }
 
    cout << day-1 << "\n";//출력
    return 0;
