#include <iostream>

#define M 6

#define N 6

using namespace std;

bool bipartiteGraph[M][N] = {

{0, 1, 1, 0, 0, 1},

{1, 0, 0, 1, 0, 0},

{0, 0, 1, 0, 0, 0},

{0, 0, 1, 1, 0, 0},

{0, 0, 0, 0, 0, 0},

{0, 0, 0, 0, 0, 1}

};
bool bipartiteMax(int u, bool visited[], int a[]) { for (int v = 0; v < N; v++) {
if (bipartiteGraph[u][v] && !visited[v]) { visited[v] = true;
if (a[v] < 0 || bipartiteMax(a[v], visited, a)) { a[v] = u;
return true;

}

}

}

return false;

}
int maxMatch() {

int a[N];
for(int i = 0; i<N; i++) a[i] = -1;
int Count = 0;
for (int u = 0; u < M; u++) { bool visited[N];
for(int i = 0; i<N; i++) visited[i] = false;
if (bipartiteMax(u, visited, a)) Count++;
}

return Count;

}

int main() {

cout << "Maximum number of applicants matching for a particular job: " << maxMatch();

}
