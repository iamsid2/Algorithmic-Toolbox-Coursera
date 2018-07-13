#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int lcs2(vector<int> &X, vector<int> &Y)
{
   int m = X.size();
   int n = Y.size();
   int LCS[m+1][n+1];
   int i, j;
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         LCS[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         LCS[i][j] = LCS[i-1][j-1] + 1;

       else
         LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
     }
   }
   return LCS[m][n];


}

int main()
{
  size_t n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  size_t m;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  cout << lcs2(a, b) << endl;
}
