#include <iostream>
using namespace std;
 
#define MAXN (20)
int N; //벽장의 개수
int sl, sr; //left, right
int M; //target 개수
int seq[MAXN+10];
int min_cnt = 9999;
// int move[] = {-1,1};
 
void InputData(){
    cin >> N;
    cin >> sl >> sr;
    cin >> M;
    for (int i=0; i<M; i++){
        cin >> seq[i]; //traget
    }
}
 
 
void DFS_door(int open, int n, int sl, int sr){
    if (M == n){
        if (min_cnt > open){
            min_cnt = open;
        }
        return;
    }
     
    DFS_door(open+abs(sl-seq[n]), n+1, seq[n], sr);
    DFS_door(open+abs(sr-seq[n]), n+1, sl, seq[n]);
     
}
 
int Solve(){
    // 1. 문을 target 갯수 : open
    // 2. 문을 연 횟수 : n
    // 3. 왼쪽, 오른쪽 문중 어떤걸 열지 : sl, sr
    int open = 0;
    int n = 0;
    DFS_door(open, n, sl, sr);
    return min_cnt;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
     
     
    // Solve(sl);
    InputData();//입력받는 부분
 
    //여기서부터 작성
    ans = Solve();
 
    cout << ans << endl;//출력하는 부분
    return 0;
}
