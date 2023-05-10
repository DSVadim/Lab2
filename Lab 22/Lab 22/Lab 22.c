#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* duplicate_first_and_last(Node* head, Node** P1, Node** P2) {
    if (!head || !head->next) {
        return head;
    }

    Node* new_first_node = (Node*)malloc(sizeof(Node));
    new_first_node->data = head->data;

    new_first_node->next = head;
    head->prev = new_first_node;
    head = new_first_node;

    Node* last_node = head;
    while (last_node->next) {
        last_node = last_node->next;
    }

    Node* new_last_node = (Node*)malloc(sizeof(Node));
    new_last_node->data = last_node->data;

    new_last_node->next = NULL;
    new_last_node->prev = last_node;
    last_node->next = new_last_node;

    *P1 = new_first_node;
    *P2 = new_last_node;

    return head;
}

void print_list_forward(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void print_list_backward(Node* tail) {
    while (tail) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

int main() {
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));
    Node* node4 = (Node*)malloc(sizeof(Node));

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    node4->prev = node3;
    node3->prev = node2;
    node2->prev = node1;
    node1->prev = NULL;

    printf("Original : ");
    print_list_forward(node1);

    Node* P1 = NULL;
    Node* P2 = NULL;

    Node* new_head = duplicate_first_and_last(node1, &P1, &P2);

    printf("Modified : ");
    print_list_forward(new_head);

    printf("P1 points to %d\n", P1->data);
    printf("P2 points to %d\n", P2->data);

    return 0;
}
