/*
Valid Mountain Array
FEITO EM 23/05/2023
Testes:
    - {0,1,2,1,0}           -> True
    - {1,2}                 -> False
    - {0,1,2,1,2,0}         -> False
    - {9,8,7,6,5,4,3,2,1,0} -> False
EXPLICAÇÃO:
    O(n)
    Com apenas um loop iterando de 0 a arr.size() - 1 utilizo 3 variáveis de controle
    inicializadas como false. O objetivo é que ao fim do programa as 3 variáveis estejam
    com valor true para que a montanha de array seja válida.
    Para atender essas condições:
    # arr.size() deve ter pelo menos tamanho 3
    # quando arr[i] < arr[i + 1], isso indica que ele está subindo e deve acontecer apenas no início da execução, logo -> up = true;
    # quando arr[i] > arr[i + 1], isso indica que ele está descendo e deve acontecer apenas no meio para o fim da execução, logo -> control_up = true, indicando que a subida já foi realizada e não pode mais acontecer e down = true, indicando a descida;
    # caso arr[i] == arr[i + 1], então o array não contém a montanha válida e por isso é terminado
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;

        bool up = false, down = false, control_up = false;

        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] < arr[i + 1] && !control_up)
                up = true;
            else if (arr[i] > arr[i + 1]) {
                control_up = true;
                down = true;
            } else return false;
        }

        if(control_up && down && up)
            return true;
        else return false;
    }
};


int main() {
    Solution solution;
    vector<int> arr = {9,8,7,6,5,4,3,2,1,0};
    cout << solution.validMountainArray(arr);
    return 0;
}