#include <iostream>
#include <algorithm>
 
using namespace std;
#define MAXN ((int)1e5)
int N;//영화수
struct DATA{
    int s, e;
};
DATA A[MAXN + 10];
int ans =0;
 
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
    }
}
bool comp(DATA a, DATA b){
    return a.e < b.e;
}
 
 
void Solve(){
    DATA cri={-1,-1}; //start & init
    //ans++;
     
    for (int i=0; i<N; i++){
        DATA cur = A[i];
         
        if (cur.e-cur.s <2) continue; // 두시간 미만의 영화는 고려할 필요 없음
        if (cri.s==-1){
            cri.s = cur.s;
            cri.e = cur.e; 
            ans++;
            continue;
        }
        if (cur.s >= cri.e){
            cri.s = cur.s;
            cri.e = cur.e;
            ans++;
        }
    }
     
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    InputData();//입력받는 부분
     
    sort(A, A+N, comp); // e 순으로 정렬
    Solve();
     
//  for (int i=0; i<N; i++){
//      cout << A[i].s << A[i].e << endl;
//  }
 
    cout << ans << "\n";//출력하는 부분
    return 0;
} 
