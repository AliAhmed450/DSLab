#include <iostream>
using namespace std;
struct task1 {

  void rotateToRight(int arr[], const int size, int &rotationCount) {
    if (rotationCount == 0)
      return;

    for (int i = size - 1; i >= 0; i--) {
      arr[i] = arr[i - 1];
    }

    rotationCount--;
    rotateToRight(arr, size, rotationCount);
  }

  int main() {
    const int size = 365;
    int arr[size] = {1, 5, 3, 5, 2};
    int rotationCount = 5;
    rotateToRight(arr, size, rotationCount);

    for (auto x : arr) {
      cout << x << " ";
    }
    return 0;
  }
};
