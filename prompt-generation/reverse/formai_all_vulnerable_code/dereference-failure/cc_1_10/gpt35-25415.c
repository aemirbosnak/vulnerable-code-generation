//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
 
struct Node {
    int val;
    struct Node* next;
};
 
struct Metadata {
    int num_nodes;
    int total_val;
};
 
struct Metadata* extract_metadata(struct Node* head) {
    struct Metadata* metadata = (struct Metadata*)malloc(sizeof(struct Metadata));
    if(head==NULL) {
        metadata->num_nodes = 0;
        metadata->total_val = 0;
    }
    else {
        struct Metadata* child_metadata = extract_metadata(head->next);
        metadata->num_nodes = child_metadata->num_nodes + 1;
        metadata->total_val = child_metadata->total_val + head->val;
        free(child_metadata);
    }
    return metadata;
}
 
void print_list(struct Node* head) {
    if(head!=NULL) {
        printf("%d ", head->val);
        print_list(head->next);
    }
}
 
int main() {
    // Build the linked list
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    head->val = 1;
    head->next = (struct Node*) malloc(sizeof(struct Node));
    head->next->val = 2;
    head->next->next = (struct Node*) malloc(sizeof(struct Node));
    head->next->next->val = 3;
    head->next->next->next = NULL;
 
    // Print the linked list
    printf("Linked List: ");
    print_list(head);
    printf("\n");
 
    // Extract metadata and print
    struct Metadata* metadata = extract_metadata(head);
    printf("Number of nodes: %d\n", metadata->num_nodes);
    printf("Total value: %d\n", metadata->total_val);
    free(metadata);
 
    return 0;
}