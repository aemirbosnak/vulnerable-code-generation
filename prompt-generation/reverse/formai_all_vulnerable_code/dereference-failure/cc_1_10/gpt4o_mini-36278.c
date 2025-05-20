//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 1024
#define POP3_PORT 110

typedef struct {
    char *host;
    int port;
    int socketfd;
} Pop3Client;

// Function to create a socket
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to resolve hostname to IP
struct sockaddr_in resolve_hostname(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host_entry = gethostbyname(hostname);
    
    if (host_entry == NULL) {
        perror("Hostname resolution failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host_entry->h_addr, host_entry->h_length);

    return server_addr;
}

// Function to connect to POP3 server
void connect_to_server(Pop3Client *client) {
    client->socketfd = create_socket();
    struct sockaddr_in server_addr = resolve_hostname(client->host, client->port);
    
    if (connect(client->socketfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(client->socketfd);
        exit(EXIT_FAILURE);
    }
}

// Function to send command to the server
void send_command(Pop3Client *client, const char *command) {
    if (send(client->socketfd, command, strlen(command), 0) < 0) {
        perror("Send command failed");
        close(client->socketfd);
        exit(EXIT_FAILURE);
    }
}

// Function to receive response from the server
void receive_response(Pop3Client *client) {
    char buffer[MAX_BUFFER];
    int bytes_received = recv(client->socketfd, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_received < 0) {
        perror("Receive response failed");
        close(client->socketfd);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0'; // Null-terminate the response
    printf("Server Response: %s\n", buffer);
}

// Function to authenticate to POP3 server
void authenticate(Pop3Client *client, const char *username, const char *password) {
    // Send the USER command
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(client, command);
    receive_response(client);

    // Send the PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(client, command);
    receive_response(client);
}

// Function to list mail messages
void list_messages(Pop3Client *client) {
    send_command(client, "LIST\r\n");
    receive_response(client);
}

// Function to retrieve a specific message
void retrieve_message(Pop3Client *client, int message_number) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "RETR %d\r\n", message_number);
    send_command(client, command);
    receive_response(client);
}

// Function to quit the POP3 session
void quit_session(Pop3Client *client) {
    send_command(client, "QUIT\r\n");
    receive_response(client);
    close(client->socketfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Pop3Client client;
    client.host = argv[1];
    client.port = POP3_PORT;

    connect_to_server(&client);
    receive_response(&client);  // Receive the server's welcome message

    authenticate(&client, argv[2], argv[3]);
    list_messages(&client);
    
    // For demonstration, retrieve the first message if it exists
    retrieve_message(&client, 1);
    
    quit_session(&client);
    return EXIT_SUCCESS;
}