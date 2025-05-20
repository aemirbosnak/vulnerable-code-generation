//FormAI DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080 // port number to use

char *server_responses[] = {"Hello from server!", "How are you?", "Goodbye!"}; // possible server responses
int num_responses = 3; // number of possible server responses

void *connection_handler(void *socket_desc) {
    int sock = *(int*)socket_desc; // retrieve socket descriptor
    char client_message[1024];
    int read_size;
    
    while ((read_size = recv(sock, client_message, 1024, 0)) > 0) { // receive message from client
        printf("Client sent message: %s\n", client_message);
        int response_num = rand() % num_responses; // generate random number to select server response
        char server_response[1024];
        strcpy(server_response, server_responses[response_num]);
        write(sock, server_response, strlen(server_response)); // send response to client
    }
    
    if (read_size == 0) { // client disconnected
        printf("Client disconnected\n");
        fflush(stdout);
    }
    else if (read_size == -1) { // receive error
        printf("Receive error\n");
    }
     
    free(socket_desc); // free socket descriptor
    pthread_exit(NULL); // exit thread
}

int main(int argc, char const *argv[]) {
    srand(time(NULL)); // seed random number generator
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
      
    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
      
    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
      
    // bind socket to address and port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    // listen for connections from clients
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        printf("New client connected\n");
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = new_socket;
         
        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void*)new_sock) < 0) {
            perror("Thread creation failed");
            return 1;
        }
    }
     
    if (new_socket < 0) {
        perror("Accept failed");
        return 1;
    }
     
    return 0;
}