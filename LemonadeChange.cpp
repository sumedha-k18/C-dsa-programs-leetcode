#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int five = 0, ten = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            int bill = bills[i];
            if (bill == 5)
            {
                five++;
            }
            else if (bill == 10)
            {
                if (five == 0)
                    return false;
                five--;
                ten++;
            }
            else // bill == 20
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    int n;
    cout << "Enter number of customers: ";
    cin >> n;
    vector<int> bills(n);
    cout << "Enter bills (5, 10, 20):\n";
    for (int i = 0; i < n; i++)
        cin >> bills[i];
    Solution sol;
    if (sol.lemonadeChange(bills))
        cout << "True (Correct change possible)\n";
    else
        cout << "False (Change not possible)\n";
    return 0;
}
