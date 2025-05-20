//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

// Custom data structure to hold client information
typedef struct client_info {
    int sockfd;
    char name[256];
} client_info;

// Create a client and connect to the server
client_info* create_client(char* ip, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR: Socket creation failed");
        exit(1);
    }

    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: Connection failed");
        exit(1);
    }

    // Allocate memory for client info
    client_info* client = (client_info*) malloc(sizeof(client_info));

    // Store the socket and name
    client->sockfd = sockfd;
    strcpy(client->name, "");

    return client;
}

// Receive messages from the server and display them
void* receive_messages(void* arg) {
    client_info* client = (client_info*) arg;
    char buffer[256];

    // Loop to receive messages
    while (1) {
        memset(buffer, 0, sizeof(buffer));

        // Receive a message
        if (recv(client->sockfd, buffer, sizeof(buffer), 0) > 0) {
            printf("%s", buffer);
        } else {
            perror("ERROR: Message reception failed");
            close(client->sockfd);
            pthread_exit(NULL);
        }
    }
}

// Send messages to the server
void send_messages(client_info* client) {
    char buffer[256];

    // Loop to send messages
    while (1) {
        memset(buffer, 0, sizeof(buffer));

        // Get the message from the user
        fgets(buffer, sizeof(buffer), stdin);

        // Send the message to the server
        if (send(client->sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("ERROR: Message transmission failed");
            close(client->sockfd);
            pthread_exit(NULL);
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    // Create a client and connect to the server
    client_info* client = create_client(argv[1], atoi(argv[2]));

    // Create a thread to receive messages from the server
    pthread_t receive_thread;
    pthread_create(&receive_thread, NULL, receive_messages, (void*) client);

    // Send messages to the server
    send_messages(client);

    // Wait for the receive thread to finish
    pthread_join(receive_thread, NULL);

    // Close the client socket
    close(client->sockfd);

    return 0;
}