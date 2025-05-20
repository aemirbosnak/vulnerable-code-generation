//GEMINI-pro DATASET v1.0 Category: Poker Game ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <poll.h>
#include <fcntl.h>

#define PORT 8888
#define MAX_CLIENTS 10

struct client {
    int fd;
    struct sockaddr_in addr;
    char buf[1024];
    int buf_len;
    int hand[5];
    int hand_size;
    int bet;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

int main() {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int i, j;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, MAX_CLIENTS);

    struct pollfd fds[MAX_CLIENTS + 1];
    fds[0].fd = sockfd;
    fds[0].events = POLLIN;
    for (i = 1; i < MAX_CLIENTS + 1; i++) {
        fds[i].fd = -1;
        fds[i].events = 0;
    }

    while (1) {
        int nfds = poll(fds, MAX_CLIENTS + 1, -1);
        if (nfds < 0) {
            perror("poll");
            continue;
        }

        if (fds[0].revents & POLLIN) {
            clilen = sizeof(cli_addr);
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (newsockfd < 0) {
                perror("accept");
                continue;
            }

            int flags = fcntl(newsockfd, F_GETFL, 0);
            fcntl(newsockfd, F_SETFL, flags | O_NONBLOCK);

            for (i = 1; i < MAX_CLIENTS + 1; i++) {
                if (fds[i].fd == -1) {
                    fds[i].fd = newsockfd;
                    fds[i].events = POLLIN;
                    break;
                }
            }

            if (i == MAX_CLIENTS + 1) {
                close(newsockfd);
            }

            printf("New client connected: %s\n", inet_ntoa(cli_addr.sin_addr));
        }

        for (i = 1; i < MAX_CLIENTS + 1; i++) {
            if (fds[i].fd == -1) {
                continue;
            }

            if (fds[i].revents & POLLIN) {
                clients[i].buf_len = read(fds[i].fd, clients[i].buf, sizeof(clients[i].buf) - 1);
                if (clients[i].buf_len < 0) {
                    perror("read");
                    close(fds[i].fd);
                    fds[i].fd = -1;
                    fds[i].events = 0;
                    continue;
                }
                clients[i].buf[clients[i].buf_len] = '\0';

                printf("Client %d: %s\n", i, clients[i].buf);

                if (strcmp(clients[i].buf, "join") == 0) {
                    num_clients++;
                    clients[i].hand_size = 0;
                    printf("Client %d joined the game\n", i);
                }
                else if (strcmp(clients[i].buf, "leave") == 0) {
                    num_clients--;
                    printf("Client %d left the game\n", i);
                    close(fds[i].fd);
                    fds[i].fd = -1;
                    fds[i].events = 0;
                }
                else if (strcmp(clients[i].buf, "bet") == 0) {
                    int bet = atoi(&clients[i].buf[4]);
                    clients[i].bet = bet;
                    printf("Client %d bet %d\n", i, bet);
                }
                else if (strcmp(clients[i].buf, "call") == 0) {
                    int bet = 0;
                    for (j = 1; j < MAX_CLIENTS + 1; j++) {
                        if (clients[j].fd != -1) {
                            bet = clients[j].bet;
                            break;
                        }
                    }

                    clients[i].bet = bet;
                    printf("Client %d called the bet\n", i);
                }
                else if (strcmp(clients[i].buf, "fold") == 0) {
                    clients[i].hand_size = 0;
                    clients[i].bet = 0;
                    printf("Client %d folded\n", i);
                }
                else if (strcmp(clients[i].buf, "show") == 0) {
                    printf("Client %d's hand: ", i);
                    for (j = 0; j < clients[i].hand_size; j++) {
                        printf("%d ", clients[i].hand[j]);
                    }
                    printf("\n");
                }
                else {
                    printf("Unknown command from client %d: %s\n", i, clients[i].buf);
                }
            }
        }
    }

    return 0;
}