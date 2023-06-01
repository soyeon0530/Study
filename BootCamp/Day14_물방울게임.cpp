#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAXN (100)
int A;
int N;
int W[MAXN+10];
int min_cnt = INT_MAX;
int cnt =0;
void InputData(){
    cin >> A >> N;
    for (int i=0; i<N; i++){
        cin >> W[i];
    }
}

void DFS(int n, int user, int i, int cnt){
    // cout << "n " <<n<< " user " <<user << " i "<<i << " cnt "<<cnt <<" W[i] "<<W[i]<< endl;
    
    if (cnt>=min_cnt) return;
    if (user==1) {min_cnt = N; return;}
    if (n>=N){ min_cnt=min(min_cnt, cnt); return;}
    if (user > W[i]){ // user 크기가 더 크면 흡수
        
        user = user+W[i]; //스킬 사용X
        DFS(n+1, user, i+1, cnt);
    }
    else{ //user 크기가 더 적으면 -> 자기보다 적은 수 만큼 생성
        DFS(n, user+(user-1), i, cnt+1); // not 제거 
        DFS(n+1, user, i+1, cnt+1);  //제거 only
        
            
        }
    }
    


int main(){
    int t, T, ans = -1;
    cin >> T;
    for (t=1; t<=T; t++){
        cnt = 0;
        min_cnt = INT_MAX;
        InputData();//입력받는 부분
        sort(W, W+N);

        //여기서부터 작성
        DFS(0, A, 0, 0); 
        cout << "Case #" << t << ": " << min_cnt << endl;//출력하는 부분
    }
    return 0;
}
