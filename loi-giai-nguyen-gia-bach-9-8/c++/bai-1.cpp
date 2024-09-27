#include <iostream>
using namespace std;

int main() {
  int a;
  cout << "Nhập a\n";
  cin >> a;
  if (a % 2 == 0) {
    cout << "a là số chẵn";
  } else {
    cout << "a là số lẻ";
  }
}