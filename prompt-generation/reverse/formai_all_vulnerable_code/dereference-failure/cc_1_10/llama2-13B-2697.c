//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define PORT 8080

struct node {
    int port;
    char *ip;
    struct node *next;
};

struct node *head = NULL;

void add_node(char *ip, int port) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->port = port;
    new_node->ip = ip;
    new_node->next = head;
    head = new_node;
}

void del_node(char *ip) {
    struct node *current = head;
    struct node *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->ip, ip) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    char *ips[] = {"192.168.1.1", "192.168.1.2", "192.168.1.3"};
    int ports[] = {8080, 8081, 8082};
    int i, j;

    for (i = 0; i < sizeof(ips) / sizeof(ips[0]); i++) {
        for (j = 0; j < sizeof(ports) / sizeof(ports[0]); j++) {
            add_node(ips[i], ports[j]);
        }
    }

    for (i = 0; i < sizeof(ips) / sizeof(ips[0]); i++) {
        del_node(ips[i]);
    }

    return 0;
}