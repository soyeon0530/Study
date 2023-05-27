#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
#define MAX (100)
int N;//색종이 수
int X[100 + 10];//가로 시작 좌표
int Y[100 + 10];//세로 시작 좌표
int Paper[MAX + 10][MAX + 10];//도화지[세로][가로]
void FillPaper(int sr, int sc, int er, int ec) {
    for (int r = sr; r < er; r++) {
        for (int c = sc; c < ec; c++) {
            Paper[r][c] = 1;
        }
    }
}
struct STK {
    int h, n;
};
int CalAreaN(int r) {
    stack <STK> stk = {};
    int maxarea = 100;
    for (int c = 0; c < MAX; c++) {
        int n = c;
        while (!stk.empty() && (stk.top().h > Paper[r][c])) {
            n = stk.top().n;
            int area = stk.top().h * (c - stk.top().n);
            if (maxarea < area) maxarea = area;
            stk.pop();
        }
        if (!stk.empty() && (stk.top().h == Paper[r][c])) continue;
        stk.push({ Paper[r][c], n });
    }
    while (!stk.empty()) {
        int area = stk.top().h * (MAX - stk.top().n);
        if (maxarea < area) maxarea = area;
        stk.pop();
    }
    return maxarea;
}
int SolveN2(void) {//시간복잡도 O(N 2제곱)
    int maxarea = 100;
    //0.초기화
    memset(Paper, 0, sizeof(Paper));
    //1.색종이 붙이기
    for (int i = 0; i < N; i++) {
        FillPaper(Y[i], X[i], Y[i] + 10, X[i] + 10);
    }
    //2.세로 높이 구하기
    for (int c = 0; c < MAX; c++) {
        for (int r = 1; r < MAX; r++) {
            if (Paper[r][c] == 0) continue;
            Paper[r][c] += Paper[r - 1][c];
        }
    }
    //3.직사각형 중 최대 넓이 찾기
    for (int r = 1; r < MAX; r++) {//세로 인덱스
        int area = CalAreaN(r);
        if (maxarea < area) maxarea = area;
    }
    return maxarea;
}
  
void InputData(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }
}
  
int main(void) {
    int ans = -1;
    InputData();//입력받는 부분
  
    ans = SolveN2();
  
    printf("%d\n", ans);//출력하는 부분
    return 0;
}
