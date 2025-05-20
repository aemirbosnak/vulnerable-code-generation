//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

#define PORT 8080
#define MAX_REQUEST_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024
#define MAX_THREADS 10
#define BACKLOG 10

struct request {
    char *data;
    int length;
};

void *handle_request(void *arg) {
    int client_socket = *(int*)arg;
    char buffer[MAX_REQUEST_LENGTH];
    bzero(buffer, MAX_REQUEST_LENGTH);
    recv(client_socket, buffer, MAX_REQUEST_LENGTH, 0);
    struct request *request = (struct request*)malloc(sizeof(struct request));
    request->data = strdup(buffer);
    request->length = strlen(buffer);
    printf("Request received: %s\n", request->data);
    char *response = "Response to the request.";
    send(client_socket, response, strlen(response), 0);
    free(request->data);
    free(request);
    close(client_socket);
    pthread_exit(0);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }
    if(listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }
    printf("Server started on port %d\n", PORT);
    int client_socket;
    while(1) {
        client_socket = accept(server_socket, NULL, NULL);
        pthread_t thread_id;
        if(pthread_create(&thread_id, NULL, handle_request, (void*)&client_socket)!= 0) {
            printf("Error creating thread\n");
            exit(1);
        }
    }
    return 0;
}