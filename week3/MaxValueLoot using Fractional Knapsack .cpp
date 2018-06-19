#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct items{
    int weights;
    int values;
    double val;
};

struct by_val{
    bool operator()(items const &a, items const &b)   {
        return a.val < b.val;
    }
};

double get_optimal_value(int capacity, vector<items> specs, int num) {
    double value = 0.0;
    int a;
    while (capacity>0 && num!=0)  {
        a = min(specs[num-1].weights, capacity);
        value = value + a*specs[num-1].val;
        capacity = capacity - a;
        num--;
    }
    return value;
}

int main() {
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<items> specs;
    for (int i = 0; i < n; i++) {
        specs.push_back(items());
        cin >> specs[i].values >> specs[i].weights;
        specs[i].val = (double) specs[i].values/specs[i].weights;
    }
    sort(specs.begin(), specs.end(), by_val());
    double optimal_value = get_optimal_value(capacity, specs, n);
    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}
