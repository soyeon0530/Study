#include <iostream>
#include <algorithm>
using namespace std;
#define MAXNM ((int)1e5)
int N, M;//소마리수, 잔디구간 개수
long long A[MAXNM+10];//잔디 구간 시작
long long B[MAXNM+10];//잔디 구간 끝
long long min_val = 999999;
long long max_val = -1;
 
 
void InputData(){
    cin >> N >> M;
    for (int i=0 ; i<M ; i++){
        cin >> A[i] >> B[i];
    } 
    sort(A, A+M); sort(B, B+M);
    min_val = 1;
    max_val=B[M-1];// 잔디 간의 구간
    //cout << "min" << min_val << "max" << max_val << endl;
}
bool IsPossible(long long m){
    long long out = N;
    long long cnt=1;//처음 위치에 cow 위치 
    long long cow_pos=A[0]; // 처음 cow 위치
/*
    for (int i=0; i<M; i++){
         
        //잔디 구간 내 
        if (B[i]-cow_pos>=m){
            cnt += (B[i]-A[i])/m; 
            cow_pos = cow_pos+((B[i]-A[i])/m)*m;
        }
         
        // 다음 잔디 시작 지점
        //cout << "cow_pos" << cow_pos << "cnt" << cnt;;
        if (i<=M-1){
            if (cow_pos+m>B[M-1]) break;
            if (A[i+1]-cow_pos<=m) cow_pos += m;
            else cow_pos += (A[i+1]-cow_pos);
            cnt++;
        }
        //cout << " next cow_pos" << cow_pos << "next cnt" << cnt;;
 
        if (cnt>=out) return true; //Distance 늘려보기 (최대D)
    } //소가 더 적게
    if (cnt>=out) return true;
    if (cnt<out) return false; //N만큼 더 세워야 하니까, Distance 줄이기*/
    for (int i=0; i<M; i++){
        while(cow_pos + m <= B[i]){
            if(++cnt >= N) return true;
            cow_pos += m;
            if (cow_pos < A[i]) cow_pos = A[i];
        }
    }
    return false;
}
 
long long BinarySearch(){
    long long s = min_val; long long e = max_val;
    long long sol=0;
    while (s<=e){
        long long m = (s+e)/2;
        if (IsPossible(m)){ ///소가 서 있을 수 있음
            sol=m;
            s=m+1;
        }
        else{
            e=m-1; //// 소가 더 많이 서 있을 수 없으면, D 줄이기
        }
         
    }
    return sol;
     
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long ans =0;
    InputData();// 입력받는 부분
    ans=BinarySearch();
    // 여기서부터 작성
 
    cout << ans << "\n";// 출력하는 부분
    return 0;
}
