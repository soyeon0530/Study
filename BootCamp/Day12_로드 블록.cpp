#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
int N, M;
int A[10000 + 10];
int B[10000 + 10];
int L[10000 + 10];
int nMap[100+10][100+10];
int CostMap[100+10][100+10];
struct Data
{
    int dist;   //누적 거리
    int pos;    //내 위치
    vector <int> path;   // 경로
};
void InputData(){
    cin >> N >> M;
    for (int i = 0; i<M; i++){
        cin >> A[i] >> B[i] >> L[i];
    }
}
void BuildMap()
{
    for (int i = 0; i<M; i++){
        nMap[A[i]][B[i]] = L[i];
        nMap[B[i]][A[i]] = L[i];
    }
}
int change_solve(int s, int e)
{
    fill(CostMap[0],CostMap[100+10],INT_MAX);
    nMap[s][e] *= 2;
    nMap[e][s] *= 2;
    queue <Data> q;
    q.push({0,1,{}});
    int check_dist = INT_MAX;
    vector<int> check_path;
    while(!q.empty())
    {
        int cur_dist = q.front().dist;
        int cur_pos = q.front().pos;    //행 시작지점
        vector<int> cur_path = q.front().path;
        q.pop();
        if(cur_pos == N && check_dist > cur_dist)
        {
            check_dist = cur_dist;
            check_path = cur_path;
            // cout << "succes";
        }
        // cout << "CUR DIST : " << cur_dist << " cur_POS " << cur_pos << endl;
        for(int i = 0; i <= 100; i++)   //열 도착지점
        {
            int new_pos = i;
            int new_dist = cur_dist + nMap[cur_pos][i];
            vector<int> new_path = cur_path;
            if( nMap[cur_pos][new_pos] != 0 && CostMap[cur_pos][new_pos] > new_dist )
            {
                CostMap[cur_pos][new_pos] = new_dist;
                new_path.push_back(cur_pos);
                q.push({new_dist, new_pos, new_path});
            }
        }
    }
    // cout << "succes check_dist = " << check_dist << endl;
    nMap[s][e] /= 2;
    nMap[e][s] /= 2;
    return check_dist;
}
void solve()
{
    BuildMap();
    queue <Data> q;
    q.push({0,1,{}});
    int check_dist = INT_MAX;
    vector<int> check_path;
    while(!q.empty())
    {
        int cur_dist = q.front().dist;
        int cur_pos = q.front().pos;    //행 시작지점
        vector<int> cur_path = q.front().path;
        q.pop();
        if(cur_pos == N && check_dist > cur_dist)
        {
            check_dist = cur_dist;
            check_path = cur_path;
            // cout << "succes";
        }
        // cout << "CUR DIST : " << cur_dist << " cur_POS " << cur_pos << endl;
        for(int i = 0; i <= 100; i++)   //열 도착지점
        {
            int new_pos = i;
            int new_dist = cur_dist + nMap[cur_pos][i];
            vector<int> new_path = cur_path;
            if( nMap[cur_pos][new_pos] != 0 && CostMap[cur_pos][new_pos] > new_dist )
            {
                CostMap[cur_pos][new_pos] = new_dist;
                new_path.push_back(cur_pos);
                q.push({new_dist, new_pos, new_path});
            }
        }
    }
    check_path.push_back(N);
    // cout << check_dist << endl;
    int ans = 0;
    for(int i = 0; i < check_path.size()-1; i++)
    {
        // cout << check_path[i] << " " << check_path[i+1] << endl;
        int result = change_solve(check_path[i], check_path[i+1]);
        ans = max(ans, result);
    }
        // cout << "ans = " << ans << endl;
        cout << ans - check_dist << endl;
}
int main(){
    InputData();// 입력받는 부분
    fill(CostMap[0],CostMap[100+10],INT_MAX);
    solve();
    return 0;
}
