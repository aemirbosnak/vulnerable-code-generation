//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080

typedef struct node {
    int value;
    struct node *next;
} node_t;

typedef struct peer {
    int sock;
    node_t *head;
} peer_t;

void init_peers(int num_peers) {
    int i;
    for (i = 0; i < num_peers; i++) {
        peer_t *p = malloc(sizeof(peer_t));
        p->sock = socket(AF_INET, SOCK_STREAM, 0);
        p->head = NULL;
        // Initialize peer's address
        struct sockaddr_in server_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(PORT),
            .sin_addr.s_addr = INADDR_ANY
        };
        bind(p->sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
        listen(p->sock, 10);
        printf("Peer %d listening on port %d\n", i, PORT);
    }
}

void search_distributed(int num_peers, int target) {
    int i, j;
    node_t *found = NULL;
    peer_t *peers[num_peers];

    // Initialize peers
    init_peers(num_peers);

    // Broadcast search request to all peers
    for (i = 0; i < num_peers; i++) {
        struct sockaddr_in client_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(PORT),
            .sin_addr.s_addr = INADDR_ANY
        };
        connect(peers[i]->sock, (struct sockaddr *)&client_addr, sizeof(client_addr));
        send(peers[i]->sock, &target, sizeof(int), 0);
    }

    // Receive responses from peers
    for (i = 0; i < num_peers; i++) {
        recv(peers[i]->sock, &found, sizeof(node_t*), 0);
        if (found != NULL) {
            // Found node found in peer i
            break;
        }
    }

    // Combine found nodes from all peers
    for (j = 0; j < i; j++) {
        node_t *cur = found;
        found = NULL;
        while (cur != NULL) {
            found = cur->next;
            cur->next = found;
            cur = found;
        }
    }

    // Print found node
    if (found != NULL) {
        printf("Found node: %d\n", found->value);
    } else {
        printf("Not found\n");
    }

    // Clean up peers
    for (i = 0; i < num_peers; i++) {
        close(peers[i]->sock);
        free(peers[i]);
    }
}

int main() {
    int num_peers = 5;
    int target = 1234;

    search_distributed(num_peers, target);

    return 0;
}