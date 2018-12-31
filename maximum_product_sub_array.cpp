#include <bits/stdc++.h>
using namespace std;



int main() {
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  //need to keep track of both positive as well as negative products
  int prevmaxproduct = a[0];
  int prevminproduct = a[0];
  int currentmax = a[0];
  int currentmin = a[0];
  int ans = a[0];

  for(int i = 1; i < n; i++){
    currentmax = max(prevmaxproduct * a[i], max(prevminproduct*a[i], a[i]));

    currentmin = min(prevmaxproduct * a[i], min(prevminproduct*a[i], a[i]));

    ans = max(ans, currentmax);

    prevmaxproduct = currentmax;
    prevminproduct = currentmin;
  }

  cout << ans;
}

/*
n = 7
a[] = 1 -2 -3 0 7 -8 -2
ans: 112
*/
