#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int p =n;
  for(int i=1; i <= p; i++){
    if (n >= i){
  	  summands.push_back(i);
  	  n -= i;
    }
    else{
      summands[summands.size()-1] = summands.back() + n;
      break;
	}
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  return 0;
}
