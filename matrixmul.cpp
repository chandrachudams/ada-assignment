#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int d[], int n)
{


	int c[n][n];

	int i, j, k, L, q;


	for (i = 1; i < n; i++)
		c[i][i] = 0;


	 for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            c[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {

                q = c[i][k] + c[k + 1][j]
                    + d[i - 1] * d[k] * d[j];
                if (q < c[i][j])
                    c[i][j] = q;
            }
        }
    }

	return c[1][n - 1];
}

// Driver Code
int main()
{
	cout<<"Enter the size of the array\n";
	int n;
	cin>>n;
    cout<<"Enter the array of the sizes of the matrices:\n";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr,n);

	return 0;
}


