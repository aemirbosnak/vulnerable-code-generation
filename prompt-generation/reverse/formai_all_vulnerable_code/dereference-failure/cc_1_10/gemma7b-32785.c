//Gemma-7B DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct CmdNode {
    char cmd[MAX_CMD_LEN];
    struct CmdNode* next;
} CmdNode;

CmdNode* cmd_insert(CmdNode* head, char* cmd) {
    CmdNode* newNode = malloc(sizeof(CmdNode));
    strcpy(newNode->cmd, cmd);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void cmd_print(CmdNode* head) {
    CmdNode* current = head;

    while (current) {
        printf("%s\n", current->cmd);
        current = current->next;
    }
}

int main() {
    CmdNode* head = NULL;

    char cmd[MAX_CMD_LEN];

    printf("Enter a command: ");
    scanf("%s", cmd);

    while (strcmp(cmd, "exit") != 0) {
        head = cmd_insert(head, cmd);

        printf("Enter a command: ");
        scanf("%s", cmd);
    }

    printf("List of commands:\n");
    cmd_print(head);

    return 0;
}