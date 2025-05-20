//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_IP_LENGTH 15
#define MAX_LOG_LENGTH 100

typedef struct Node {
    char ip[MAX_IP_LENGTH + 1];
    int count;
    struct Node *next;
} Node;

Node *head = NULL;

bool is_ip_valid(const char *ip) {
    int a, b, c, d;
    return sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d) == 4;
}

void insert_ip(char *ip) {
    if (head == NULL) {
        head = (Node *) malloc(sizeof(Node));
        strcpy(head->ip, ip);
        head->count = 1;
        head->next = NULL;
    } else {
        Node *temp = head;
        while (temp != NULL) {
            if (strcmp(temp->ip, ip) == 0) {
                temp->count++;
                return;
            }
            temp = temp->next;
        }
        Node *new_node = (Node *) malloc(sizeof(Node));
        strcpy(new_node->ip, ip);
        new_node->count = 1;
        new_node->next = head;
        head = new_node;
    }
}

void print_ips() {
    Node *temp = head;
    while (temp != NULL) {
        printf("IP: %s, Count: %d\n", temp->ip, temp->count);
        temp = temp->next;
    }
}

int main() {
    char log[MAX_LOG_LENGTH + 1];
    printf("Enter log: ");
    fgets(log, sizeof(log), stdin);
    char *ip = strtok(log, " ");
    while (ip != NULL) {
        if (is_ip_valid(ip)) {
            insert_ip(ip);
        }
        ip = strtok(NULL, " ");
    }
    print_ips();
    return 0;
}