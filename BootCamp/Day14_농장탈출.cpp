#include <iostream>
using namespace std;
#define MAXN (20)
int N;//소마리수
int W[MAXN+10];//소무게
int sol;//보트에 최대로 태운 마리수
int isPossible(int a, int b){
    cout << "input" << " a " << a << " b " <<b <<endl;
    cout << "a&&b " << (a && b) << endl;
    while(a && b){
        
        cout << "/%0 a " << a%10 << " b%10 " << b%10 <<endl;
        cout << "/10 a " << a/10 << " b " << b/10 <<endl;
        if (a%10 + b%10 >= 10) return 0;//자리올림 발생, 태우기 불가능
        a/=10;
        b/=10;
        
    }
    return 1;//자리올림 발생 안함, 태우기 가능
}
void DFSmulti(int s, int cnt, int sum){
    if (sol >= cnt + N - s) return;//가지치기, 이전답>=현재까지 태운소+남은모든소
    if (sol < cnt) sol = cnt;//답 갱신
    for (int i=s; i<N; i++){
        if (!isPossible(sum, W[i])) continue;//i번소는 자리올림 발생, skip
        DFSmulti(i+1, cnt+1, sum+W[i]);
    }
}
void DFSbinary(int n, int cnt, int sum){
    if (sol >= cnt + N - n) return;//가지치기, 이전답>=현재까지 태운소+남은모든소
    if (sol < cnt) sol = cnt;//답 갱신
    if (n >= N) return;//종료조건
    if (isPossible(sum, W[n])) DFSbinary(n+1, cnt+1, sum+W[n]);//태우는 경우(조건있음, 자리올림 발생 안해야 함)
    DFSbinary(n+1, cnt, sum);//안 태우는 경우
}
int Solve(){
    sol=0;//최댓값을 찾으므로 최솟값으로 초기화
    //DFSbinary(0, 0, 0);//소인덱스, 태운마리수, 무게합
    DFSmulti(0, 0, 0);//시작인덱스, 태운마리수, 무게합
    return sol;
}
void InputData(){
    cin >> N;
    for (int i=0 ; i<N ; i++){
        cin >> W[i];
    }
}
int main(){
    InputData();
    int ans = Solve();
    cout << ans << endl;//출력하는 부분
    return 0;
}
