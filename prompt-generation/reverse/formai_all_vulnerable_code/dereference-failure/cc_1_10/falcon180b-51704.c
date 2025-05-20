//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"

typedef struct {
    int sockfd;
    struct sockaddr_in server_addr;
} client_t;

void* monitor_thread(void* arg) {
    client_t* client = (client_t*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(client->sockfd, buffer, BUFFER_SIZE, 0);

        if(bytes_received <= 0) {
            break;
        }

        printf("Received: %s\n", buffer);
    }

    close(client->sockfd);
    free(client);
}

int create_socket() {
    int sockfd;

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

int connect_to_server(int sockfd, const char* server_addr, int port) {
    struct hostent* server;
    struct sockaddr_in server_addr_in;

    if((server = gethostbyname(server_addr)) == NULL) {
        fprintf(stderr, "no such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr_in, 0, sizeof(server_addr_in));
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_port = htons(port);
    server_addr_in.sin_addr = *(struct in_addr*)server->h_addr;

    if(connect(sockfd, (struct sockaddr*)&server_addr_in, sizeof(server_addr_in)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

int main() {
    int sockfd;
    client_t* client;
    pthread_t thread_id;

    if((sockfd = create_socket()) == -1) {
        exit(EXIT_FAILURE);
    }

    if((client = (client_t*)malloc(sizeof(client_t))) == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }

    client->sockfd = sockfd;

    if(connect_to_server(sockfd, SERVER_ADDR, SERVER_PORT) == -1) {
        exit(EXIT_FAILURE);
    }

    if(pthread_create(&thread_id, NULL, monitor_thread, (void*)client)!= 0) {
        fprintf(stderr, "pthread_create failed\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int bytes_sent;

    while(1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

        if(bytes_sent <= 0) {
            break;
        }
    }

    close(sockfd);

    return 0;
}