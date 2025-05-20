//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if(argc != 4){
        printf("Error: Usage %s <server address> <server port> <resource>\n", argv[0]);
        exit(-1);
    }
    printf("Building HTTP client to access %s:%s/%s\n", argv[1], argv[2], argv[3]);

    // Create a socket for communication with the server
    printf("\nCreating a socket for communication with the server...\n");
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket == -1){
        printf("Error: Unable to create a socket.\n");
        exit(-1);
    }

    // Set server address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    printf("Connecting to server...\n");
    int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if(connection_status == -1){
        printf("Error: Unable to connect to server.\n");
        exit(-1);
    }

    // Send HTTP request to server
    printf("Sending HTTP request to server...\n");
    char *message;
    message = malloc(1024);
    if(message == NULL){
        printf("Error: Unable to allocate memory for request.\n");
        exit(-1);
    }
    memset(message, 0, sizeof(char) * 1024);
    sprintf(message, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", argv[3], argv[1]);
    int bytes_sent = send(client_socket, message, strlen(message), 0);
    if(bytes_sent == -1){
        printf("Error: Unable to send request to server.\n");
        exit(-1);
    }

    // Receive HTTP response from server
    printf("Receiving HTTP response from server...\n");
    char *response;
    response = malloc(1024);
    if(response == NULL){
        printf("Error: Unable to allocate memory for response.\n");
        exit(-1);
    }
    memset(response, 0, sizeof(char) * 1024);
    int bytes_received = recv(client_socket, response, 1024, 0);
    if(bytes_received == -1){
        printf("Error: Unable to receive response from server.\n");
        exit(-1);
    }

    // Print HTTP response from server
    printf("Response from server:\n");
    printf("%s", response);

    // Close socket and free memory
    printf("\nClosing socket and freeing memory...\n");
    free(message);
    free(response);
    close(client_socket);

    return 0;
}