#include <iostream>
#include <stack>
using namespace std;
int N;//히스토그램수
int H[100000+10];//히스토그램 높이
long long idx = 0;
 
bool InputData() {
    cin >> N;
    if (N == 0) return false;
     
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
    H[N]=-1;
    return true;
}
 
long long Solve(){
     
    stack <pair<int, int>> s;
    long long max_square;
 
    max_square=-1;
    for (int i=0; i<=N; i++){
        int temp =i;
         
        while (s.size()!=0 && s.top().second > H[i]){
             
            long long idx = s.top().first;
            temp = idx;
            long long height = s.top().second;
             
             
            long long square =  height*(i-idx);
            if (max_square<square){
                max_square = square;
            }
            s.pop();
        }
         
        s.push({temp,H[i]});
    }
     
    return max_square;
     
     
}
 
int main() {
     
    while(InputData()){//입력받는 부분
        long long ans = -1;
 
        ans = Solve();
        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}
