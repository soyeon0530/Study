#include <iostream>
#include <queue>
using namespace std;
#define MAXN (50)
int R, C;//지도 세로, 가로 크기
char map[MAXN+10][MAXN+10];
bool visit[MAXN+10][MAXN+10]={false,};
int flood_map[MAXN+10][MAXN+10]={0,};
//'.','*', 'X','D','S'
//홍수지역 : 뻗어나감. 바위 or 비버x (우선순위 : 화가> 홍수)
//이동 불가: 바위지역'X', 홍수지역'*
struct pos{
    int x; int y; int t;
};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
queue <pos> q;
queue <pos> flood_q; //홍수
 
void Flood(){
        //1초마다 한번씩.
 
    while (!flood_q.empty()){
    //홍수지역
        pos flood_cur = flood_q.front(); flood_q.pop();
         
        for (int i=0; i<4; i++){
            int n_x  = flood_cur.x+dx[i];
            int n_y  = flood_cur.y+dy[i];
             
            if (n_x<0 || n_x >=R || n_y <0 || n_y >=C)continue;
            if (map[n_x][n_y]=='X' || map[n_x][n_y]=='D' || map[n_x][n_y]=='*') continue; // 바위지역, 화가의 위치, 비버의 굴에는 확산 불가
            if (flood_map[n_x][n_y]!=0) continue;
             
            flood_map[n_x][n_y]=flood_cur.t+1;
            flood_q.push({n_x, n_y, flood_cur.t+1}); // t: 디버깅용
        }
    }
     
    // for (int i=0; i<R; i++){
    //     for (int j=0;j<C; j++){
    //         cout << flood_map[i][j];
    //     }
    //     cout << "\n";
    // }
}
 
int BFS(pos start, pos end){
 
     
    q={};
    q.push({start.x, start.y, 1});
    visit[start.x][start.y]=true;
    int ans=-1;
 
    while(!q.empty()){
        pos cur = q.front();q.pop();
        for (int i=0; i<4; i++){
            int n_x = cur.x + dx[i];
            int n_y = cur.y + dy[i];
             
            if (map[n_x][n_y]=='D'){ //도착지 D
                return cur.t;
            }
            if (n_x<0 || n_x >=R || n_y <0 || n_y >=C) continue;
            if (map[n_x][n_y]=='X' || map[n_x][n_y]=='*')continue;
            if (visit[n_x][n_y]) continue;
            if (flood_map[n_x][n_y]<=cur.t+1 && flood_map[n_x][n_y]!=0) continue;
            q.push({n_x, n_y, cur.t+1});
            visit[n_x][n_y]=true;
        }
         
    }
    return ans;
 
}
 
int Solve(){
    pos start; pos end; 
    flood_q={};
    int ans;
    int stop_1 = false; int stop_2 = false;
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            if (map[i][j]=='S' && stop_1==false){
                start.x = i; start.y = j;
                stop_1 = true;}
            if (map[i][j]=='D' && stop_2==false){
                end.x = i; end.y = j;
                stop_2 = true;}
            if (map[i][j]=='*'){
                flood_q.push({i,j, 1});
                flood_map[i][j]=1;
                 
            }
 
            }
        }
    //cout << flood_q.size();
    Flood();
    ans = BFS(start, end);
    return ans;
}
 
 
void InputData(){ 
    cin >> R >> C;
    for (int i=0; i<R; i++){
        cin >> map[i];
    }
}
 
 
 
int main(){
    int T, ans = -1;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        InputData();//입력 받는 부분
         
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                visit[i][j]=0;
                flood_map[i][j]=0;
            }
        }
         
        ans = Solve();
 
        if (ans ==-1) cout << "KAKTUS" << endl;//출력 하는 부분
        else cout << ans << endl;
    }
    return 0;
}
