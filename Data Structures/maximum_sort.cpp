#include <iostream>
#inlcude <vector>

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

int main(){
  //maximum(arr)
}
