#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)
int N;//개수
int F[MAXN + 10];
long long ans = 0;
 
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> F[i];
        //cout << F[i];
    }
}
 
 
bool IsPossible(int s, int m){
    if (m==s) return true;
    if ( F[s] < F[m]*0.9 ) return false;
    else return true;
}
 
void Calans(int i, long long m){
    ans += (m-i);
}
 
long long BinarySearch(int s_idx, int e){
    //s 큰값부터 시작.
    long long sol=0;
    int s = s_idx;
    while (s<=e){
        int m = (s+e)/2;
        //cout << s << e << m << ans << endl;
        if (IsPossible(s_idx,m)){
            sol=m;
            s=m+1;
        }
        else e=m-1;// False인 경우: 큰 사이즈 *0.9 보다 작았으므로, 범위 키워주기.
  
    }
 
    return sol;
}
 
 
void Solve(){
    sort(F, F+N);
    //int s; int e=F[N-1]; // 정렬 상태: S= 가장 작은값. e: 가장 큰값
    long long sol;
    for (int i=0; i<N; i++){
        sol=BinarySearch(i, N-1);
        Calans(i, sol);
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    Solve();
 
    cout << ans << "\n";// 출력하는 부분
    return 0;
}
