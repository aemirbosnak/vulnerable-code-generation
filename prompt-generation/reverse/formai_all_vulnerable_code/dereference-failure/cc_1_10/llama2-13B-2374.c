//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_VALUE_LEN 100
#define PORT 8080

struct node {
    int id;
    int sock;
    char value[MAX_VALUE_LEN];
};

struct search_req {
    int id;
    char value[MAX_VALUE_LEN];
};

struct search_res {
    int id;
    int found;
    char value[MAX_VALUE_LEN];
};

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct node *nodes;
    struct search_req *req;
    struct search_res *res;
    int node_count = 0;

    // Initialize the nodes
    nodes = (struct node *)calloc(MAX_NODES, sizeof(struct node));
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i].id = i;
        nodes[i].sock = socket(AF_INET, SOCK_STREAM, 0);
        connect(nodes[i].sock, (struct sockaddr *)&nodes[i].id, sizeof(nodes[i].id));
    }

    // Start the search
    req = (struct search_req *)calloc(1, sizeof(struct search_req));
    res = (struct search_res *)calloc(MAX_NODES, sizeof(struct search_res));
    req->id = 0;
    req->value[0] = 'x';

    // Distributed search
    for (int i = 0; i < MAX_NODES; i++) {
        // Send the search request to the next node
        send(nodes[i].sock, req, sizeof(struct search_req), 0);

        // Receive the response from the next node
        recv(nodes[i].sock, res, sizeof(struct search_res), 0);

        // Update the search result
        if (res->found) {
            printf("Found the value %s on node %d\n", res->value, res->id);
            break;
        }
    }

    // Clean up
    for (int i = 0; i < MAX_NODES; i++) {
        close(nodes[i].sock);
    }
    free(nodes);
    free(req);
    free(res);

    return 0;
}

void send_req(int sock, struct search_req *req) {
    int len = sizeof(struct search_req);
    send(sock, req, len, 0);
}

void recv_res(int sock, struct search_res *res) {
    int len = sizeof(struct search_res);
    recv(sock, res, len, 0);
}