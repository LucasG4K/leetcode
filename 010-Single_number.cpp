/*
136. Single Number
# TESTES:
    - {2,2,1}     -> 1
    - {4,1,2,1,2} -> 4
    - {1}         -> 1

# TIME: O(n)
# SPACE: O(1)

# EXPLICAÇÃO:
    - Já que semper temos apenas um número único e os demais em pares,
    utilizando a o operador XOR sempre teremos o número que resta sem pares.
    Ex:
        nums = {4,1,2,1,2}
        1. x = 0; => x = 0 xor 4 = 4 (0000 xor 0100 = 0100);
        2. x = 4; => x = 4 xor 1 = 5 (0100 xor 0001 = 0101);
        3. x = 5; => x = 5 xor 2 = 7 (0101 xor 0010 = 0111);
        4. x = 7; => x = 7 xor 1 = 6 (0111 xor 0001 = 0110);
        5. x = 6; => x = 6 xor 2 = 4 (0110 xor 0010 = 0100);
        Desse modo x = 4, que é o número sem par e, portanto, sozinho.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int i : nums)
            x ^= i;
        return x;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4,1,2,1,2};
    cout << solution.singleNumber(nums) << "\n";
    return 0;
}