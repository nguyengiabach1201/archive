#include <iostream>
using namespace std;

bool laSoNguyenTo(int n) {
  if (n > 2) {
    for (int i = 2; i <= n / 2; ++i) {
      if (n % i == 0) {
        return false;
        break;
      }
    }
    return true;
  } else {
    if (n == 2)
      return true;
    return false;
  }
}

int main() {
  int n;
  cout << "Nhập n\n";
  cin >> n;

  for (int x = 2; x <= n; x++) {
    if (laSoNguyenTo(x)) {
      cout << x << "\n";
    }
  }
}