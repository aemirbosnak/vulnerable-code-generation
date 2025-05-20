//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 1234

typedef struct node {
    int value;
    struct node *next;
} node_t;

typedef struct peer {
    int sock;
    node_t *head;
} peer_t;

void init_peer(peer_t *peer) {
    peer->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (peer->sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
}

void search_value(int value, peer_t *peer) {
    node_t *current = peer->head;
    while (current != NULL) {
        if (current->value == value) {
            printf("Found value %d at %p\n", value, current);
            return;
        }
        current = current->next;
    }
    printf("Value not found\n");
}

void send_value(int value, int sock) {
    struct packet {
        int value;
    } packet;
    packet.value = value;
    send(sock, &packet, sizeof(packet), 0);
}

void recv_value(int sock) {
    struct packet {
        int value;
    } packet;
    recv(sock, &packet, sizeof(packet), 0);
    printf("Received value %d from %p\n", packet.value, sock);
}

int main(int argc, char **argv) {
    peer_t *peer = malloc(sizeof(peer_t));
    init_peer(peer);

    // Start search
    search_value(5, peer);

    // Start listening for incoming connections
    listen(peer->sock, 3);

    while (1) {
        // Accept incoming connections
        int sock = accept(peer->sock, NULL, NULL);
        recv_value(sock);
        close(sock);
    }

    return 0;
}