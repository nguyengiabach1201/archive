#include <iostream>
using namespace std;

int main() {
  int n1, n2, max;

  cout << "Nhập 2 số:\n";
  cin >> n1 >> n2;

  max = (n1 > n2) ? n1 : n2;

  while (true) {
    if (max % n1 == 0 && max % n2 == 0) {
      cout << "Bội chung nhỏ nhất là: " << max;
      break;
    } else
      ++max;
  }

  return 0;
}