#include <iostream>
using namespace std;

int main() {
  int a;
  int b;
  int c;
  int x = 100;

  while (x < 999) {
    a = x / 100;
    b = (x - a * 100) / 10;
    c = x - a * 100 - b * 10;

    if ((a + b + c) % 4 == 0)
      cout << x << "\n";

    x += 1;
  }
}