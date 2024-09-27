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
  int n, x, S = 0;
  cout << "Nhập n\n";
  cin >> n;
  cout << "Nhập x\n";
  cin >> x;
  for (int i = 1; i <= n; i++) {
    S = S + pow(x, i) / giaiThua(i);
  }
  cout << S;
}