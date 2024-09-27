#include <iostream>
using namespace std;

int main() {
  float a;
  float b;
  float x;
  cout << "Nhập a\n";
  cin >> a;
  cout << "Nhập b\n";
  cin >> b;

  if (a == 0 && b == 0) {
    cout << "Phương trình có vô số nghiệm";
  } else if (a == 0) {
    cout << "Phương trình vô nghiệm";
  } else {
    x = -b / a;
    cout << "Nghiệm của phương trình là " << x;
  }
}