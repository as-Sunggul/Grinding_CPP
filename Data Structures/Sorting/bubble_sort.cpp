#include <iostream>
#include <vector>
#define pb push_back

void bubble(std::vector<int>& arr){
	int size = arr.size();
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - 1 - i; j++){
			if(arr[j] > arr[j + 1]){
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main(){
  //sort(arr)
}
