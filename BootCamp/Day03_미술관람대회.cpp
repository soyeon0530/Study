#include <iostream>
#include <queue> 
 
using namespace std;
#define MAXN (100)
int N;//그림크기(정사각형)
char map[MAXN+10][MAXN+10];
int sol1, sol2; // sol1: 일반 꿀꿀이 sol2: 적록색맹 꿀꿀이
 
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int visited[MAXN+10][MAXN+10]={0,};
 
struct pos{
    int x, y;
};
queue <pos> q; 
 
void InputData(){
    cin >> N;
    for (int h=1; h<=N; h++){
        cin >> &map[h][1]; }
}
 
void MakeRgmap(){
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (map[i][j]=='G') map[i][j] = 'R'; // R로 통일
            visited[i][j] = 0; //visited reset
        }
    }
}
 
 
void BFS(int i, int j, char condition){
    q={};
    q.push({i,j});
    visited[i][j]=1;
 
    while(!q.empty()){
        pos cur = q.front(); q.pop();
         
        for (int i=0; i<4; i++){
            int n_x = cur.x + dx[i];
            int n_y = cur.y + dy[i];
             
            if (n_x<=0 || n_y<=0 || n_x>N || n_y>N || visited[n_x][n_y]==1 || map[n_x][n_y]!=condition) continue;
            q.push({n_x,n_y});
            visited[n_x][n_y] = 1;
 
        }
         
    }
}
 
 
int Run(int cnt){
    cnt=0;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (visited[i][j]==0){
                BFS(i, j, map[i][j]);
                cnt+=1;
            }
        }
         
    }
    return cnt;
}
void Solve(){
 
    sol1 = Run(sol1); //so11
    MakeRgmap();
    sol2 = Run(sol2);
     
     
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();// 입력받는 부
    //MakeRgmap(); // 적녹색맹용 map 생성
    // 여기서부터 작성
    Solve();
     
     
    cout << sol1 << " " <<  sol2 << "\n";// 출력하는 부분
    return 0;
}
