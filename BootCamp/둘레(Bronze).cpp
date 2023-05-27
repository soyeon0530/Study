#include <iostream>
#include <queue>
using namespace std;
#define MAXN ((int)1e4)
#define M_size (100) //들판의 크기
 
int N; //더미의 숫자
int X[MAXN+10];
int Y[MAXN+10];
int map[M_size+10][M_size+10]={0, };
int visited[M_size+10][M_size+10]={0, }; // 주변에 건초 몇개 있는지 count
int start_x, start_y, end_x, end_y; // 탐색 조건 & BFS 조건
int min_x=9999, min_y=9999; //BFS 조건
int max_x=-99999, max_y=-9999; //BFS 조건
int cnt;
 
struct pos{
    int x, y;
};
 
 
queue <pos> q;
 
//int
 
void InputData(){
    cin >> N;
    for (int i=0 ; i<N ; i++){
        cin >> X[i] >> Y[i];
    }
}
 
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int none_cnt=0;
 
void BFS(){
     
    start_x = min_x-1; start_y = min_y-1;
    end_x = max_x+1; end_y = max_y+1; 
 
    q={};
    q.push({start_x, start_y});
    map[start_x][start_y]=2; //무조건 2 (건초가 아닌 영역)
    //cout << start_x << start_y << endl;
     
    //cout << q.size() << endl;
    while (!q.empty()){
         
        pos cur_pos = q.front(); q.pop();
 
         
        for (int i =0; i<4; i++){
            int n_x = cur_pos.x + dx[i];
            int n_y = cur_pos.y + dy[i];
            //cout << n_x << n_y << endl;
            if (n_x<start_x || n_y<start_y || n_x>end_x || n_y>end_y || map[n_x][n_y]==2) continue;
            if (map[n_x][n_y]==1) cnt+=1;
            else if(map[n_x][n_y]==0) {
                q.push({n_x, n_y});
                map[n_x][n_y] = 2;
            }
        }
    }
}
 
 
void MakeMinimap(){
 
     
    for (int i=0; i<N; i++){
        if (Y[i]<min_x) min_x = Y[i]; // 세로=행
        if (Y[i]>max_x) max_x = Y[i];
        if (X[i]<min_y) min_y = X[i]; //가로 = 열
        if (X[i]>max_y) max_y = X[i];
         
    }
     
    for (int i=0; i<N; i++)
        map[Y[i]][X[i]]=1;
 
    // cout << min_x << max_x << endl;
    // cout << min_y << max_y << endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();// 입력받는 부분
    MakeMinimap();
 
    BFS();
 
 
    cout << cnt << "\n";// 출력하는 부분
    return 0;
}
