#include <iostream>
#include <vector>

using std::vector;



void merge(int sortindex[], double perunit[], int n, int low, int mid, int high){
	int n1 = mid-low+1;
	int n2 = high-mid;
	double first[n1];
	double second[n2];
	int sort[n1+n2];
	for(int i=0; i < n1; i++){
		first[i] = perunit[low+i];
	}
	for(int j=0; j < n2; j++){
		second[j] = perunit[mid+1+j];
	}
	for(int i=0; i< n ; i ++){
		sort[i]= sortindex[i];
	}
	int i = 0;
	int j = 0;
	int k = low;
	while (i<n1 && j<n2){
		if(first[i] <= second[j]){
			perunit[k] = first[i];
			sortindex[k] = sort[low+i];
			i++;
		}
		else{
			perunit[k] = second[j];
			sortindex[k] = sort[mid+1+j];
			j++;
		}
		k++;
	}
	while (i < n1){
		perunit[k] = first[i];
		sortindex[k] = sort[low+i];
		i++;
		k++;
	}
	while (j < n2){
		perunit[k] = second[j];
		sortindex[k] = sort[mid+1+j];
		j++;
		k++;
	}		
}

void mergesort(int sortindex[], double perunit[], int n, int low, int high){
	int mid = (low+high)/2;
	if (low < high){
    	mergesort(sortindex, perunit, n , low, mid);
	    mergesort(sortindex, perunit, n,  mid+1, high);
	    merge(sortindex, perunit, n , low, mid, high);
    }
}

double get_optimal_value(int n, double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  int p = 0;
  double perunit[n];
  int sortindex[n];
  for (int i = 0; i < n; i++){
    if (weights[i] == 0 ){
    	perunit[i] =  0;
  	    sortindex[i] = i;
	}
  	else {
	    perunit[i] =  values[i]/weights[i];
  	    sortindex[i] = i;
    }
  }
  mergesort(sortindex, perunit, n, 0, n-1);

  for (int i = n-1; i>=0 ; i--){
	  p = sortindex[i];
	  if((capacity - weights[p]) > 0){
	  	  if(weights[p]==0){
	  	  	continue;
		  }
		  capacity -= weights[p];
		  value += values[p];
	  }
	  else{
	  	  if(weights[p] == 0){
	  	  	continue;
		  }
		  value += (values[p]/weights[p])*capacity;
		  break;
	  }
  }
  return value;
}
	


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  double optimal_value = get_optimal_value(n, capacity, weights, values);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
