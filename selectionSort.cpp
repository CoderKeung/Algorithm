#include <iostream>
#include <vector>
using namespace std;

int findSmallest(vector<int>);
vector<int> selectionSort(vector<int>);

int main(int argc, char const *argv[]) {
  vector<int> v = {5,6,7,3,2,1};
  vector<int> a = selectionSort(v);
  for (auto i : a) std::cout << i << '\n';
  return 0;
}

int findSmallest(vector<int> arr) {
  int smallest = arr[0];
  int smallestIndex = 0;
  for (size_t i = 0; i < arr.size(); i++) {
    if (arr[i] < smallest) {
      smallest = arr[i];
      smallestIndex = i;
    }
  }
  return smallestIndex;
}

vector<int> selectionSort(vector<int> arr) {
  vector<int> newArr;
  for (auto i : arr) {
    int smallestIndex = findSmallest(arr);
    newArr.push_back(arr[smallestIndex]);
    arr.erase(arr.begin()+smallestIndex);
  }
  return newArr;
}
