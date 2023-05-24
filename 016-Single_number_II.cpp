/*
137. Single Number II
FEITO EM 24 DE MAIO DE 2023
 # TESTES:
    - {0,1,0,1,0,1,99} -> 99
# TIME COMPLEXITY:
    O(n²)
    O(n) forma otimizada
# EXPLICAÇÃO:
    Utilizando o map, sendo a chave o número do vetor e o valor a quantidade de vezes
    em que o número se repete nesse vetor, foi feito o loop para preenchimento, iterando de
    0 ao tamanho do vetor. Com o unordered_map (hash method) preenchido com as ocorrências
    de cada número no vetor, basta percorrê-lo usando um for com seu iterator de forma a 
    encontrar a chave cuja ocorrência no vetor, ou seja, seu valor, seja menor que 3.
    Como melhorar? Ver a forma otimizada comentada no escopo do código;
    
    - Explicação da melhoria O(n):
    Utilizando a lógica binária,  
    ~ complemento bit a bit -> valor = 7; // Representação binária: 00000111
                               ~valor;    // Representação binária: 11111000

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;
        }

        for(unordered_map<int,int>::iterator it = map.begin(); it != map.end(); ++it) {
            if(it->second < 3) {
                return it->first;
            }
        }
        return 0;
       
        /* OTIMIZAÇÃO -> O(n)
        int n = nums.size();
        int ones = 0;
        int twos = 0;
        for(int i=0; i<n; i++) {
            ones = (nums[i] ^ ones) & (~twos);
            twos = (nums[i] ^ twos) & (~ones);
        }
        return ones;
        */

    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,1,0,1,0,1,99};
    cout << solution.singleNumber(nums) << "\n";
    return 0;
}