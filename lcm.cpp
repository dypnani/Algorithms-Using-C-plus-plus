#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(long long a, long long b) {
	long long current_gcd =1;
	long long product = a*b;
	long long temp = 0;
	if (b > a){
		temp = b;
		b = a;
		a = temp;
	}
	while(current_gcd >= 1){
	   	temp = a % b;
	   	if (temp == 0){
	   	   current_gcd = b;
	   	   break;
	    }
	   	a = b;
	   	b = temp;
	}
    return product/current_gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
