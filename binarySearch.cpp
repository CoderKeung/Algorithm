#include <iostream>
using namespace std;

int binarySearch(int[], int, int);

int main(){
  int list[] = {1, 3, 5, 7, 9};
  int item = 2;
  cout << binarySearch(list, 5, item) << endl;
  return 0;
}

int binarySearch(int list[], int len, int item) {
  int low = 0;
  int high = len - 1;
  while (low <= high) {
    int mid = (high + low) / 2;
    int guess = list[mid];
    if (guess == item)
      return mid;
    if (guess > item)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

