#include <iostream>
using namespace std;

void sapXep(float a[], int n) {
  for (int step = 0; step < n -1; ++step) {
    for (int i = 0; i < n - step - 1; ++i) {
      if (a[i] > a[i + 1]) {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    }
  }
}

int main() {
  int n;
  cout << "Nhập n\n";
  cin >> n;
  cout << "Nhập dãy các số từ a1 tới an\n";

  float *a = new float[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sapXep(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}