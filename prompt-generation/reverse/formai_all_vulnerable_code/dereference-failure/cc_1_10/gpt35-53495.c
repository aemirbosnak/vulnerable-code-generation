//FormAI DATASET v1.0 Category: Client Server Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 5

/* Struct to hold client information */
struct client_info {
    int sock_fd;
    struct sockaddr_in client_addr;
};

/* Array of client_info structs */
struct client_info clients[MAX_CLIENTS];

/* Function to handle client connections */
void *client_handler(void *arg) {
    int sock_fd = *((int *) arg);
    char buffer[1024];
    int read_size;

    memset(buffer, 0, sizeof(buffer));

    while((read_size = recv(sock_fd, buffer, sizeof(buffer), 0)) > 0) {
        /* Echo received message back to client */
        send(sock_fd, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
    }

    if(read_size == 0) {
        /* Client disconnected */
        printf("Client disconnected\n");
    }
    else {
        perror("recv failed");
    }

    /* Free the socket pointer */
    free(arg);

    return NULL;
}

int main(int argc, char *argv[]) {
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t thread_id;
    int *client_sock_fd;

    /* Initialize server socket */
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(listen_fd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    /* Set socket options */
    int opt = 1;
    if(setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    /* Bind to port 8080 */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if(bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    /* Listen for incoming connections */
    if(listen(listen_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 8080\n");

    /* Accept incoming connections */
    for(int i = 0; i < MAX_CLIENTS; i++) {
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);

        if(client_fd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        /* Add client information to clients array */
        clients[i].sock_fd = client_fd;
        memcpy(&clients[i].client_addr, &client_addr, sizeof(client_addr));

        /* Create new thread to handle client */
        client_sock_fd = malloc(sizeof(int));
        *client_sock_fd = client_fd;
        if(pthread_create(&thread_id, NULL, client_handler, (void *)client_sock_fd) < 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }

    /* Close all client sockets */
    for(int i = 0; i < MAX_CLIENTS; i++) {
        close(clients[i].sock_fd);
    }

    /* Close server socket */
    close(listen_fd);

    return 0;
}