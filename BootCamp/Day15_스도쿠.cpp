#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN (9)
int sudoku[MAXN][MAXN];
int row[MAXN];
int col[MAXN];

// vector <int> all_v;
struct pos{
    int x; int y;
};

pos v_pos[82];
int cnt_zero =0;
// q={};

void InputData(){
    // q={};
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cin >> sudoku[r][c];
            if (sudoku[r][c]==0){
                
                v_pos[cnt_zero].x = r;
                v_pos[cnt_zero].y = c;
                cnt_zero++;
            }
            
        }
    }
}
void OutputData(){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cout << sudoku[r][c] << " ";
        }
        cout << endl;
    }
}


bool flag = false;
void DFS(int n, int val, int x, int y){
    // cout << "n " << n << " val " << val << " x " << x << " y " << y <<endl;
    if (n>=cnt_zero) {
        flag=true;
        return;
    }
    // cout << "chck row" << endl;
    
    //열
    sudoku[v_pos[n].x][v_pos[n].y]=val;
    for (int i=0; i<MAXN; i++){
        if (i==y) continue;
        if (sudoku[x][i]==val) return;
    }
    
    //행 (2차원)
    for (int i=0; i<MAXN; i++){
        if (i==x) continue;
        if (sudoku[i][y]==val) return;
    }

    //행, 열
    int start_x = 3*(x/3); int start_y = 3*(y/3);
    // cout << "start_x " <<start_x << " start_y " << start_y << endl;
    
    for (int i=start_x; i< start_x+3; i++){
        for (int j=start_y; j< start_y+3; j++){
            if (i==x && j==y) continue;
            if (sudoku[i][j]==val) {return;}
        }
    }
            
   
    for (int val=1; val<=MAXN; val++){

        
        DFS(n+1, val, v_pos[n+1].x, v_pos[n+1].y);
        if (flag) return;
        sudoku[v_pos[n+1].x][v_pos[n+1].y]=0;
        
        
    }
    
}

int main(){
    InputData();//입력받는 부분
    for (int val=1; val<=MAXN; val++){
        // sudoku[v_pos[0].x][v_pos[0].y]=val;
        DFS(0, val, v_pos[0].x, v_pos[0].y);
        if (flag) break;
        sudoku[v_pos[0].x][v_pos[0].y]=0;
    }

    OutputData();
   //출력하는 부분
    return 0;
}
