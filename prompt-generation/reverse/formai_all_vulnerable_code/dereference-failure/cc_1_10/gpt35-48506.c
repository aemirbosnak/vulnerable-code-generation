//FormAI DATASET v1.0 Category: Firewall ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node {
    char rule[100];
    struct node *next;
}Node;

void addRule(Node** head, char* rule) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->rule, rule);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printRules(Node* head) {
    Node* temp = head;
    printf("\nThe Firewall Rules are:\n");
    while (temp != NULL) {
        printf("%s\n", temp->rule);
        temp = temp->next;
    }
}

void removeRule(Node** head, char* rule) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->rule, rule) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nRule not found!\n");
        return;
    }

    if (prev != NULL) {
        prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    printf("\nRule deleted successfully!\n");
}

int checkRules(Node* head, char* packet) {
    Node* temp = head;
    while (temp != NULL) {
        char* rule = strdup(temp->rule);
        char* action = strtok(rule, " ");
        char* protocol = strtok(NULL, " ");
        char* sourceIP = strtok(NULL, " ");
        char* destinationIP = strtok(NULL, " ");

        if (strcmp(action, "ALLOW") == 0) {
            if (strcmp(protocol, "TCP") == 0 && strcmp(sourceIP, packet) == 0) {
                printf("\nPacket allowed by rule: %s\n", temp->rule);
                return 1;
            }
        } else if (strcmp(action, "BLOCK") == 0) {
            if (strcmp(protocol, "UDP") == 0 && strcmp(destinationIP, packet) == 0) {
                printf("\nPacket blocked by rule: %s\n", temp->rule);
                return 0;
            }
        }
        temp = temp->next;
    }

    printf("\nNo rule matches the packet!\n");
    return 0;
}

int main() {
    printf("\nWelcome to the Firewall Program!\n");

    Node* ruleList = NULL;

    addRule(&ruleList, "ALLOW TCP 192.168.0.1 192.168.0.2");
    addRule(&ruleList, "BLOCK UDP 192.168.0.3 192.168.0.4");

    printRules(ruleList);

    char packet[15];
    strcpy(packet, "192.168.0.1");

    checkRules(ruleList, packet);

    removeRule(&ruleList, "ALLOW TCP 192.168.0.1 192.168.0.2");

    printRules(ruleList);

    return 0;
}