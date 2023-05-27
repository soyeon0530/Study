#include <iostream>
using namespace std;
#define MAXN (12)
int N;//대회수
int A[MAXN+10][MAXN+10];//[출발][도착]=항공료
int cost; 
int min_cost = 9999;
bool use[MAXN+10];
int num[MAXN+10];
 
void InputData(){
    cin >> N;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cin >> A[i][j];
        }
    }
}
 
void Solve(int n, int cost){
    if (n==N){
        // for (int i=0; i<=N-1; i++)
        //     cout << num[i] << " ";//출력
        //cout << " " << "\n" ;
        if (A[num[N-1]][1]==0) return;
        cost = cost + A[num[N-1]][1];
        if (min_cost > cost) min_cost = cost;
     
        return;
    }
     
    for (int i=2; i<=N; i++)
    {
        if ( A[num[n-1]][i]==0 ) continue;
        if (use[i]) continue;
        use[i] = true;
        num[n] = i;
 
        int new_cost = cost +  A[num[n-1]][i];
        //if (new_cost > min_cost) continue;
        //cout << new_cost << "\n";
        Solve(n+1, new_cost);
        use[i] = false;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();//입력
     
    use[1] = true;
    num[0] = 1;
    Solve(1, 0);
    //여기서부터 작성
 
    cout << min_cost << "\n";//출력
    return 0;
}
