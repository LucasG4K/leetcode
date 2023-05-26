/*
Replace Elements with Greatest Element on Right Side
FEITO EM 25 DE MAIO DE 2023
# TESTES:
    - {17,18,5,4,6,1} -> {18,6,6,6,1,-1}
    - {400}           -> {-1}
    - {17,18}         -> {18,-1}
# TIME COMPLEXITY:
    1. O(n²) brute force -> comentado
    2. O(n) forma otimizada
# EXPLICAÇÃO:
    1. Utilizando o método de força bruta, faz as comparações entre o elemento e seus demais
    a direita até que encontre o maior número que está a direita e substitua na posição atual.
    Faça isso até que chegue a penúltima posição do vetor, depois complete o penúltimo com
    o valor do último e o último com o valor -1.
    2. Iterando no vetor de n à 0, o objetivo é ter duas variáveis, uma auxiliar e a outra
    para armazenar o maior elemento atual do vetor. Devemos iniciar a variável com -1 já que ela
    deverá substituir o valor na posição n e imediatamente assumir o valor de n-1, que será maior
    já que o vetor assume apenas elementos positivos. A variável que guarda o maior número, só será atualizada
    se encontrar outro número a esquerda que seja maior que o ela. A variável auxiliar, serve para guardar o maior
    valor no começo da iteração, para que ele não seja sobrescrito caso entre no if. Assim, a variável auxiliar
    será a responsável por jogar o valor para dentro do vetor à cada iteração feita.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

      /*if(arr.size() < 2)
            return arr = {-1};
        int biggest;
        for (int i = 0; i < arr.size() - 2; ++i) {
            biggest = arr[i + 1];
            for (int j = i+1; j < arr.size(); ++j) {
                if(biggest < arr[j]) {
                    biggest = arr[j];
                }
            }
            arr[i] = biggest;
        }
        arr[arr.size() - 2] = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;*/
        
        int biggest = -1, temp;
        for (int i = arr.size() - 1; i >= 0; --i) {
            temp = biggest;
            if (biggest < arr[i])
                biggest = arr[i];
            arr[i] = temp;
        }

        return arr;
    }
};

void printer(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
}

int main() {
    Solution solution;
    vector<int> arr = {17,18,5,4,6,1};
    solution.replaceElements(arr);
    printer(arr);
    return 0;
}