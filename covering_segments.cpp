#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

struct sort_by_end
{
    inline bool operator() (const Segment& struct1, const Segment& struct2)
    {
        return (struct1.end < struct2.end);
    }
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  std::sort(segments.begin(), segments.end(), sort_by_end());
  size_t i = 0;
  while(i < segments.size()) {
  	if (i == 0){
  		points.push_back(segments[i].end);
  		i++;
  		continue;
	}
	int present = points.back();
	if (present >= segments[i].start && present <= segments[i].end){
		i++;
	}
	else {
		points.push_back(segments[i].end);
		i++;
	}
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  return 0;
}
