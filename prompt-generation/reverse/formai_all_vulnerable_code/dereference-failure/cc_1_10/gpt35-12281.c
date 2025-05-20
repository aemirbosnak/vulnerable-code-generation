//FormAI DATASET v1.0 Category: Firewall ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKED_IP_FILE "blocked_ips.txt"

#define MAX_IP_LEN 16

struct node {
    char ip[MAX_IP_LEN];
    struct node* next;
};

typedef struct node Node;

void print_list(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%s\n", current->ip);
        current = current->next;
    }
}

int is_blocked(Node* head, char* ip) {
    Node* current = head;
    while(current != NULL) {
        if(strcmp(current->ip, ip) == 0) {
            return 1; // IP is blocked, return true
        }
        current = current->next;
    }
    return 0; // IP is not blocked, return false
}

void add_blocked_ip(Node** head, char* ip) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->ip, ip);
    new_node->next = *head;
    *head = new_node;
}

void load_blocked_ips(Node** head) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(BLOCKED_IP_FILE, "r");
    if(fp == NULL) {
        printf("Error opening blocked IPs file\n");
        return;
    }

    while((read = getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\n")] = 0; // Remove trailing newline character
        add_blocked_ip(head, line);
    }

    fclose(fp);
    if(line) {
        free(line);
    }
}

void block_ip(Node** head, char* ip) {
    add_blocked_ip(head, ip);
    FILE* fp = fopen(BLOCKED_IP_FILE, "a");
    if(fp == NULL) {
        printf("Error opening blocked IPs file\n");
        return;
    }
    fprintf(fp, "%s\n", ip);
    fclose(fp);
}

int main() {
    Node* blocked_ips = NULL;
    load_blocked_ips(&blocked_ips);
    printf("Blocked IPs:\n");
    print_list(blocked_ips);

    char ip1[MAX_IP_LEN] = "192.168.1.100";
    if(is_blocked(blocked_ips, ip1)) {
        printf("%s is blocked\n", ip1);
    } else {
        printf("%s is not blocked\n", ip1);
        block_ip(&blocked_ips, ip1);
        printf("%s is now blocked\n", ip1);
        printf("Updated Blocked IPs:\n");
        print_list(blocked_ips);
    }

    char ip2[MAX_IP_LEN] = "10.0.0.1";
    if(is_blocked(blocked_ips, ip2)) {
        printf("%s is blocked\n", ip2);
    } else {
        printf("%s is not blocked\n", ip2);
        block_ip(&blocked_ips, ip2);
        printf("%s is now blocked\n", ip2);
        printf("Updated Blocked IPs:\n");
        print_list(blocked_ips);
    }

    return 0;
}