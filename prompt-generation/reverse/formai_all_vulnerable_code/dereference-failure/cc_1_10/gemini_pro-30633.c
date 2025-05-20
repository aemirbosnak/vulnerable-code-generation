//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

// Custom port number
#define PORT 8080

// Maximum buffer size
#define BUFFER_SIZE 1024

// Client-side function to send and receive data from the server
void client(char* server_ip) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(server_ip);
    int connect_status = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (connect_status < 0) {
        perror("Could not connect to server");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char message[BUFFER_SIZE];
    printf("Enter your message: ");
    fgets(message, BUFFER_SIZE, stdin);
    int send_status = send(sockfd, message, strlen(message), 0);
    if (send_status < 0) {
        perror("Could not send message");
        exit(EXIT_FAILURE);
    }

    // Receive a response from the server
    char response[BUFFER_SIZE];
    int recv_status = recv(sockfd, response, BUFFER_SIZE, 0);
    if (recv_status < 0) {
        perror("Could not receive response");
        exit(EXIT_FAILURE);
    }

    // Print the response from the server
    printf("Server response: %s", response);

    // Close the connection
    close(sockfd);
}

// Server-side function to listen for incoming connections and handle requests
void server() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the specified port
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);
    int bind_status = bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (bind_status < 0) {
        perror("Could not bind socket to port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    int listen_status = listen(sockfd, 5);
    if (listen_status < 0) {
        perror("Could not listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);
    while (1) {
        int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &addrlen);
        if (client_sockfd < 0) {
            perror("Could not accept incoming connection");
            continue;
        }

        // Handle the client request
        char message[BUFFER_SIZE];
        int recv_status = recv(client_sockfd, message, BUFFER_SIZE, 0);
        if (recv_status < 0) {
            perror("Could not receive message from client");
            close(client_sockfd);
            continue;
        }

        // Process the client request
        char response[BUFFER_SIZE];
        sprintf(response, "Hello %s! Your message has been received.", message);

        // Send a response to the client
        int send_status = send(client_sockfd, response, strlen(response), 0);
        if (send_status < 0) {
            perror("Could not send response to client");
            close(client_sockfd);
            continue;
        }

        // Close the client connection
        close(client_sockfd);
    }

    // Close the server socket
    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [server_ip]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Decide whether to run as a client or server
    if (strcmp(argv[1], "server") == 0) {
        server();
    } else if (strcmp(argv[1], "client") == 0) {
        client(argv[2]);
    } else {
        printf("Invalid argument. Please specify 'server' or 'client'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}