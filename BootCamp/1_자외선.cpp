// 자외선 합의 최소값
#include <iostream>
#include <queue>
using namespace std;
#define MAXN (100)
#define INF (1<<30)
 
struct pose{
    int x, y;
};
 
int N;//가로, 세로 크기
char map[MAXN+10][MAXN+10];//지도정보
int cost[MAXN+10][MAXN+10];
// visited?
//int cost[];
queue <pose> q;
 
void InputData(){
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> &map[i][1];
    }
}
 
int Solve(){
    for (int x=1; x<=N; x++){
        for (int y=1; y<=N; y++){
            cost[x][y] = INF;
        }
    }
     
    int delta_x[] = {1,-1,0,0};
    int delta_y[] = {0,0, -1,1};
     
    //int temp_x, temp_y;
     
    q = {};
    q.push({1,1});
    cost[1][1] = 0;
     
    while (!q.empty()){
         
        pose cur = q.front();
        q.pop();
         
        for (int i=0; i<4; i++){
            //pose n;
            int n_x = cur.x + delta_x[i];
            int n_y = cur.y + delta_y[i];
             
            if (1<=n_x && n_x<=N && 1<=n_y && n_y<=N){
                int added =cost[cur.x][cur.y] + map[n_x][n_y] -48;
 
                if (added < cost[n_x][n_y]){
                    cost[n_x][n_y] = added;
                    q.push({n_x, n_y});                                    
                }
                //cout << cost[n.x][n.y] << "\n";
            }
             
        }
         
    }
     
    return cost[N][N];
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();//입력
 
    // fill(cost[0], cost[MAXN+10], 9999);
    ans = Solve();
    //Solve();
    //여기서부터 작성
    cout << ans << "\n";//출력
    return 0;
}
