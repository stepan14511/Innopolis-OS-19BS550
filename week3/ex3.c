#include <stdio.h>

typedef struct Node Node; // This is needed to use a pointer to Node inside the Node struct

struct Node{
    int value;
    Node* next_node;
    Node* prev_node;
};

void print_list(Node* first_node){
    printf("%d ", first_node->value);
    if (first_node->next_node != NULL){
        print_list(first_node->next_node);
    }
    if(first_node->prev_node == NULL){
        printf("\n"); // New line after printing
    }
}

void insert_node(Node* node_itself, Node* prev_node){
    // Reassigning dependencies between the nodes.
    node_itself->next_node = prev_node->next_node;
    prev_node->next_node = node_itself;
    
    if(node_itself->next_node != NULL) node_itself->next_node->prev_node = node_itself;
    node_itself->prev_node = prev_node;
}

void delete_node(Node* node){
    // Reassigning dependencies between the nodes.
    if(node->prev_node != NULL) node->prev_node->next_node = node->next_node;
    if(node->next_node != NULL) node->next_node->prev_node = node->prev_node;
}

int main(){
    // Create head node
    Node head_node;
    head_node.next_node = NULL;
    head_node.prev_node = NULL;
    head_node.value = 1;
    printf("Added first element (value = 1): ");
    print_list(&head_node);

    Node second_node;
    second_node.value = 2;
    insert_node(&second_node, &head_node);
    printf("Added element (value = 2) after the first one: ");
    print_list(&head_node);

    Node third_node;
    third_node.value = 3;
    insert_node(&third_node, &head_node);
    printf("Added element (value = 3) after the first one: ");
    print_list(&head_node);

    delete_node(&third_node);
    printf("Deleted the second node (value = 3): ");
    print_list(&head_node);


    delete_node(&second_node);
    printf("Deleted the second node (value = 2): ");
    print_list(&head_node);

    return 0;
}