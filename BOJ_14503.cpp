#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int N, M;
int r, c, d;
int nr, nc;
int arr[50][50] = {0,};
bool movable[4] = {true, true, true, true};

int leftr[4] = {0, -1, 0, 1};
int leftc[4] = {-1, 0, 1, 0};

int backr[4] = {1, 0, -1, 0};
int backc[4] = {0, -1, 0, 1};

int clean(int nr, int nc) {
  memset(movable, true, sizeof(movable) / sizeof(bool));
  r = nr;
  c = nc;
  arr[nr][nc] = -1;
  return 1;
}

int search() {
  int cnt = 0;
  if(arr[r][c] == 0) {
    arr[r][c] = -1;
    cnt += 1;
  }

  while(true) {
    switch(d) {
      case 0:
      case 1:
      case 2:
      case 3:
        nr = r + leftr[d];
        nc = c + leftc[d];
        if(nr > -1 && nr < N && nc > -1 && nc < M) {
          if(arr[nr][nc] == 0) {
            cnt += clean(nr, nc);
            movable[d] = true;
          }
          else {
            movable[d] = false;
          }
          d = d - 1 >= 0 ? d - 1 : 3;
        }
    }

    if(!movable[0] && !movable[1] && !movable[2] && !movable[3]) {
      nr = r + backr[d];
      nc = c + backc[d];
      if(nr > -1 && nr < N && nc > -1 && nc < M && arr[nr][nc] != 1) {
        r = nr;
        c = nc;
        memset(movable, true, sizeof(movable) / sizeof(bool));
      }
      else {
        break;
      }
    }
  }
  
  return cnt;
}

int main() {
  scanf("%d %d", &N, &M);
  scanf("%d %d %d", &r, &c, &d);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  printf("%d\n", search());
}