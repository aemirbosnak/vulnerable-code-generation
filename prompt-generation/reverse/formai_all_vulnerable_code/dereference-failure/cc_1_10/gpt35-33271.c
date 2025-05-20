//FormAI DATASET v1.0 Category: Networking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
    int server_fd, new_socket;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(server_address);
    char buffer[1024] = {0};
    char detective_name[30] = {0};
    char message[] = "Enter the name of the detective you want to contact: ";
    char received_message[1024];
    char response[] = "Thank you, I'll connect you shortly.";

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error: Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Set server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    // Bind socket to server address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("Error: Socket bind failed.\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Error: Listen failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connection...\n");

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&server_address, (socklen_t*)&addrlen))<0) {
        perror("Error: Accept connection failed.\n");
        exit(EXIT_FAILURE);
    }

    // Prompt user to enter detective's name
    send(new_socket, message, strlen(message), 0);
    read(new_socket, detective_name, 30);
    printf("Incoming message from %s: ", detective_name);

    // Receive message from detective
    memset(buffer, 0, sizeof(buffer));
    read(new_socket, buffer, 1024);
    strcpy(received_message, buffer);
    printf("%s\n", received_message);

    // Send response to detective
    send(new_socket, response, strlen(response), 0);
    printf("Response sent.\n");

    close(new_socket);
    close(server_fd);
    return 0;
}