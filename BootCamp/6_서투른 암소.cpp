#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
 
char str[100000+10];
int N=0;
int ans = 0;
stack <char> s;
 
 
void InputData(){
    cin >> str;
}
 
void CountN(){
    for (int i=0; i<100000+10; i++){
        //cout << str[i] << endl;
        if (str[i]==')' || str[i]=='(') N++;
        else break;
    }
    //cout << N << endl;
}
 
int Solve(){
    s={};
    //cout << s.size() << endl;
    for (int i=0; i<N; i++){
        char c = str[i];
 
        if (c=='(') s.push(c);
        if (c==')'){
            if (!s.empty())
                s.pop();
            else if (s.empty()){
                s.push('(');
                ans+=1;
            }
        }
        //cout << c << endl;
        //cout << s.size() << endl;
    }
     
    //cout << ans << s.size() ;
    if (s.empty()) return ans;
    ans = ans+s.size()/2;
    return ans;
}
 
 
//균형:  갯수, 방향
int main(){
     
 
    InputData();// 입력받는 부분
    CountN();
    ans = Solve();
    // 여기서부터 작성
 
    cout << ans << endl;// 뒤집어야 하는 괄호 최소수
    return 0;
}
