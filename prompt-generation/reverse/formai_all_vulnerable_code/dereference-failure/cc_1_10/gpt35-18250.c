//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 10
#define BUFF_SIZE 100

struct XMLNode {
    char *tag;
    char *content;
    int num_children;
    struct XMLNode **children;
};

void free_node(struct XMLNode *node) {
    if (node == NULL) {
        return;
    }
    free(node->tag);
    free(node->content);
    for (int i = 0; i < node->num_children; i++) {
        free_node(node->children[i]);
    }
    free(node->children);
    free(node);
}

int main() {
    char buff[BUFF_SIZE];
    int stack_pointer = -1;
    struct XMLNode *stack[MAX_DEPTH];
    struct XMLNode *current_node = NULL;
    while (fgets(buff, BUFF_SIZE, stdin) != NULL) {
        if (buff[0] == '<' && buff[1] != '/') {
            // open tag case
            stack_pointer++;
            stack[stack_pointer] = malloc(sizeof(struct XMLNode));
            stack[stack_pointer]->tag = malloc(BUFF_SIZE);
            int i = 1, j = 0;
            while (buff[i] != '>') {
                stack[stack_pointer]->tag[j] = buff[i];
                i++;
                j++;
            }
            stack[stack_pointer]->tag[j] = '\0';
            stack[stack_pointer]->num_children = 0;
            stack[stack_pointer]->children = malloc(MAX_DEPTH * sizeof(struct XMLNode));
            if (current_node != NULL) {
                current_node->children[current_node->num_children] = stack[stack_pointer];
                current_node->num_children++;
            }
            current_node = stack[stack_pointer];
        } else if (buff[0] == '<' && buff[1] == '/') {
            // close tag case
            if (stack_pointer == -1) {
                printf("Error: closing tag without matching opening tag!\n");
                return 1;
            }
            if (strcmp(current_node->tag, buff+2) != 0) {
                printf("Error: closing tag does not match opening tag!\n");
                return 1;
            }
            current_node = stack[--stack_pointer];
        } else {
            // content case
            current_node->content = malloc(BUFF_SIZE);
            strcpy(current_node->content, buff);
        }
    }
    if (stack_pointer != -1) {
        printf("Error: unclosed tag(s)!\n");
        return 1;
    }
    printf("XML parsing successful!\n");
    free_node(current_node);
    return 0;
}