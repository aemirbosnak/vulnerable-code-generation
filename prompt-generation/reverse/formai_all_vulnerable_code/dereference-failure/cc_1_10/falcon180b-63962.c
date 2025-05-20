//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

struct node {
    char hostname[BUF_SIZE];
    char ip[BUF_SIZE];
    struct node *next;
};

struct node *head = NULL;

void add_node(char *hostname, char *ip) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->hostname, hostname);
    strcpy(new_node->ip, ip);
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_nodes() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("Hostname: %s\n", temp->hostname);
        printf("IP Address: %s\n", temp->ip);
        printf("\n");
        temp = temp->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char hostname[BUF_SIZE];
    strcpy(hostname, argv[1]);

    struct hostent *host_info;
    if ((host_info = gethostbyname(hostname)) == NULL) {
        printf("Error: Host not found\n");
        exit(1);
    }

    char **aliases = host_info->h_aliases;
    while (*aliases!= NULL) {
        add_node(*aliases, inet_ntoa(*((struct in_addr *)host_info->h_addr)));
        aliases++;
    }

    print_nodes();

    return 0;
}