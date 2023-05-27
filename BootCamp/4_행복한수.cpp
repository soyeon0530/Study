#include <iostream>
#include <vector>
using namespace std;
#define MAXN ((int)1e3)
 
 
int N;
int used[MAXN + 10];
vector <int> v;
 
void InputData(){
    cin >> N;
}
 
 
int CalSum(int val){
     
    int sum=0;
    //int cnt = 0;
     
    if (val/10<1) return val*val; //한자릿수
     
    while(val>=10){
        sum = sum + (val%10)*(val%10);
        val = val/10;
    }
    sum += val*val; 
    return sum;
}
 
 
bool Chck(int val){
    for (int i=0; i<v.size(); i++){
        if(v[i]==val) return true;
    }
    v.push_back(val);
    return false;
}
 
int ans = 0;
void Solve(){
     
    int val; // 초깃값
    bool next = false;
     
    //cout << val << " ";
    for (int i=N; i>0; i--){
        //cout << "i" << i << " ";
        v={};
        next = false;
        val=i;
        while (next==false){
             
            val = CalSum(val);
            //cout << val << endl;
             
            next = Chck(val);
            if (val==1 && ans<i) {
                //cout << val << endl;
                //cout << N << endl;
                ans = i;
                next = true;
            }
        }
    }
     
     
}
 
int main(){
    //int ans = -1;
    InputData();//입력받는 부분
 
    //여기서부터 작성
    Solve();
    cout << ans << endl;//출력하는 부분
    return 0;
}
