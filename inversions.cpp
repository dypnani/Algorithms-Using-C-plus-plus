#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, int left, int right, int ave)
{
    int i, j, k;
    i = left;
    k = left;
    j = ave;
    long long inversions = 0;
    while (i < ave && j < right)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
			if (a[i] != a[j])
			   inversions = inversions+(ave-i);
			else 
			   inversions = inversions+(ave-i-1);
			b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i < ave)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j < right)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++)
    {
        a[i] = b[i];
    }
    return inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  number_of_inversions += merge(a ,  b ,  left, right, ave);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
