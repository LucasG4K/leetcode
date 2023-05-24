/*
9. Palindrome Number
FEITO EM 24 DE MARÇO DE 2023
Testes:
    - 1          -> True
    - 11         -> True
    - 101        -> True
    - 1221       -> True
    - 1234       -> False
    - 1234567899 -> False
EXPLICAÇÃO:
    O(n)
    Em uma iteração pelo inteiro, fazemos a divisão por 10 do x original até que obtenhamos 0.
    Fazendo isso, estamos pegando o resto da divisão do número decimal (base 10).
    O resto da divisão indica cada algarismo decorrente da divisão por 10 de modo que decompomos o número
    utilizando o quociente e sempre dividindo-o até que o resultado das divisões chegue no valor 0.
    Exemplos:
    - Caso 1002
        1002/10 = 100 e resto 2
        100/10  =  10 e resto 0 
        10/10   =   1 e resto 0
        1/10    =   0 e resto 1
    Acima, unindo o resto de cada divisão, temos o valor 2001. Comparando com o número 1002 originalmente, vemos que
    na forma invertida, os 2 números são diferentes e portanto não são palíndromos, devendo retornar o booleano false.
    - Caso 101
        101/10 = 10 e resto 1
        10/10  =  1 e resto 0
        1/10   = 10 e resto 1
    Acima, unindo o resto de cada divisão, temos o valor 101. Comparando com o número 101 originalmente, vemos que
    na forma invertida, os 2 números são iguais e portanto são palíndromos, devendo retornar o booleano true.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        else if (x < 10) return true;
        
        unsigned int num = x, palindrome = 0;
        
        while (num) {
            palindrome = palindrome * 10 + num % 10; // dígito * 10 + resto
            num /= 10; // conta 1 algarismo lido
        }

        if (x == palindrome) return true;
        return false;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome(1) << endl;
    cout << solution.isPalindrome(11) << endl;
    cout << solution.isPalindrome(101) << endl;
    cout << solution.isPalindrome(1221) << endl;
    cout << solution.isPalindrome(1234) << endl;
    cout << solution.isPalindrome(1234567899) << endl;
    return 0;
}