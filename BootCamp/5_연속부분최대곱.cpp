#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
 
int N;
 
double D[10000+10];
 
double v[10000+10]={0.,};
double ans = -1;
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> D[i];
         
    }
}
 
void Solve(){
    double result[N+10];
    ans = 0.;
        
    for (int i=0; i<N-1; i++){ // i: start
         
        v[i]= D[i]; // 초깃값
        if (v[i]>ans) {
            ans = v[i];}
        for (int j=i+1; j<N; j++){
            v[j] = v[j-1]*D[j];
 
            if (v[j]>ans) {
                ans = v[j];
            }
        }
         
    }
    // for (int i=0; i<N-1; i++)
    //     cout << v[i] << endl;
}
 
 
 
 
int main(){
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    Solve();
    printf("%.3lf\n", ans);// 출력하는 부분
    return 0;
}
