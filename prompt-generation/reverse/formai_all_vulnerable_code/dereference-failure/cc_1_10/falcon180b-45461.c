//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BACKLOG 5
#define TRUE 1
#define FALSE 0
#define ERR_EXIT(m) { perror(m); exit(EXIT_FAILURE); }

typedef struct {
    int socket;
    struct sockaddr_in address;
    char name[100];
    int namelen;
} client;

void *thread(void *param) {
    client *c = (client *) param;
    char buffer[1024];
    bzero(buffer, 1024);
    while(TRUE) {
        recv(c->socket, buffer, 1024, 0);
        printf("Received message from %s: %s\n", inet_ntoa(c->address.sin_addr), buffer);
        send(c->socket, buffer, strlen(buffer), 0);
    }
    close(c->socket);
    return NULL;
}

int main() {
    int opt = TRUE;
    int master_socket, new_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    bzero(buffer, 1024);

    master_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(master_socket == -1) {
        ERR_EXIT("socket failed");
    }

    if(setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        ERR_EXIT("setsockopt");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        ERR_EXIT("bind failed");
    }

    if(listen(master_socket, BACKLOG) < 0) {
        ERR_EXIT("listen");
    }

    while(TRUE) {
        addrlen = sizeof(client_addr);
        new_socket = accept(master_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if(new_socket == -1) {
            ERR_EXIT("accept");
        }

        bzero(buffer, 1024);
        sprintf(buffer, "New connection from %s\n", inet_ntoa(client_addr.sin_addr));
        printf(buffer);

        client *c = (client *) malloc(sizeof(client));
        c->socket = new_socket;
        c->address = client_addr;
        strcpy(c->name, inet_ntoa(client_addr.sin_addr));
        c->namelen = strlen(c->name);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread, (void *) c);
    }

    close(master_socket);
    return 0;
}