/*
217. Contains Duplicate
# TESTES:
    - {1,2,3,1}             -> true
    - {1,2,3,4}             -> false
    - {1,1,1,3,3,4,3,2,4,2} -> true

# POSSÍVEIS ABORDAGENS:
    Brute force O(n^2)
    Ordenação   O(nlog(n))
    Hash        O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) 
            if (nums[i] == nums[i + 1])
                return true;
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3,1};
    cout << solution.containsDuplicate(nums) << "\n";
    return 0;
}