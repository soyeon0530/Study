#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>
using namespace std;
 
#define MAXN (50)
int N, M, K;//철도역수, 철도수, 추가로 연결시킬수있는 철도수
int S[MAXN + 10];
int E[MAXN + 10];
bool use[50+10]={false,};
 
vector <int> v_data[50+10];
vector <int> v_result;
queue <int> q;
bool comp (int a, int b){return a>b;}
void InputData() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> S[i] >> E[i];
        // cout << S[i] << " " << E[i] << endl;
        v_data[S[i]].push_back(E[i]);
        v_data[E[i]].push_back(S[i]);
        // cout << v_data[S[i]].size() << endl;
    }
}
int BFS(int start){
    int cnt;
    q={};
    int size = v_data[start].size();
    for (int i=0; i<size; i++){
        q.push(v_data[start][i]);
         
    }
    cnt++;
    use[start]=true;
     
     
    while (!q.empty()){
         
        int next = q.front(); q.pop();
         
        if (use[next])continue;
         
        int size = v_data[next].size(); //연결된 도시의 수 만큼
        for (int i=0; i<size; i++){
            q.push(v_data[next][i]);
        }
        use[next]=true;
        cnt++;
         
         
    }
    // cout << "city "<< cnt ;
    return cnt;
     
}
 
void Solve(){
    //도시의 수 만큼 탐색
    int cnt=0;
    for (int i=1; i<=N; i++){
        if (!use[i]){
             
            cnt = BFS(i);
            v_result.push_back(cnt);
        }
    }
 
 
}
 
 
int main() {
    int ans = 0;
    InputData();//입력받는 부분
 
    // 여기서부터 작성
    Solve();
    sort(v_result.begin(), v_result.end(), comp);
     
    for (int i=0; i<K+1; i++){
        ans+=v_result[i];
        // cout << v_result[i];
    }
     
    cout << ans << "\n";// 출력하는 부분
    return 0;
}
 
