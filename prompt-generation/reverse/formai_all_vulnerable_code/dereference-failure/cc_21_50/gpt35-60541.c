//FormAI DATASET v1.0 Category: Chat server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/time.h>

#define SERVER_PORT 8888
#define MAX_CLIENTS 30
#define BUFFER_SIZE 1024

int main() {
    int server_socket, opt = 1, activity, addrlen, new_socket, valread, sd;
    int max_sd, client_socket[MAX_CLIENTS] = {0};

    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];
    fd_set server_readfds;

    memset(&server_addr, 0, sizeof(server_addr));

    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Server socket creation failed");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) != 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Server socket bind failed");
        exit(EXIT_FAILURE);
    }

    if(listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Server socket listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", SERVER_PORT);

    while(1) {
        FD_ZERO(&server_readfds);

        FD_SET(server_socket, &server_readfds);
        max_sd = server_socket;

        for(int i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i];

            if(sd > 0) {
                FD_SET(sd, &server_readfds);
            }

            if(sd > max_sd) {
                max_sd = sd;
            }
        }

        activity = select(max_sd + 1, &server_readfds, NULL, NULL, NULL);

        if(activity < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        if(FD_ISSET(server_socket, &server_readfds)) {
            if((new_socket = accept(server_socket, (struct sockaddr *)&server_addr, (socklen_t *)&addrlen)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            printf("New connection, socket fd is %d, IP is : %s, port : %d\n", new_socket, inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

            for(int i = 0; i < MAX_CLIENTS; i++) {
                if(client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    printf("Add new client at index %d\n", i);

                    break;
                }
            }
        }

        for(int i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i];

            if(FD_ISSET(sd, &server_readfds)) {
                if((valread = read(sd, buffer, BUFFER_SIZE)) == 0) {
                    getpeername(sd, (struct sockaddr *)&server_addr, (socklen_t *)&addrlen);
                    printf("Host disconnected, socket fd %d, IP %s, port %d\n", sd, inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

                    close(sd);
                    client_socket[i] = 0;
                } else {
                    buffer[valread] = '\0';
                    printf("Message from client %d: %s\n", i, buffer);

                    for(int j = 0; j < MAX_CLIENTS; j++) {
                        if(client_socket[j] > 0 && j != i) {
                            if(send(client_socket[j], buffer, strlen(buffer), 0) != strlen(buffer)) {
                                perror("Failed to send message to client");
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}