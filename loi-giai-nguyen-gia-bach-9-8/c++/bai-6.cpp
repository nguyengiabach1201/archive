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
  bool nLaSoNguyenTo;
  cout << "Nhập n\n";
  cin >> n;
  nLaSoNguyenTo = laSoNguyenTo(n);
  if (nLaSoNguyenTo == 1) {
    cout << "n là số nguyên tố\n";
  } else {
    cout << "n không phải là số nguyên tố\n";
  }
}