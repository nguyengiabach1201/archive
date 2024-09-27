#include <iostream>
using namespace std;

int main() {
  int n;
  int x = 1;
  int S = 0;
  cout << "Nhập n\n";
  cin >> n;
  while (x <= n) {
    S = S + x;
    x += 1;
  }
  cout << S;
}