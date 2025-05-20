//FormAI DATASET v1.0 Category: Chat server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

void *connection_handler(void *);

int main(int argc, char *argv[]) {
    int server_sock, client_sock, *new_sock, c, *ip, optval = 1;
    struct sockaddr_in server, client;
    
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    if (server_sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    memset(server.sin_zero, '\0', sizeof server.sin_zero);

    if (bind(server_sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(server_sock, 3) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    while ((client_sock = accept(server_sock, (struct sockaddr *) &client, (socklen_t *) &c))) {
        puts("Connection accepted");

        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;
        ip = (int *) malloc(sizeof *ip);
        *ip = (int) inet_ntoa(client.sin_addr);

        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *) new_sock) < 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }

        printf("Handler assigned for client %d\n", *ip);
    }

    if (client_sock < 0) {
        perror("accept");
        return EXIT_FAILURE;
    }

    return 0;
}

void *connection_handler(void *socket_desc) {
    int sock = *(int *) socket_desc;
    char *message;
    long read_size;
    char client_message[4000];

    message = "Greetings! I am your essential C chat server. How may I help you today?\n";
    write(sock, message, strlen(message));

    while ((read_size = recv(sock, client_message, 4000, 0)) > 0) {
        client_message[read_size] = '\0';
        if (strcmp(client_message, "exit") == 0) {
            message = "Goodbye, happy chatting!\n";
            write(sock, message, strlen(message));
            break;
        }
        write(sock, client_message, strlen(client_message));
    }

    if (read_size == 0) {
        printf("Client %d disconnected\n", sock);
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv");
    }

    free(socket_desc);

    return 0;
}