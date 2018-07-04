#include <iostream>
#include <vector>

using namespace std;

long long merge_sort(vector<int> &a, size_t left, size_t right)
{
    long long inv_count = 0;
    for(size_t i = 0;i<right;i++)
    {
        for(size_t j=i+1;j<=right;j++)
        {
            if(a[i] > a[j])
               inv_count++;
        }
    }
    return inv_count;

}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    cin >> a[i];
  }
  cout << merge_sort(a, 0, (a.size() - 1))<< '\n';
}
