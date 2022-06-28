#include <bits/stdc++.h>

using namespace std;

int MatrixChainOrder(int arr[], int n)

{

int p[n][n];

int i, j, k, l, q;
for (i = 1; i < n; i++) p[i][i] = 0;

for (l = 2; l < n; l++)

{

for (i = 1; i < n - l + 1; i++)

{

j = i + l - 1;

p[i][j] = INT_MAX;

for (k = i; k <= j - 1; k++)

{

q = p[i][k] + p[k + 1][j]

+ arr[i - 1] * arr[k] * arr[j];

if (q < p[i][j])

p[i][j] = q;

}

}
}

return p[1][n - 1];

}

int main()

{

int n;
cout<<"Enter the size of the array"<<endl; cin>>n;

int arr[n];
cout<<"Enter the array"<<endl; for(int i=0;i<n;i++){ cin>>arr[i];

}

cout << "Minimum matrix multiplications is "
<< MatrixChainOrder(arr, n); return 0;
}
