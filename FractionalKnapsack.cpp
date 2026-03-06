#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity)
    {
        int n = val.size();
        // pair<ratio, pair<value, weight>>
        vector< pair<double, pair<int, int> > > items;
        for(int i = 0; i < n; i++)
        {
            double ratio = (double) val[i] / wt[i];
            items.push_back(make_pair(ratio, make_pair(val[i], wt[i])));
        }
        // sort in decreasing order of ratio
        sort(items.begin(), items.end(), greater< pair<double, pair<int,int> > >());
        double totalval = 0.0;
        int currentwt = 0;
        for(int i = 0; i < n; i++)
        {
            int itemval = items[i].second.first;
            int itemwt  = items[i].second.second;
            double ratio = items[i].first;
            if(currentwt + itemwt <= capacity)
            {
                currentwt += itemwt;
                totalval += itemval;
            }
            else
            {
                int remaining = capacity - currentwt;
                totalval += remaining * ratio;
                break;
            }
        }
        return totalval;
    }
};
int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    Solution sol;
    double result = sol.fractionalKnapsack(val, wt, capacity);

    cout << "Maximum value in knapsack = " << result << endl;

    return 0;
}
