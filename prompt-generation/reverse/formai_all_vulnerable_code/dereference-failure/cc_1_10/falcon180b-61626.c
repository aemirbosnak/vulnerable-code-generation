//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define NODE_SIZE 200
#define NODE_NUM 5

typedef struct node {
    char data[NODE_SIZE];
    struct node *next;
} Node;

Node *head = NULL;

void init() {
    head = (Node *)malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    head->next = NULL;
}

void append(char *str) {
    Node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = (Node *)malloc(sizeof(Node));
    if (temp->next == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(temp->next->data, str);
    temp->next->next = NULL;
}

void backup() {
    FILE *fp;
    char filename[20];
    Node *temp = head;
    int i = 1;

    while (temp!= NULL) {
        sprintf(filename, "backup%d.txt", i);
        fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("Error opening file\n");
            exit(1);
        }
        while (temp!= NULL) {
            fputs(temp->data, fp);
            temp = temp->next;
        }
        fclose(fp);
        temp = head;
        i++;
    }
}

int main() {
    init();
    char str[100];

    while (1) {
        printf("Enter string to append (or type 'backup' to backup data): ");
        scanf("%s", str);

        if (strcmp(str, "backup") == 0) {
            backup();
        } else {
            append(str);
        }
    }

    return 0;
}