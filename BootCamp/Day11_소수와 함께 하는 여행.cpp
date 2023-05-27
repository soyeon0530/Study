#include <iostream>
#include <queue>
#include <string>
using namespace std;
 
int S, E;//출발 정류장 번호, 도착 정류장 번호
int min_ans=99999;
bool visited[10000+10]={false,};
struct bus_stop{
    int num; int t;
};
queue <bus_stop> q;
 
 
void InputData(){
    cin >> S >> E;
}
 
 
//소수인지 아닌지 판별하는 함수. ? ?? => 배열에 넣어놓기.
bool IsPossible(int n) {
    for (int i = 2; i < n; i++) {
        if (n%i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
            return false;
        }
    }
    return true;
}
 
int Make_Num(int cur, int i, int j){
    string c = to_string(j);
    string temp = to_string(cur);
    temp.replace(i,1,c);
    return stoi(temp);
}
 
int BFS(){
    int choose[]={0,1,2,3};
    int num[] = {0,1,2,3,4,5,6,7,8,9};
    q={};
    q.push({S,0});
    visited[S]=1;
     
    while (!q.empty()){
        bus_stop cur = q.front(); q.pop();
        // cout <<cur.num << " " << cur.t << endl;
         
        for (int i=0; i<4; i++){
            int get_pos = choose[i];
             
            for (int j=0; j<10; j++){
                int get_num=num[j];
                if (i==0 && j== 0) continue; //j가 0일떄는 계산x
             
                 
                int new_num = Make_Num(cur.num, get_pos, get_num);
                //cout << new_num <<" ";
                 
                if (new_num==cur.num) continue;
                if (new_num==E){min_ans=min(min_ans, cur.t + 1);}
                if (visited[new_num]) continue;  //같은 수 방문x
                //cout << IsPossible(new_num) << endl;
                if (IsPossible(new_num)==false) continue; // 소수X -> pass
                // cout << q.size();
                q.push({new_num, cur.t+1});
                visited[new_num] = true;
            }
        }
    }
    return min_ans;  
}
int main(){
    int ans = -1;
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    BFS();
 
    cout << min_ans << endl;// 출력하는 부분
    return 0;
}
