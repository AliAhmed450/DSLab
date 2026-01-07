#include <iostream>
using namespace std;

struct task2 {
  int findPartition(int arr[], int left, int right) {
    int mid = (left + right) / 2;
    if (arr[mid] < 0) {
      if (arr[mid - 1] > -1) {
        return mid;
      }
      return findPartition(arr, left, mid);
    }

    if (arr[mid] > -1 && arr[mid + 1] < 0) {
      return mid + 1;
    }
    return findPartition(arr, mid, right);
  }

  void rearrangearray(int arr[], int start, int end) {
    int temp = arr[end];
    for (int i = end; i > start; i--) {
      arr[i] = arr[i - 1];
    }
    arr[start] = temp;
  }

  void rearrage(int arr[], const int size) {
    int partition = findPartition(arr, 0, size - 1);

    int loopCount = size - partition;
    int start = 0;
    int end = partition;
    for (int i = 0; i < loopCount; i++) {
      rearrangearray(arr, start, end);
      start++;
      end++;
    }
  }
  int main() {
    const int size = 10;
    int arr[size] = {1, 5, 7, 8, 15, 16, -1, -7, -22, -67};
    cout << "Before: " << endl;
    for (auto x : arr) {
      cout << x << " ";
    }

    cout << endl;
    rearrage(arr, size);
    cout << "After: " << endl;
    for (auto x : arr) {
      cout << x << " ";
    }
    cout << endl;
    return 0;
  }
};
