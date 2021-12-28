#include <iostream>
#include <vector>

void insertion(std::vector<int>& arr){
	int size = arr.size();
	for(int i = 0; i < size; i++){
		int pos = i;
		while(pos > 0 && arr[pos] < arr[pos - 1]){
			std::swap(arr[pos], arr[pos - 1]);
			pos--;
		}
	}
}

int main(){
 //insertion(arr)
}
