#include <iostream>
#include <vector>


void shell(std::vector<int>& array) {
    int n = array.size();
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array.at(j) = array[j - interval];
      }
      array.at(j) = temp;
    }
  }
}

int main(){
  //shell(arr)
}
