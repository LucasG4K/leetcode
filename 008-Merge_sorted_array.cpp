/*
88. Merge Sorted Array

# TESTES:
    - nums1 = {1,2,3,0,0,0} | m = 3  ___\ {1,2,2,3,5,6}
      nums2 = {2,5,6} | n = 3           /
    - nums1 = {0} | m = 0            ___\ {1}
      nums2 = {1} | n = 1               /
# TIME: O(n)
# SPACE: O(n)
# EXPLICAÇÃO:
    - Utilizando os 2 vetores vindos do parâmetro, pegamos também os valores efetivos
    de cada um, sendo ele os inteiros n e m. Fazendo então 3 ponteiros, m e last que apontam
    para os elementos de nums1 e n que aponta para o elemento em nums2. O objetivo é verificar
    qual se o elemento em nums1 é maior/igual ou menor que nums2 para decidir qual o número deverá
    ser colocado na posição apontada pelo last no vetor nums1. Isso garante que o "merge" e a reordenação
    dos números seja feita linearmente.
    Ex:
              m         last
    | 1 | 2 | 3 | 0 | 0 | 0 |
              n
    | 2 | 5 | 6 |
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] >= nums2[n - 1])
                nums1[last--] = nums1[--m];
            else
                nums1[last--] = nums2[--n];
        }
        while (n > 0)
            nums1[last--] = nums2[--n];

        delete &nums2;
    }
};

void printer(vector<int>nums) {
    for (int i : nums)
        cout << i << " ";
    cout << "\n";
}

int main() {
    Solution solution;
    vector<int> nums1 = {1,2,3,0,0,0},
                nums2 = {2,5,6};
    int m = 3,
        n = 3;
    solution.merge(nums1, m, nums2, n);
    printer(nums1);

    return 0;
}