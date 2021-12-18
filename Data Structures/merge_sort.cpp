#include <iostream
#include <vector>
#define pb push_back

void merge(std::vector<int> left, std::vector<int> right, std::vector<int>& arr){
	arr.clear();
	int nL = left.size();
	int nR = right.size();
	int leftpointer = 0, rightpointer = 0, current = 0;
	while(leftpointer < nL && rightpointer < nR){
		if(left[leftpointer] <= right[rightpointer]){
			arr.pb(left[leftpointer]);
			leftpointer++;
		}else{
			arr.pb(right[rightpointer]);
			rightpointer++;
		}
		current++;
	}
	
	while(leftpointer < nL){
		arr.pb(left[leftpointer]);
		current++;
		leftpointer++;
	}
	
	while(rightpointer < nR){
		arr.pb(right[rightpointer]);
		current++;
		rightpointer++;
	}
	
	
}


void mergesort(std::vector<int>& arr){
	int n = arr.size();
	if(n < 2)return;
	int mid = n/2;
	std::vector<int> right;
	std::vector<int> left;
	for(int i = 0; i < mid; i++){
		left.pb(arr[i]);
	}
	
	for(int i = mid; i < n; i++){
		right.pb(arr[i]);
	}
	mergesort(left);
	mergesort(right);
	merge(left, right, arr);
	left.clear();
	right.clear();
}

int main(){
 //mergesort(arr) 
}

