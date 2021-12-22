#include <iostream>

using namespace std;

int maze[1001][1001];
int dp[1001][1001];

int find_max(int a , int b);

int main() {
  int N ,M;
  cin >> N >> M;

  for(int i =0; i<N;i++){
    for(int j =0; j<M; j++){
      cin >> maze[i][j];
    }
  }

  dp[0][0] = maze[0][0];

  for(int i =0; i<N; i++){
    for(int j =0; j<M; j++){
      dp[i+1][j] = find_max(maze[i+1][j] + dp[i][j] , dp[i+1][j]);

      dp[i][j+1] = find_max(maze[i][j+1] + dp[i][j] , dp[i][j+1]);

      dp[i+1][j+1] = find_max(maze[i+1][j+1] + dp[i][j] , dp[i+1][j+1]);

      
    }
  }

  cout << dp[N-1][M-1];
  return 0;
  
}

int find_max(int a , int b){
  if(a>b) return a;
  else return b;
}