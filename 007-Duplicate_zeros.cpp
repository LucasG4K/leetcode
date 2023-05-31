/*
1089. Duplicate Zeros
# TESTES:
    - {1,0,2,3,0,4,5,0} -> {1,0,0,2,3,0,0,4}
    - {1,2,3} -> {1,2,3}
# TIME: O(n)
# SPACE: O(n)
# EXPLICAÇÃO:
    - Cria-se uma fila vazia, realiza o loop preenchendo a fila com o elemento 
    na posição iterado do vetor e fazendo seu rearranjo no vetor, caso a posição
    iterada tenha o valor 0, a fila é preenchida por 1 valor 0 a mais. Já que
    a fila recebe 2 valores em uma única iteração nesse caso e sabendo que o 
    vetor é sobrescrito a partir dela a duplicação do 0 será realizada corretamente
    e os demais números no vetor serão "empurrados" pela fila.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> q;
        for (int i = 0; i < arr.size(); ++i) {
            q.push(arr[i]);
            if (arr[i] == 0)
                q.push(arr[i]);
            arr[i] = q.front();
            q.pop();
        }
    }
};

void printer(vector<int>nums) {
    for (int i : nums)
        cout << i << " ";
    cout << "\n";
}

int main() {
    Solution solution;
    vector<int> nums = {1,0,2,3,0,4,5,0};
    solution.duplicateZeros(nums);
    printer(nums);

    return 0;
}