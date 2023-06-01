#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAXH (5)
#define MAXW (9)
char map[MAXH+2][MAXW+2];
int tot_pin;
int remain_pin;
 
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
 
int solremain, solmove;
void InputData(){
    for (int h=1; h<=MAXH; h++){
        cin >> &map[h][1];
    }
}
 
void Get_tot_pin(){
 
     
    tot_pin=0;
    solmove=0;
    for (int h=1; h<=MAXH; h++){
        for (int j=1; j<=MAXW; j++){
            if (map[h][j]=='o') tot_pin++;
        }
    }    
    solremain = tot_pin;
}
 
void DFS(int n){//돌아다닌개수
    if (solmove < n) solmove = n;
     
    for (int h=1; h<=MAXH; h++){
        for (int j=1; j<=MAXW; j++){
            if (map[h][j]=='o'){
                    int cur_x = h;
                    int cur_y = j;
                    // cout << "cur.x" << h <<" cur.y " << cur_y << endl;
                    for (int i=0; i<4; i++){
                 
                        int n_x = dx[i]+cur_x;
                        int n_y = dy[i]+cur_y;
                         
                        int nn_x = dx[i]+n_x;
                        int nn_y = dy[i]+n_y;
                         
                         
                         
                        if (n_x<1 || n_y<1 || n_x>MAXH || n_y>MAXW) continue;
                        if (nn_x<1 || nn_y<1 || nn_x>MAXH || nn_y>MAXW) continue;
                         
                         
                        if (map[n_x][n_y]=='o' && map[nn_x][nn_y]=='.'){
                            map[nn_x][nn_y]='o';
                            map[n_x][n_y]='.';
                            map[cur_x][cur_y]='.';
                 
                            DFS(n+1);
                             
                            map[nn_x][nn_y]='.';
                            map[n_x][n_y]='o';
                            map[cur_x][cur_y]='o';
                        }
                    }
            }
        }
    }
}
 
 
int main(){
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분
        
        Get_tot_pin();
        DFS(0);
 
 
        cout << solremain - solmove  << " " << solmove << endl;//출력하는 부분
    }
    return 0;
}
