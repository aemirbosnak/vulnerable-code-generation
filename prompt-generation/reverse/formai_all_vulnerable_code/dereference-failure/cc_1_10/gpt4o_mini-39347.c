//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    char server_address[256];
    char username[64];
    char password[64];
} FTPClient;

void initialize_client(FTPClient *client, const char *address, const char *user, const char *pass) {
    client->sock = -1;
    strncpy(client->server_address, address, sizeof(client->server_address));
    strncpy(client->username, user, sizeof(client->username));
    strncpy(client->password, pass, sizeof(client->password));
}

int connect_to_server(FTPClient *client) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    
    // Convert host name to IP address
    host = gethostbyname(client->server_address);
    if (host == NULL) {
        perror("Error resolving hostname");
        return -1;
    }

    client->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sock < 0) {
        perror("Error creating socket");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(client->sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    return 0;
}

void send_command(FTPClient *client, const char *command) {
    send(client->sock, command, strlen(command), 0);
}

void receive_response(FTPClient *client) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client->sock, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_received < 0) {
        perror("Error receiving response");
    } else {
        buffer[bytes_received] = '\0';
        printf("Server Response: %s\n", buffer);
    }
}

void login(FTPClient *client) {
    // Send USER command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", client->username);
    send_command(client, command);
    receive_response(client);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", client->password);
    send_command(client, command);
    receive_response(client);
}

void list_files(FTPClient *client) {
    // Send LIST command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "PASV\r\n");
    send_command(client, command);
    receive_response(client);
    
    // Code to handle PASV and get the data connection would be here (omitted for brevity)

    snprintf(command, sizeof(command), "LIST\r\n");
    send_command(client, command);
    receive_response(client);
}

void close_connection(FTPClient *client) {
    if (client->sock != -1) {
        close(client->sock);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    FTPClient client;
    initialize_client(&client, argv[1], argv[2], argv[3]);

    if (connect_to_server(&client) == 0) {
        printf("Connected to FTP server: %s\n", client.server_address);
        login(&client);
        list_files(&client);
        close_connection(&client);
    }

    return 0;
}