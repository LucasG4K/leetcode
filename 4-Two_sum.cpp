/*
1. Two Sum
FEITO EM 10 DE MAIO DE 2023
# TESTES:
    - {0,1,2,3}, 5 -> {2,3}
    - {3,2,4}, 6   -> {1,2}
    - {3,3}, 6     -> {0,1}
# TIME COMPLEXITY:
    O(n²)
    O(?) forma otimizada
# EXPLICAÇÃO:
    - Utilizando o método de força bruta, faz as comparações elemento a elemento
    até que encontremos dois números (que não sejam os de mesma posição) que somados
    sejam o valor de target. Assim, retornamos os seus índices.
    - Como melhorar?
    ???
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target && i != j) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

void printer(vector<int>nums) {
    for (int i : nums)
        cout << i << " ";
    cout << "\n";
}

int main() {
    Solution solution;
    vector<int> nums = {0,1,2,3};
    printer(solution.twoSum(nums, 5));
    nums = {3,2,4};
    printer(solution.twoSum(nums, 6));
    nums = {3,3};
    printer(solution.twoSum(nums, 6));
    return 0;
}