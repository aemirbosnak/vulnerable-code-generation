//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define BACKLOG 10

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int create_socket(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket failed");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error("bind failed");
    }

    if (listen(sockfd, BACKLOG) == -1) {
        error("listen failed");
    }
    return sockfd;
}

void* handle_request(void* arg) {
    int client_socket = *(int*)arg;
    char buffer[MAX_LINE];
    while (fgets(buffer, MAX_LINE, stdin)!= NULL) {
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int server_socket = create_socket(port);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            error("accept failed");
        }
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_request, (void*)&client_socket)!= 0) {
            error("pthread_create failed");
        }
    }
    return 0;
}