//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODES 100
#define MAX_VALUE_LEN 100

struct node {
    int sock;
    char value[MAX_VALUE_LEN];
};

struct search_request {
    int sock;
    char value[MAX_VALUE_LEN];
};

void init_nodes(int num_nodes) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        struct node *node = malloc(sizeof(struct node));
        node->sock = socket(AF_INET, SOCK_STREAM, 0);
        node->value[0] = '\0';
    }
}

void distribute_search_requests(int num_nodes, char *value) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        struct search_request *req = malloc(sizeof(struct search_request));
        req->sock = socket(AF_INET, SOCK_STREAM, 0);
        req->value[0] = '\0';
        strcpy(req->value, value);
        send(req->sock, value, strlen(value), 0);
    }
}

void handle_search_response(int sock, char *value) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (sock == i) {
            printf("Found at node %d: %s\n", i, value);
            break;
        }
    }
}

int main() {
    int num_nodes = 5;
    char value[] = "Hello, world!";

    init_nodes(num_nodes);
    distribute_search_requests(num_nodes, value);

    for (int i = 0; i < num_nodes; i++) {
        recv(i, value, strlen(value), 0);
        handle_search_response(i, value);
    }

    return 0;
}