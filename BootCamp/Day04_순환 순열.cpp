#include <iostream>
#include <vector>
using namespace std;
 
#define MAXIN (1000)
int N, P;
//int vector[MAXIN] // 나머지 < 몫
 
vector <int> v;
void InputData(){
    cin >> N >> P;
}
 
bool Chck(int val){
     
    if (val==0) {
        v={};
        v.push_back(0);
        return true;}
     
    for (int i=0; i < v.size(); i++){
        if (v[i]==val) {
            return true;
        }
    }
     
    v.push_back(val);
    return false;
}
 
void Cal(){
    bool circle = false;
    int val = N; // start
     
    while (circle==false){
         
         
        //cout << N << endl;
        val = val*N;
        //cout << val << endl;
        val = val%P;
        //cout << val << endl;
         
        circle = Chck(val);
    }    
}
 
void Solve(){
    Cal();
    //return cnt
}
 
int main(){
    int ans = -1;
    InputData();// 입력받는 부분
    Solve();
    // 여기서부터 작성
    ans = v.size();
    cout << ans << endl;// 출력하는 부분
    return 0;
}
