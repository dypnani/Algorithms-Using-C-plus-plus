#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int explore(vector<vector<int> > &adj, int x, vector<int>& visited, vector<int>& recstack) {
  visited[x] = 1; 
  recstack[x] = 1;
  for(int i = 0;i < adj[x].size(); i++){		      
	     if (visited[adj[x][i]] != 1 && explore(adj,adj[x][i],visited,recstack) == 1)
	          return 1; 
         else if (recstack[adj[x][i]] ==1) 
              return 1;
  }
  recstack[x] = 0;
  return 0;
}

int acyclic(vector<vector<int> > &adj, int n) {
  int result = 0;
  vector<int> visited(n,0);
  vector<int> recstack(n,0);
  for(int i=0; i < n; i++){
  	 if (visited[i] != 1)
       if (explore(adj,i,visited,recstack) == 1)
            return 1;
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  
  std::cout << acyclic(adj, n);
}
