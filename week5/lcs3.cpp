#include <iostream>
#include <vector>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
     int an = a.size();
	int bn = b.size();
	int cn = c.size();
	int LCS3[an+1][bn+1][cn+1];

	for(int i=0; i<=an; i++)
	{
		for(int j=0; j<=bn; j++)
		{
			for(int k=0; k<=cn; k++)
			{
				if(i == 0 || j == 0 || k == 0)
					LCS3[i][j][k] = 0;
				else if(a[i-1] == b[j-1] && a[i-1] == c[k-1])
					LCS3[i][j][k] = LCS3[i-1][j-1][k-1] + 1;
				else
					LCS3[i][j][k] = max(max(max(max(max(LCS3[i-1][j][k], LCS3[i][j-1][k]), LCS3[i][j][k-1]), LCS3[i-1][j-1][k]), LCS3[i-1][j][k-1]), LCS3[i][j-1][k-1]);
			}
		}
	}
  return LCS3[an][bn][cn];
}

int main()
{
  int an;
  cin >> an;
  vector<int> a(an);
  for (int i = 0; i < an; i++)
  {
    cin >> a[i];
  }
  int bn;
  cin >> bn;
  vector<int> b(bn);
  for (int i = 0; i < bn; i++)
  {
    cin >> b[i];
  }
  int cn;
  cin >> cn;
  vector<int> c(cn);
  for (int i = 0; i < cn; i++)
  {
    cin >> c[i];
  }
  cout << lcs3(a, b, c) << endl;
}
