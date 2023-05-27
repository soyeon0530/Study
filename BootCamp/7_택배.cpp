#include <iostream>
#include <algorithm>
using namespace std;
 
int N, C, M; //마을 수, 트럭용량, 보내는 박스 정보의 개수
int S[10000+10];
int E[10000+10];
int NUM[10000+10];
 
struct DATA{
    int s;
    int e;
    int num;
};
 
DATA arr[10000+10];
 
bool comp(DATA a, DATA b){
    return a.e < b.e;
}
 
void InputData(){
    cin >> N >> C;
    cin >> M;
    for (int i=0; i<M; i++){
        cin >> arr[i].s  >> arr[i].e >> arr[i].num;
        //CRI[E[i]] +=NUM[i];
         
    }
     
    sort(arr, arr+M, comp);
}
 
int max_val = 0;
void Solve(){
     
    //1: 0 2:1 3:2 4:3 (마을 번호: 해당 마을번호로 오는 마을의 갯수)
     
    //CRI 배열 존재
    //int box=0;
    int truck[2000+10]={0,};
     
    //도착하는 마을 번호
    for (int i=0; i<M; i++){
        DATA cur = arr[i];
        int s = cur.s;
        int e = cur.e;
        int num = cur.num;
         
        int min_avail = 9999;
         
         
        for (int j=s; j<e; j++){
             
            int avail = C-truck[j];
            if (avail>=0){
                if (num <=avail){avail=num;}
                // if (num>avail){avail=num-avail;} // 가지고 있는 양 > 적재가능한 양 (적재해야하는 양 = 적재가능한양)
                min_avail = min(min_avail, avail);
            }
        }   
        for (int j=s; j<e; j++){
            truck[j] += min_avail;
        }
        max_val += min_avail;
    }
}
     
     
 
 
int main(){
    //int ans = -1;
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    Solve();
 
    cout << max_val << endl;// 출력하는 부분
    return 0;
}
