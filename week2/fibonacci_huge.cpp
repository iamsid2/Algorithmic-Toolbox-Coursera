#include <iostream>
#include<vector>

using namespace std;

long long get_fibonacci_huge(long long n, long long m)
{
	if(n == 0)
	{
      return 0;
    }
	vector<long> fib(n+1);
	vector<long> mod(m+1);

	fib[0] = 0;
	fib[1] = 1;
	mod[0] = 0;
	mod[1] = 1;

	int i=2;
	while(1)
	{
		fib[i] = mod[i-1] + mod[i-2];
		mod[i] = fib[i] % m;
		if(mod[i-1] == 0 && mod[i] == 1)
			break;
		i++;
	}
	int rem = (int)(n % (i-1));
	return fib[rem] % m;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge(n, m) << '\n';
}
