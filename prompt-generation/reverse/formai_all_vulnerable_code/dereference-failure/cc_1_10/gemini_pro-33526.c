//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10

typedef struct {
    int fd;
    struct sockaddr_in addr;
    char name[32];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(char *msg) {
    for (int i = 0; i < num_clients; i++) {
        send(clients[i].fd, msg, strlen(msg), 0);
    }
}

void handle_client(int fd) {
    char buf[256];
    int n;

    while ((n = recv(fd, buf, sizeof(buf) - 1, 0)) > 0) {
        buf[n] = '\0';

        if (strncmp(buf, "JOIN", 4) == 0) {
            // New client joining
            char *name = buf + 5;
            if (strlen(name) >= sizeof(clients[num_clients].name)) {
                send(fd, "ERR: Name too long", sizeof("ERR: Name too long"), 0);
                close(fd);
                return;
            }

            strcpy(clients[num_clients].name, name);
            clients[num_clients].fd = fd;
            clients[num_clients].addr = *((struct sockaddr_in *)&fd);
            num_clients++;

            broadcast(buf);
        } else if (strncmp(buf, "MOVE", 4) == 0) {
            // Client sending a move command
            broadcast(buf);
        } else if (strncmp(buf, "QUIT", 4) == 0) {
            // Client quitting
            char msg[64];
            sprintf(msg, "QUIT:%s", clients[fd].name);
            broadcast(msg);

            for (int i = 0; i < num_clients; i++) {
                if (clients[i].fd == fd) {
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    break;
                }
            }

            close(fd);
        } else {
            // Unknown command
            send(fd, "ERR: Unknown command", sizeof("ERR: Unknown command"), 0);
        }
    }

    if (n == 0) {
        // Client disconnected
        char msg[64];
        sprintf(msg, "QUIT:%s", clients[fd].name);
        broadcast(msg);

        for (int i = 0; i < num_clients; i++) {
            if (clients[i].fd == fd) {
                clients[i] = clients[num_clients - 1];
                num_clients--;
                break;
            }
        }

        close(fd);
    }
}

int main(int argc, char **argv) {
    int sockfd, newsockfd;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, MAX_CLIENTS);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            continue;
        }

        printf("New client connected from %s\n", inet_ntoa(cli_addr.sin_addr));

        if (num_clients >= MAX_CLIENTS) {
            // Too many clients connected
            send(newsockfd, "ERR: Too many clients connected", sizeof("ERR: Too many clients connected"), 0);
            close(newsockfd);
        } else {
            // Add new client to list
            clients[num_clients].fd = newsockfd;
            clients[num_clients].addr = cli_addr;
            num_clients++;

            char msg[64];
            sprintf(msg, "JOIN:%s", clients[num_clients - 1].name);
            broadcast(msg);

            handle_client(newsockfd);
        }
    }

    close(sockfd);

    return 0;
}