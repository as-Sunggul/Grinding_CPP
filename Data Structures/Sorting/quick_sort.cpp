#include <iostream>
#include <vector>

int partition(std::vector<int> &arr, int left, int right){
	int pivot = arr[right];
	int pIndeks = left;
	for(int i = left; i < right; i++){
		if(arr[i] <= pivot){
			std::swap(arr[i], arr[pIndeks]);
			pIndeks++;
		}
	}
	std::swap(arr[pIndeks], arr[right]);
	return pIndeks;
}

void quick(std::vector<int>& arr, int left, int right){
	if(left >= right)return;
	int current = partition(arr, left, right);
	quick(arr,left, current - 1);
	quick(arr,current + 1, right);
}

int main(){
 //quick(arr) 
}
