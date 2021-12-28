#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <vector>
#define pb push_back


class sort{
private:
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

public:
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

	void maximum(std::vector<int>& arr) {
	   int n = arr.size();
	   for(int i = n - 1; i >= 0; i--){
	       int maksIndeks = i;
	       for(int j = i - 1; j >= 0; j--){
	           if(arr[j] > arr[maksIndeks])maksIndeks = j;
	       }
	       std::swap(arr[i], arr[maksIndeks]);
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

	void quick(std::vector<int>& arr, int left, int right){
		if(left >= right)return;
		int current = partition(arr, left, right);
		quick(arr,left, current - 1);
		quick(arr,current + 1, right);
	}

};



int main(){
	std::srand((unsigned)time(0));
	int lower = 0, upper = 10, size = 10;
	//std::cout<<"Lower bound : ";std::cin>>lower;
	//std::cout<<"Upper bound : ";std::cin>>upper;
	//std::cout<<"Number of numbers : ";std::cin>>size;
	
	int temp;
	std::vector<int> cnt;
	for(int i = 0; i < size; i++){
		temp = (rand() % (upper + lower - 1) + 1);
		cnt.push_back(temp);
	}
	
	std::cout<<"\nBefore sorting :";
	for(auto x : cnt){
		std::cout<<x<<" ";
	}
	
	// sort Sort;
  // now Sort is an object that you can use to access different types of sorting from sort class
	

	std::cout<<"\nAfter sorting :";
	for(auto x : cnt){
		std::cout<<x<<" ";
	}
	std::cout<<"\n\n\n";
	
}
