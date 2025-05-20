//FormAI DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct cyber_node {
    int id;
    char* name;
    char* cyberpower;
    struct cyber_node* next;
} CyberNode;

CyberNode* cyber_city = NULL;

void add_cyber_node(int id, char* name, char* cyberpower) {
    CyberNode* new_node = (CyberNode*) malloc(sizeof(CyberNode));
    new_node->id = id;
    new_node->name = (char*) malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->cyberpower = (char*) malloc(strlen(cyberpower) + 1);
    strcpy(new_node->cyberpower, cyberpower);
    new_node->next = NULL;

    if (cyber_city == NULL) {
        cyber_city = new_node;
    } else {
        CyberNode* current_node = cyber_city;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void remove_cyber_node(int id) {
    CyberNode* prev_node = NULL;
    CyberNode* current_node = cyber_city;
    while (current_node != NULL) {
        if (current_node->id == id) {
            if (prev_node == NULL) {
                cyber_city = current_node->next;
            } else {
                prev_node->next = current_node->next;
            }
            free(current_node->name);
            free(current_node->cyberpower);
            free(current_node);
            return;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
}

void print_cyber_nodes() {
    printf("Cyber City:\n");
    printf("ID\tName\tCyberpower\n");
    printf("--\t----\t----------\n");
    CyberNode* current_node = cyber_city;
    while (current_node != NULL) {
        printf("%d\t%s\t%s\n", current_node->id, current_node->name, current_node->cyberpower);
        current_node = current_node->next;
    }
}

int main() {
    add_cyber_node(1, "Samantha", "Hacker");
    add_cyber_node(2, "Max", "Programmer");
    add_cyber_node(3, "Logan", "Cyber Ninja");
    add_cyber_node(4, "Violet", "Data Scientist");
    print_cyber_nodes();
    remove_cyber_node(2);
    printf("\nAfter removing Max:\n");
    print_cyber_nodes();
    return 0;
}