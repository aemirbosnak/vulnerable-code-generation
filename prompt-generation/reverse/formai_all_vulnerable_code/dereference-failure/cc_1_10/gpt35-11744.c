//FormAI DATASET v1.0 Category: Data recovery tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *head = NULL;

void insert_node(int data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void print_list() {
    node *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void recover_data() {
    FILE *fp;
    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int data;
    while (fscanf(fp, "%d", &data) != EOF) {
        insert_node(data);
    }

    fclose(fp);
}

int main() {
    printf("Data recovery tool\n");
    printf("Reading data from file...\n");

    recover_data();

    printf("Recovered data: ");
    print_list();

    return 0;
}