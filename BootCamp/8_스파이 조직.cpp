#include <iostream>
#include <map>
using namespace std;
 
int N;
int depth; 
char A[20000+10];
char ans[20000+10];
 
 
void InputData(){
    cin >> N >> A;
}
 
int idx = 0;
 
void Solve(){
    int ten;
    for (int i=1; A[i]!=0; i++){
        //cout << A[i] << " " ; 
        //cout << depth << endl;
        if (A[i]=='<'){
            depth++;
            //ten=0;
 
        }
        else if (A[i]=='>'){
            depth--;
            //ten=0;
        }
 
        if (depth==N && A[i]!='>' && A[i]!='<'){
            while (A[i]!='>' && A[i]!='<'){
                //i++;
                cout << A[i];
                i=i+1;
         
            }
            i=i-1;
            cout << " ";
        }
        //i=i-1;
         
    }
}
 
void Output(){
    for (int i=0; i<idx; i++){
        cout << ans[i] << " ";
    }
}
 
int main (){
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    Solve();
    //Output();
    return 0;
}
