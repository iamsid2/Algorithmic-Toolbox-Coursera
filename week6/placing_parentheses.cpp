#include <iostream>
#include <cassert>
#include<string>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

long long eval(long long a, long long b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp)
{
    int length = exp.size();
  int n = (length + 1) / 2;
  long long minA[n][n];
  long long maxA[n][n];
  memset(minA,0,sizeof(minA));
  memset(maxA,0,sizeof(maxA));
  for (int i = 0; i < n; i++)
  {
	  minA[i][i] = std::stoll(exp.substr(2*i,1));
	  maxA[i][i] = std::stoll(exp.substr(2*i,1));
  }

  for (int s = 0; s <  n-1; s++)
  {
	  for (int i = 0; i < n-s - 1; i++)
	  {
		  int j = i + s + 1;
		  long long minVal = LLONG_MAX;
	      long long maxVal = LLONG_MIN;
		  for (int k = i; k < j; k++ )
	      {
			  long long a = eval(minA[i][k],minA[k + 1][j],exp[2 * k + 1]);
			  long long b = eval(minA[i][k],maxA[k + 1][j],exp[2 * k + 1]);
			  long long c = eval(maxA[i][k],minA[k + 1][j],exp[2 * k + 1]);
			  long long d = eval(maxA[i][k],maxA[k + 1][j],exp[2 * k + 1]);
			  minVal = min(minVal,min(a,min(b,min(c,d))));
			  maxVal = max(maxVal,max(a,max(b,max(c,d))));
	      }
		  minA[i][j] = minVal;
		  maxA[i][j] = maxVal;
	  }
  }

  return maxA[0][n - 1];
}

int main()
{
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
}
