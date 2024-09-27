#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int m, n = 2;
  cout << "Nhập số\n";
  cin >> m;

  while (n * n <= m) {
    if (m % n == 0) {
      cout << n << "x";
      m /= n;
    } else {
      n++;
    }
  }

  if (m > 1)
    cout << m;
}