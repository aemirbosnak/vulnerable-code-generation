//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_ADDR 256
#define MAX_LOG_ENTRIES 1000

struct log_entry {
    char ip_address[MAX_IP_ADDR];
    char timestamp[20];
    char message[100];
};

struct node {
    struct log_entry log_entry;
    struct node *next;
};

struct node *create_node(struct log_entry log_entry) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->log_entry = log_entry;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node **head, struct log_entry log_entry) {
    struct node *new_node = create_node(log_entry);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void print_log_entries(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%s %s %s\n", current_node->log_entry.ip_address,
                             current_node->log_entry.timestamp,
                             current_node->log_entry.message);
        current_node = current_node->next;
    }
}

int main() {
    char ip_address[MAX_IP_ADDR];
    char timestamp[20];
    char message[100];
    struct node *log_entries = NULL;

    int i;
    for (i = 0; i < MAX_LOG_ENTRIES; i++) {
        printf("Enter IP address, timestamp, and message for log entry %d:\n", i+1);
        scanf("%s %s %[^\n]s", ip_address, timestamp, message);
        struct log_entry log_entry;
        strcpy(log_entry.ip_address, ip_address);
        strcpy(log_entry.timestamp, timestamp);
        strcpy(log_entry.message, message);
        insert_node(&log_entries, log_entry);
    }

    printf("\nAll log entries:\n");
    print_log_entries(log_entries);

    return 0;
}