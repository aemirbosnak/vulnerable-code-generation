//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    char symbol;
} Node;

typedef struct {
    Node* nodes;
    int size;
} List;

List* createList(int size) {
    List* list = (List*)malloc(sizeof(List));
    list->nodes = (Node*)malloc(size*sizeof(Node));
    list->size = size;
    return list;
}

void destroyList(List* list) {
    free(list->nodes);
    free(list);
}

void printList(List* list) {
    for(int i=0; i<list->size; i++) {
        printf("%c ", list->nodes[i].symbol);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    List* list = createList(10);
    
    for(int i=0; i<list->size; i++) {
        list->nodes[i].value = rand()%100;
        if(list->nodes[i].value < 50) {
            list->nodes[i].symbol = '@';
        } else {
            list->nodes[i].symbol = '#';
        }
    }
    
    printf("===== Welcome to CyberData! =====\n\n");
    printf("CyberData is a unique data structure visualization tool for Cyberpunk programmers.\n");
    printf("Each node in the list is represented by either '@' or '#' symbol.\n");
    printf("The more numeric value a node has, the more likely it is to be represented by '#'.\n\n");
    printf("Here is your list:\n");
    printList(list);
    
    destroyList(list);
    printf("\nThank you for using CyberData! See you again soon!\n");
    return 0;
}