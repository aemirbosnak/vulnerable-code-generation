//FormAI DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

void *handle_client(void *arg);

int main(int argc, char *argv[]) {
    int server_fd, new_socket, port_num;
    struct sockaddr_in address;
    int opt = 1; 
    int addrlen = sizeof(address);

    if(argc < 2) {
        printf("Usage: %s PORT_NUMBER\n", argv[0]);
        return 1;
    }

    port_num = atoi(argv[1]);

    // create server socket
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        return 1;
    }

    // set socket options
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt error");
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_num);

    // bind socket to address
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind error");
        return 1;
    }

    // start listening for incoming connections
    if(listen(server_fd, 5) < 0) {
        perror("Listen error");
        return 1;
    }

    printf("Server started on port %d...\n", port_num);

    // wait for incoming connections
    while((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        pthread_t thread_id;
        printf("New client connected\n");

        // handle incoming client on new thread
        if(pthread_create(&thread_id, NULL, handle_client, (void*)&new_socket) < 0) {
            perror("Thread creation error");
            return 1;
        }
    }

    return 0; 
}

void *handle_client(void *arg) {
    int sock = *(int*)arg;
    char buffer[1024] = {0};
    int valread;

    // send welcome message to client
    char *welcome = "Welcome to the server!\n";
    send(sock, welcome, strlen(welcome), 0);
    
    // loop to handle incoming client messages
    while((valread = read(sock, buffer, 1024)) > 0) {
        printf("Client: %s", buffer);

        // echo back client message
        send(sock, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer)); // clear buffer for next message
    }

    printf("Client disconnected\n");
    close(sock); // close connection to client
    pthread_exit(NULL);
}