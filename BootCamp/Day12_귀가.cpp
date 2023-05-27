#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define INF (99999)
int P;
char N1[10000+10];
char N2[10000+10];
int L[10000+10];
char farm;
int visit[10000+10];
char path[10000+10];
 
struct DATA{
    char start;
    char from;
    char next;
    int cost;
};
map <char, vector<DATA>> m; 
queue <DATA> q;
 
int sol;
 
 
 
 
 
int ToInt(char place){
    switch(place){
    case 'A': return 0;
    case 'B': return 1;
    case 'C': return 2;
    case 'D': return 3;
    case 'E': return 4;
    case 'F': return 5;
    case 'G': return 6;
    case 'H': return 7;
    case 'I': return 8;
    case 'J': return 9;
    case 'K': return 10;
    case 'L': return 11;
    case 'M': return 12;
    case 'N': return 13;
    case 'O': return 14;
    case 'P': return 15;
    case 'Q': return 16;
    case 'R': return 17;
    case 'S': return 18;
    case 'T': return 19;
    case 'U': return 20;
    case 'V': return 21;
    case 'W': return 22;
    case 'X': return 23;
    case 'Y': return 24;
    case 'Z': return 25;
    case 'a': return 30;
    case 'b': return 31;
    case 'c': return 32;
    case 'd': return 33;
    case 'e': return 34;
    case 'f': return 35;
    case 'g': return 36;
    case 'h': return 37;
    case 'i': return 38;
    case 'j': return 39;
    case 'k': return 40;
    case 'l': return 41;
    case 'm': return 42;
    case 'n': return 43;
    case 'o': return 44;
    case 'p': return 45;
    case 'q': return 46;
    case 'r': return 47;
    case 's': return 48;
    case 't': return 49;
    case 'u': return 50;
    case 'v': return 51;
    case 'w': return 52;
    case 'x': return 53;
    case 'y': return 54;
    case 'z': return 55;
    default: return -1;
    }    
}
 
 
 
 
bool IsCow(char cow){
     
    switch(cow){
    case 'A': return true;
    case 'B': return true;
    case 'C': return true;
    case 'D': return true;
    case 'E': return true;
    case 'F': return true;
    case 'G': return true;
    case 'H': return true;
    case 'I': return true;
    case 'J': return true;
    case 'K': return true;
    case 'L': return true;
    case 'N': return true;
    case 'M': return true;
    case 'O': return true;
    case 'P': return true;
    case 'Q': return true;
    case 'R': return true;
    case 'S': return true;
    case 'T': return true;
    case 'U': return true;
    case 'V': return true;
    case 'W': return true;
    case 'X': return true;
    case 'Y': return true;
    default: return false;
    }
}
/* 
a b c d e
f g h i j 
k l n m o
p q r s t
u v w x y
z
*/
 
//연결된 목장이 한개 이상
 
// bool GetSizedd(vector a){
//     if (v.size()>1) return true;
//     else false;}
     
void InputData(){
    m={};
    q={};
    cin >> P;
    for (int i=0; i<P; i++){
        cin >> N1[i] >> N2[i] >> L[i];
        // cout << N1[i];
        m[N1[i]].push_back({N1[i], N1[i], N2[i], L[i]});
        m[N2[i]].push_back({N2[i], N2[i], N1[i], L[i]});
 
    }
     
     
}
 
 
void Init(){
    //visit 배열 초기화
    for (int i=0; i<10000+10; i++){
         
        visit[i]=INF;
    }
     
     
    for (int i=0; i<P; i++){
        // cout << IsCow(N1[i]);
        if (IsCow(N1[i])){
            int size =  m[N1[i]].size();
             
            for (int j=0; j<size; j++){
                q.push({N1[i], N1[i], m[N1[i]][j].next, m[N1[i]][j].cost});
                q.push({N2[i], N2[i], m[N2[i]][j].next, m[N2[i]][j].cost});
                int sgeti = ToInt(N1[i]);
                visit[sgeti] = 0; //Next에 표시
                     
            }
             
        }
     
    }
    // cout << "q" << q.size();
}
 
 
void BFS(){
    int ans = -1;
    char sstart;
    char goal='Z';
     
    while (!q.empty()){
        DATA cur = q.front(); q.pop();
        // cout << q.size();
        char start = cur.start; 
        char from_pos = cur.from; int int_from_pos = ToInt(from_pos);
        char next_pos = cur.next; int int_next_pos = ToInt(next_pos);
        int next_cost = cur.cost;
         
        // cout << " go ";
        // cout << "s " << start << " pos " << from_pos << " next " << next_pos << endl;
        // cout << "c1 "<< visit[int_from_pos] << " c2 " << int_next_pos << " c3 "<< visit[int_next_pos] <<endl;
     
     
        if (visit[int_next_pos] < next_cost+visit[int_from_pos]) continue;
        if (next_pos==goal){ sstart = start;}
        visit[int_next_pos] = next_cost+visit[int_from_pos];
         
        int size =  m[next_pos].size();
        for (int i=0; i<size; i++){
 
            q.push({start, next_pos, m[next_pos][i].next, m[next_pos][i].cost});}
         
    }
     
     
     
    cout << sstart <<" "<< visit[ToInt(goal)];
     
     
}
 
 
 
int main(){
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    // char a='a';
    Init();
    BFS();
 
    // cout << farm << " " << sol << endl;// 출력하는 부분
    return 0;
}
