#include <iostream>
using namespace std;
 
int N;
int A[100+10]; //변의 길이
int B[100+10];
int map[100+10][100+10]={0,};
 
 
 
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i] >> B[i];
 
    }
}
 
void MakeMap(){
     
    int chck =0;
    for (int i=0; i<N; i++){
        int x = A[i]; int y = B[i];
         
        for (int j=x; j<x+10; j++){
            for (int k=y; k<y+10; k++)
                map[j][k]=1; // start: 1
                chck++;
        }
    }
    //cout << chck << endl;
}
 
int cnt=0;
void Cal(){
   int dx[] = {-1,1,0,0};
   int dy[] = {0,0,-1,1};
    
    
   for (int i=0; i<100; i++){
       for (int j=0; j<100; j++){
           
           if (map[i][j]==1){
               for (int k=0; k<4; k++){
                   int new_x = i+dx[k]; 
                   int new_y = j+dy[k];
                    
                   if (new_x>=0 && new_y>=0 && new_x<=100 && new_y<=100)
                        if (map[new_x][new_y]==0) cnt++;
                    
                    
               }
           }
        
            
            
       }
   } 
}
 
 
 
 
int main(){
    //int res=0;
    //int ans = -1;
 
    InputData();// 입력받는 부분
    MakeMap();
    Cal();
    // 여기서부터 작성
    cout << cnt << endl;
    return 0;
}
