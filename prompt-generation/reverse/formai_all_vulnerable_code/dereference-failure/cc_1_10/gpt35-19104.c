//FormAI DATASET v1.0 Category: Chat server ; Style: random
// This C chat server program creates a room and allows clients to chat with each other
// using a simple TCP connection and select() function for handling multiple clients.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFSIZE 1024

typedef struct {
    int clients[MAX_CLIENTS];
    fd_set read_fds;
    int server_fd, max_fd;
    struct sockaddr_in address;
} Chatroom;

// Initializes the chatroom data structure and creates a server socket.
void init_chatroom(Chatroom *room, int port) {
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        room->clients[i] = -1;
    }
    room->max_fd = 0;
    FD_ZERO(&room->read_fds);

    if ((room->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(room->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    room->address.sin_family = AF_INET;
    room->address.sin_addr.s_addr = INADDR_ANY;
    room->address.sin_port = htons(port);

    if (bind(room->server_fd, (struct sockaddr *)&room->address, sizeof(room->address)) < 0) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    if (listen(room->server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    FD_SET(room->server_fd, &room->read_fds);
    room->max_fd = room->server_fd;
}

// Accepts a new client connection and adds it to the array of clients.
void accept_client(Chatroom *room) {
    int new_socket;
    struct sockaddr_in client_addr;
    int addr_len = sizeof(client_addr);

    if ((new_socket = accept(room->server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("New connection from %s:%d, socket fd %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), new_socket);

    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (room->clients[i] == -1) {
            room->clients[i] = new_socket;
            break;
        }
    }

    FD_SET(new_socket, &room->read_fds);
    if (new_socket > room->max_fd) {
        room->max_fd = new_socket;
    }
}

// Removes a client from the array of clients and closes its socket.
void remove_client(Chatroom *room, int client_fd) {
    close(client_fd);

    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (room->clients[i] == client_fd) {
            room->clients[i] = -1;
            break;
        }
    }

    FD_CLR(client_fd, &room->read_fds);
}

// Sends a chat message to all clients except the sender.
void broadcast_message(Chatroom *room, int sender_fd, char *message) {
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        int client_fd = room->clients[i];
        if (client_fd > 0 && client_fd != sender_fd) {
            if (send(client_fd, message, strlen(message) + 1, 0) < 0) {
                perror("send");
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: chat_server <port>\n");
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    Chatroom room;
    init_chatroom(&room, port);

    printf("Chat room listening on port %d...\n", port);

    while (1) {
        fd_set temp_fds = room.read_fds;
        if (select(room.max_fd + 1, &temp_fds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        int i;
        for (i = 0; i <= room.max_fd; i++) {
            if (FD_ISSET(i, &temp_fds)) {
                if (i == room.server_fd) {
                    accept_client(&room);
                } else {
                    char buf[BUFSIZE];
                    int recv_len = 0;
                    if ((recv_len = recv(i, buf, BUFSIZE, 0)) <= 0) {
                        if (recv_len == 0) {
                            printf("Client closed connection, socket fd %d\n", i);
                        } else {
                            perror("recv");
                        }
                        remove_client(&room, i);
                    } else {
                        buf[recv_len] = '\0';
                        printf("Received message: %s", buf);
                        broadcast_message(&room, i, buf);
                    }
                }
            }
        }
    }

    return 0;
}