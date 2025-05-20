//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_CONNECTIONS 10

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} connection;

connection connections[MAX_CONNECTIONS];
int num_connections = 0;

void add_connection(int sockfd, struct sockaddr_in addr) {
    if (num_connections >= MAX_CONNECTIONS) {
        printf("Error: too many connections\n");
        return;
    }
    connections[num_connections].sockfd = sockfd;
    connections[num_connections].addr = addr;
    num_connections++;
}

void remove_connection(int sockfd) {
    int i;
    for (i = 0; i < num_connections; i++) {
        if (connections[i].sockfd == sockfd) {
            connections[i] = connections[num_connections - 1];
            num_connections--;
            return;
        }
    }
}

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int i;

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: could not bind socket to address\n");
        return 1;
    }

    if (listen(sockfd, MAX_CONNECTIONS) < 0) {
        printf("Error: could not listen on socket\n");
        return 1;
    }

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            printf("Error: could not accept connection\n");
            continue;
        }

        add_connection(newsockfd, cli_addr);

        for (i = 0; i < num_connections; i++) {
            char buffer[256];
            int n;
            n = recv(connections[i].sockfd, buffer, sizeof(buffer), 0);
            if (n < 0) {
                printf("Error: could not receive data from connection\n");
                remove_connection(connections[i].sockfd);
                continue;
            }

            if (n == 0) {
                printf("Error: connection closed by client\n");
                remove_connection(connections[i].sockfd);
                continue;
            }

            printf("Received data from connection: %s\n", buffer);

            n = send(connections[i].sockfd, buffer, n, 0);
            if (n < 0) {
                printf("Error: could not send data to connection\n");
                remove_connection(connections[i].sockfd);
                continue;
            }
        }
    }

    return 0;
}