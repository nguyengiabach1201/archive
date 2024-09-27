#include <iostream>
using namespace std;

int main() {
  int n = 1, E, S = 0;
  cout << "Nhập E\n";
  cin >> E;
  
  while (S <= E) {
    S += n;
    n++;
  }
  cout << n;
}