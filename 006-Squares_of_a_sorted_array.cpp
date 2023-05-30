/*
977. Squares of a Sorted Array
# TESTES:
    - {-4,-1,0,3,10} -> {0,1,9,16,100}
# TIME: O(n)
# SPACE: O(n)
# EXPLICAÇÃO:
    - Cria-se um vetor vazio, realiza o loop deslocando dois apontadores por ele,
    um apontador que começa da direita e outra que começa da esquerda. O objetivo é
    percorrer a lista lado a lado fazendo as comparações entre os valores quadrados
    e armazenando esses valores na nova lista, na posição correta.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares(nums.size());
        int left = 0, right = squares.size() - 1;

        for (int i = nums.size() - 1; left <= right; --i) {
            int squareLeft = nums[left] * nums[left];
            int squareRight = nums[right] * nums[right];
            
            if (squareLeft > squareRight) {
                squares[i] = squareLeft;
                left++;
            } else {
                squares[i] = squareRight;
                right--;
            }
        }

        delete &nums;
        return squares;
    }
};

void printer(vector<int>nums) {
    for (int i : nums)
        cout << i << " ";
    cout << "\n";
}

int main() {
    Solution solution;
    vector<int> nums = {-4,-1,0,3,10};
    printer(solution.sortedSquares(nums));

    return 0;
}