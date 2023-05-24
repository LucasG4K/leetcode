/*
13. Roman to Integer
FEITO EM MARÇO DE 2023
Testes:
    - XVIII -> 18
    - XIV   -> 14
    - XIX   -> 19
EXPLICAÇÃO:
    O(n)
    Com apenas um loop iterando a string de parâmetro faço comparações entre
    o caracter lido na string e o seu sucessor. Em números romanos, os números
    geralmente são organizados do maior para o menor (Ex. XV -> 10 > 5, logo soma obtendo 15). Vemos então
    que basta somar os números para esses casos. Em casos em que um número menor esteja
    antecedendo um número maior, significa que o número menor deverá ser subtraído na soma
    final do romano (Ex. IV -> 1 < 4, logo subtrai o menor valor do maior, obtendo 4).
    Obs: o primeiro if mesmo avaliando s[i+1] com o for indo até o tamanho da string não irá gerar problemas,
    uma vez que nunca entraremos no if quando i chegar em s.size(), em decorrência do número romano ter sempre
    no final um menor que seu antecessor. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                sum -= roman[s[i]];
            } else {
                sum += roman[s[i]];
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("XVIII") << endl;
    cout << s.romanToInt("XIV") << endl;
    cout << s.romanToInt("XIX") << endl;
    cout << s.romanToInt("") << endl;
    return 0;
}