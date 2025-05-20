//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

#define PORT 8080
#define BUFFER_SIZE 1024

struct node {
    int sock;
    char name[50];
    char email[50];
};

struct node *nodes[10];

void init_nodes(int num_nodes) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        nodes[i] = (struct node *)malloc(sizeof(struct node));
        sprintf(nodes[i]->name, "Node %d", i);
        sprintf(nodes[i]->email, "node%d@example.com", i);
        nodes[i]->sock = socket(AF_INET, SOCK_STREAM, 0);
        if (nodes[i]->sock == -1) {
            perror("socket failed");
            exit(1);
        }
    }
}

void distribute_data(struct node **nodes, int num_nodes) {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        for (j = i + 1; j < num_nodes; j++) {
            if (i != j) {
                send(nodes[i]->sock, nodes[j]->name, strlen(nodes[j]->name), 0);
                send(nodes[i]->sock, nodes[j]->email, strlen(nodes[j]->email), 0);
            }
        }
    }
}

void process_data(struct node **nodes, int num_nodes) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        recv(nodes[i]->sock, nodes[i]->name, BUFFER_SIZE, 0);
        recv(nodes[i]->sock, nodes[i]->email, BUFFER_SIZE, 0);
        printf("%s %s\n", nodes[i]->name, nodes[i]->email);
    }
}

int main() {
    int num_nodes = 5;
    init_nodes(num_nodes);
    distribute_data(nodes, num_nodes);
    process_data(nodes, num_nodes);
    return 0;
}