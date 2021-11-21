#include <iostream>

// 单向扫描的分割函数
int parititionOne(int[], int, int);
// 双向扫描的标准分割函数
int paritition(int[], int, int);
void quickSort(int[], int, int);

int main(int argc, char const *argv[]) {
  int arr[10] = {7,4,5,8,9,6,2,3,7,5};
  int length = sizeof(arr)/sizeof(int);
  std::cout << parititionOne(arr, 0, length - 1) << '\n';
  for (auto i : arr) std::cout << i << '\t';
  return 0;
}

int parititionOne(int array[], int low, int high) {
  int pivot = array[low];
  while (low < high) {
    if (array[high] < pivot) {
      array[low] = array[high];
      array[high] = array[++low];
    } else {
      --high;
    }
  }
  array[low] = pivot;
  return low;
}

int paritition(int array[], int low, int high) {
  int pivot = array[low];
  while (low < high) {
    while (low < high && array[high] >= pivot) --high;
    array[low] = array[high];
    while (low < high && array[low] <= pivot) ++low;
    array[high] = array[low];
  }
  array[low] = pivot;
  return low;
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pivot = paritition(array, low, high);
    quickSort(array, low, pivot - 1);
    quickSort(array, pivot + 1, high);
  }
}
