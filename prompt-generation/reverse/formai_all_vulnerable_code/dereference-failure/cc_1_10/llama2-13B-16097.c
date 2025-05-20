//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

struct node {
    int id;
    int port;
    char *ip;
    char *book;
};

struct dht {
    int num_nodes;
    struct node **nodes;
};

void init_dht(struct dht *dht) {
    dht->num_nodes = 0;
    dht->nodes = calloc(1, sizeof(struct node *) * 10);
}

void add_node(struct dht *dht, int id, int port, char *ip, char *book) {
    struct node *node = calloc(1, sizeof(struct node));
    node->id = id;
    node->port = port;
    node->ip = ip;
    node->book = book;
    dht->nodes[dht->num_nodes] = node;
    dht->num_nodes++;
}

void distribute_book(struct dht *dht, char *book) {
    for (int i = 0; i < dht->num_nodes; i++) {
        struct node *node = dht->nodes[i];
        sendto(node->port, book, strlen(book), 0, (struct sockaddr *)&node->ip, sizeof(node->ip));
    }
}

void retrieve_book(struct dht *dht) {
    char buffer[BUFFER_SIZE];
    for (int i = 0; i < dht->num_nodes; i++) {
        struct node *node = dht->nodes[i];
        recvfrom(node->port, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&node->ip, sizeof(node->ip));
        printf("%s", buffer);
    }
}

int main() {
    struct dht dht;
    char book[] = "The Great Gatsby";

    init_dht(&dht);
    add_node(&dht, 1, 8080, "127.0.0.1", book);
    add_node(&dht, 2, 8081, "192.168.1.1", book);
    add_node(&dht, 3, 8082, "192.168.1.2", book);

    distribute_book(&dht, book);

    retrieve_book(&dht);

    return 0;
}