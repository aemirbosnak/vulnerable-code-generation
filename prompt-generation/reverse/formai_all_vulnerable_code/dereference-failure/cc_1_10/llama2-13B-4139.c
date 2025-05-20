//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <unistd.h>

#define PORT 8080

struct node {
    int sock;
    char *name;
    char *ip;
};

struct db {
    struct node *nodes;
    int num_nodes;
};

void init_db(struct db *db) {
    db->nodes = (struct node *)calloc(1, sizeof(struct node));
    db->num_nodes = 1;
}

void add_node(struct db *db, char *name, char *ip) {
    struct node *new_node = (struct node *)calloc(1, sizeof(struct node));
    new_node->name = name;
    new_node->ip = ip;
    new_node->sock = socket(AF_INET, SOCK_STREAM, 0);
    connect(new_node->sock, (struct sockaddr *)&new_node->ip, sizeof(struct sockaddr_in));
    db->nodes = realloc(db->nodes, (db->num_nodes + 1) * sizeof(struct node));
    db->nodes[db->num_nodes] = *new_node;
    db->num_nodes++;
}

void del_node(struct db *db, char *name) {
    int i;
    for (i = 0; i < db->num_nodes; i++) {
        if (strcmp(db->nodes[i].name, name) == 0) {
            break;
        }
    }
    if (i != db->num_nodes) {
        struct node *del_node = &db->nodes[i];
        close(del_node->sock);
        free(del_node);
        db->num_nodes--;
    }
}

void put(struct db *db, char *key, char *value) {
    int i;
    for (i = 0; i < db->num_nodes; i++) {
        struct node *node = &db->nodes[i];
        send(node->sock, key, strlen(key), 0);
        send(node->sock, value, strlen(value), 0);
    }
}

char *get(struct db *db, char *key) {
    char buffer[1024];
    int i;
    for (i = 0; i < db->num_nodes; i++) {
        struct node *node = &db->nodes[i];
        recv(node->sock, buffer, 1024, 0);
        if (strcmp(buffer, key) == 0) {
            return buffer;
        }
    }
    return NULL;
}

int main() {
    struct db db;
    init_db(&db);

    char *node1_ip = "127.0.0.1";
    char *node1_name = "Node1";
    add_node(&db, node1_name, node1_ip);

    char *node2_ip = "127.0.0.2";
    char *node2_name = "Node2";
    add_node(&db, node2_name, node2_ip);

    put(&db, "key1", "value1");
    put(&db, "key2", "value2");

    char *value = get(&db, "key1");
    if (value != NULL) {
        printf("Value of key1: %s\n", value);
    }

    del_node(&db, node1_name);

    value = get(&db, "key1");
    if (value != NULL) {
        printf("Value of key1 after del: %s\n", value);
    }

    return 0;
}