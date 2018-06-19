
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
 {
  int n,i,j;
  int W;
  cin >> n >> W;
  vector<int> val(n);
  vector<int> wt(n);
  for (i = 0; i < n; i++)
  {
     cin >> val[i] >> wt[i];
  }

  for (i = 0; i < n-1; i++)
  {
    for(j=0;j<n-i+1;j++)
    {
        int tmp,tmp1;
        if((val[j]/wt[j]) > (val[j+1]/wt[j+1]))
            {
                tmp = wt[j];
                wt[j] = wt[j+1];
                wt[j+1] = tmp;
                tmp1 = val[j];
                val[j]=val[j+1];
                val[j+1]=tmp1;

            }
       }
    }
      for(i=0;i<n;i++)
      cout<<wt[i]<<" ";
      for(i=0;i<n;i++)
      cout<<val[i]<<" ";


      double X[n], opt_val = 0.0;
      int w = 0;
      for(i=0;i<n;i++)
        X[i] = 0.0;
      for(i=n-1;i>=0;i--)
        {
          if(w + wt[i] < W)
            {
              X[i] = 1;
              w = w + wt[i];
              opt_val += val[i];
            }
        else
        {
           X[i] = (W - w) / wt[i];
           w = W;
           opt_val += X[i] * val[i];
           break;
        }

        }

      cout.precision(10);
      cout << opt_val << endl;
      return 0;
    }
