#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
 
int N;
int grids[500+10][500+10];
bool visit[500+10][500+10]={false,};
int min_diff = 1000100;
int max_diff = -1;
struct pos{
    int x; int y;
};
queue <pos> q;
int diff_arr[1000000+10]={0,};
int half;
vector <int> diff_stack;
 
 
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> grids[i][j];
            // min_diff = min(min_diff, grids[i][j]);
            // max_diff = max(max_diff, grids[i][j]);
             
        }
         
    }
    if(N*N%2==0) half = N*N/2; else half = N*N/2+1;
    // cout << half;
    // cout << "min diff"<< min_diff<<" " << "max diff"<< max_diff << endl;
}
 
int BFS(int cri){
    //map 에 존재하는 차이들 다 배열에 넣어주기
    int dx[] = {-1,1,0,0};
    int dy[] = {0, 0,-1,1};
     
    int cnt = 1;
     
    while(!q.empty()){
         
        pos cur =q.front();q.pop();
        for(int i=0; i<4; i++){
         
            // cout << "test" << cur.x <<" " << cur.y << endl;
             
            int n_x = cur.x+dx[i];
            int n_y = cur.y+dy[i];
            // cout << " test2" << " " << n_x << " " << n_y << endl;
             
            if (n_x<0 || n_y<0 || n_x>=N || n_y>=N) continue;
            if (visit[n_x][n_y]) continue;
             
            int diff = abs(grids[n_x][n_y]-grids[cur.x][cur.y]);
            if (diff>cri) continue;
             
            // cout << diff << " " << n_x << n_y << " " << cur.x << cur.y <<endl;
            // cout << grids[n_x][n_y] <<" "<< grids[cur.x][cur.y] << endl;
            cnt++;
            visit[n_x][n_y] = true;
            q.push({n_x, n_y});
 
         
        }
         
    }
    // cout << "cnt" << cnt << endl;
    return cnt;
}
 
bool ChckVisit(int m){
    int max_half=-1;
    int val;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            visit[i][j]=false;
        }
    }
     
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (visit[i][j]==false){
                q={};
                q.push({i,j});
                visit[i][j]=true;
 
                max_half=max(max_half, BFS(m));
                // cout << val;
                // max_half = max(BFS(D))
            }
        }
    }
    // cout << m << endl;
    // cout << "max_half" << " " << max_half << "half" << half << " ";
    if (max_half>=half) return true;
    else return false;
    // cout << val << endl;
    // return max_half;
     
}
 
int Binary_Search(){
     
    int s=0; int e=1000000;
    int sol;
     
    while (s<=e){
         
        int m=(s+e)/2;
        // cout << s <<" "<<m <<" "<< e << endl;
        if(ChckVisit(m)){
            sol=m;
            e=m-1;
             
        }
        else{
            s=m+1;
        }
    }
     
    return sol;
}
 
 
 
 
 
 
int main(){
    int ans = -1;
 
    InputData();// 입력받는 부분
    // BFS(3);
    // bool i=ChckVisit();
    // cout <<"i" << i;
    ans=Binary_Search();
 
 
     
    // 여기서부터 작성
 
    cout <<  ans << endl;// 출력하는 부분
    return 0;
}
