#include <iostream>
#include <string>
#include <queue>
 
using namespace std;
 
#define MAX_N (300000)
 
int N, K;
long long sol = 0;
string name[MAX_N + 10];
 
queue <int> q[21];
 
//int name_length[MAX_N + 10];
 
void Input_Data(void) {
    string str;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> name[i];
        //name_length[i] = name[i].length();
         
    }
}
 
 
long long BestFriend(){
    long long result = 0;
     
    for (int i=0; i<N;i++){
        // cout << name[i]<< endl;
        int name_length = name[i].length();
 
        while(!q[name_length].empty() && i-q[name_length].front() > K){
            q[name_length].pop();
        }
         
        result += q[name_length].size();
        q[name_length].push(i);
         
    }
    return result;
 
}
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
     
 
    // 입력 받는 부분
    Input_Data();
    sol=BestFriend();
    // 여기서부터 작성
     
 
    // 출력하는 부분
    cout << sol << '\n';
 
    return 0;
}
