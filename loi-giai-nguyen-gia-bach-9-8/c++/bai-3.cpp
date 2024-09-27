#include <iostream>
using namespace std;

int main() {
  int a;
  int b;
  int c;
  int d;
  cout << "Nhập a\n";
  cin >> a;
  cout << "Nhập b\n";
  cin >> b;
  cout << "Nhập c\n";
  cin >> c;
  if (a > c) {
    d = c;
    c = a;
    a = d;
  }
  if (a > b) {
    d = b;
    b = a;
    a = d;
  }
  cout << a << " " << b << " " << c;
}