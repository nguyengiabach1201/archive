#include <cmath>
#include <iostream>
using namespace std;

int giaiThua(int n) {
  int dapSo = 1;
  for (int i = 1; i <= n; i++) {
    dapSo = dapSo * i;
  }
  return dapSo;
}

int main() {
  int n, S = 0;
  cout << "Nhập n\n";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    S = S + giaiThua(i);
  }
  cout << S;
}