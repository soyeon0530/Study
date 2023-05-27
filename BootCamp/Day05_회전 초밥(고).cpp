#include <iostream>
#include <queue>
 
using namespace std;
queue <int> q;
 
int N, D, K, C;
int A[3000000+10];
int eat[3000000+10]={0,};
 
void InputData(){
    cin >> N >> D >> K >> C;
    //초밥벨트에 놓인 접시의수, 초밥의 가짓수, 연속해서 먹는 접시의수, 쿠폰번호
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}
 
int max_val = 0;
int cnt = 0;
void Init(){
    eat[C]+=1; // 공짜로 얻는 ..
    cnt += 1;
     
    for (int i=0; i<K; i++){
        q.push(A[i]);//초기화
         
        if (eat[A[i]]==0){
            cnt +=1;
        }
        eat[A[i]] += 1;
        //cout << q.back() << endl;
    }
    if (max_val < cnt){max_val=cnt;}
}
 
void Solve(){
    Init();
    for (int i=K; i<N+K; i++){
         
        int del=q.front(); q.pop(); 
        if (eat[del]==1){cnt--;} // 중복X
        eat[del]--;
         
        //new
        int new_eat = A[i];
        q.push(new_eat); //index: 마지막게 들어옴
        if (eat[new_eat]==0){cnt++;} //새로운 것 
        eat[new_eat]++;
        if (max_val < cnt){max_val=cnt;}
         
    }   
}
 
 
 
 
 
int main(){
    int ans = -1;
 
    InputData();// 입력받는 부분
     
    for (int i=N; i<N+K; i++){
        A[i] = A[i-N];
    }
 
    Solve();
     
    // 여기서부터 작성
 
    cout << max_val << endl;// 출력하는 부분
    return 0;
}
