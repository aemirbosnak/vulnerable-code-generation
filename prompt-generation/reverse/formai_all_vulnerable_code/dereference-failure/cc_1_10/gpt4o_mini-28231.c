//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h> 
#include <netdb.h>

#define BUFSIZE 1024

// Mathematical representations for FTP request types
typedef enum {
    USER = 1,
    PASS,
    CWD,
    LIST,
    RETR,
    STOR,
    QUIT
} FtpCommand;

typedef struct {
    int control_socket;
    char *hostname;
    char *username;
    char *password;
    char *current_dir;
} FtpClient;

// Function to establish a control connection to the FTP server
int establish_connection(FtpClient *client, const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host_entry;

    // Convert hostname to IP
    if ((host_entry = gethostbyname(hostname)) == NULL) {
        perror("Could not resolve hostname");
        return -1;
    }

    client->control_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->control_socket < 0) {
        perror("Could not create socket");
        return -1;
    }

    // Establishing the server address for FTP
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21); // FTP port
    memcpy(&server_addr.sin_addr.s_addr, host_entry->h_addr, host_entry->h_length);

    // Connect to server
    if (connect(client->control_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to server");
        return -1;
    }

    printf("Successfully connected to %s\n", hostname);
    return 0;
}

// Function to send commands to the FTP server
int send_command(FtpClient *client, const char *command) {
    if (send(client->control_socket, command, strlen(command), 0) < 0) {
        perror("Failed to send command");
        return -1;
    }
    
    return 0;
}

// Function to receive a response from the FTP server
void receive_response(FtpClient *client) {
    char buffer[BUFSIZE];
    int bytes_received;
    
    bytes_received = recv(client->control_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // Null terminate the received data
        printf("Server Response: %s\n", buffer);
    } else {
        perror("Failed to receive response");
    }
}

// Function to authenticate user credentials
int authenticate(FtpClient *client) {
    // User Command
    char command[BUFSIZE];
    sprintf(command, "USER %s\r\n", client->username);
    send_command(client, command);
    receive_response(client);

    // Password Command
    sprintf(command, "PASS %s\r\n", client->password);
    send_command(client, command);
    receive_response(client);
    
    return 0;
}

// Function to change the working directory
int change_directory(FtpClient *client, const char *directory) {
    char command[BUFSIZE];
    sprintf(command, "CWD %s\r\n", directory);
    send_command(client, command);
    receive_response(client);

    client->current_dir = strdup(directory);
    return 0;
}

// Function to list files in the current directory
void list_files(FtpClient *client) {
    char command[BUFSIZE];
    sprintf(command, "LIST\r\n");
    send_command(client, command);
    receive_response(client);
}

// Function to close the connection to the server
void close_connection(FtpClient *client) {
    send_command(client, "QUIT\r\n");
    receive_response(client);
    close(client->control_socket);
    printf("Connection closed.\n");
}

// Main program to implement FTP client functionality
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    // Instantiate an FtpClient and set properties
    FtpClient client;
    client.hostname = argv[1];
    client.username = argv[2];
    client.password = argv[3];
    client.current_dir = NULL;

    // Establish connection
    if (establish_connection(&client, client.hostname) != 0) {
        return 1;
    }

    // Authenticate user
    authenticate(&client);

    // Change directory to '/'
    change_directory(&client, "/");

    // List files in root directory
    list_files(&client);

    // Close the connection
    close_connection(&client);

    return 0;
}