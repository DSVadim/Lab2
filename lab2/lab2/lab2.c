#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* duplicate_first_and_last(Node* head) {
    if (!head) {
        return head;
    }

    Node* new_first_node = (Node*)malloc(sizeof(Node));
    new_first_node->data = head->data;

    new_first_node->next = head;
    head = new_first_node;

    Node* last_node = head;
    while (last_node->next) {
        last_node = last_node->next;
    }

    Node* new_last_node = (Node*)malloc(sizeof(Node));
    new_last_node->data = last_node->data;

    new_last_node->next = NULL;
    last_node->next = new_last_node;

    return head;
}

void print_list(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
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

    printf("Original : ");
    print_list(node1);

    Node* new_head = duplicate_first_and_last(node1);

    printf("Modified : ");
    print_list(new_head);

    return 0;
}
