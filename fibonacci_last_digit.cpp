#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fibonacci_last_digit_fast(int n) {
    std::vector<int> v(n+1);
    v[0]=0;
    v[1]=1;
    for(int i=2; i<=n; i++){
    	v[i] = (v[i-1]+v[i-2])%10;
	}

    return v[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
