//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOST_NAME 1024
#define MAX_CONNECTIONS 1024

typedef struct {
    char hostname[MAX_HOST_NAME];
    int port;
    int sockfd;
    struct sockaddr_in server_addr;
} connection;

connection *connections = NULL;
int num_connections = 0;

void add_connection(char *hostname, int port) {
    connection *new_conn = malloc(sizeof(connection));
    strcpy(new_conn->hostname, hostname);
    new_conn->port = port;
    new_conn->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (new_conn->sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }
    memset(&new_conn->server_addr, 0, sizeof(new_conn->server_addr));
    new_conn->server_addr.sin_family = AF_INET;
    new_conn->server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &new_conn->server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Error converting hostname to IP address\n");
        exit(1);
    }
    num_connections++;
    connections = realloc(connections, sizeof(connection) * num_connections);
    connections[num_connections - 1] = *new_conn;
    free(new_conn);
}

void print_connections() {
    for (int i = 0; i < num_connections; i++) {
        printf("%s:%d\n", connections[i].hostname, connections[i].port);
    }
}

int main() {
    char hostname[MAX_HOST_NAME];
    int port;
    while (1) {
        printf("Enter hostname and port (or type 'exit' to quit): ");
        scanf("%s %d", hostname, &port);
        if (strcmp(hostname, "exit") == 0) {
            break;
        }
        add_connection(hostname, port);
    }
    print_connections();
    return 0;
}