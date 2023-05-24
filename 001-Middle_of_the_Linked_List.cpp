/*
876. Middle of the Linked List
FEITO EM 21 DE MARÇO DE 2023
# TESTES:
    - {1,2,3,4,5,6} -> {4,5,6}
    - {1,2,3,4,5}   -> {3,4,5}
# TIME COMPLEXITY:
    O(n)
# EXPLICAÇÃO:
    # Explicação da forma otimizada:
    Com apenas um loop iterando de head até o ponteiro null (nullptr), utilizo uma variável temp e 
    atualizo o ponteiro head. A idéia é fazer com que temp percorra 2x mais rápido, isso implica 
    que head estará na metade do caminho quando temp chegar no ponteiro nulo. Logo, temos a posição exata
    de head que deverá ser retornada no problema;
*/

#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;
        int size = 0;
        while (current) {
            size++;
            current = current->next;
        }

        for (int i = 0; i < size / 2; ++i)
            head = head->next;
        return head;

        /*OTIMIZAÇÃO
        ListNode* current = head;
        while (current) {
            current = current->next->next;
            head = head->next;
        }
        return head;
        */
    }
};

int main() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    Solution solution;
    solution.middleNode(&node1);

    ListNode* current = solution.middleNode(&node1);
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    
    delete &node1;
    delete &node2;
    delete &node3;
    delete &node4;
    delete &node5;

    return 0;
}