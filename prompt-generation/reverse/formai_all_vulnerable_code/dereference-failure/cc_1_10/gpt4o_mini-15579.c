//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Declare noble constants for the FTP port and noble size
#define FTP_PORT 21
#define BUFFER_SIZE 1024

// Define a noble structure to represent the noble FTP Client
typedef struct {
    int sockfd;
    char server_ip[16];
    char username[64];
    char password[64];
    int transfer_mode; // 0 for ASCII, 1 for Binary
} FTPClient;

void noble_introduce(FTPClient *client) {
    printf("Hark! An FTP Client has been summoned to connect to the realm of %s.\n", client->server_ip);
}

void noble_connect(FTPClient *client) {
    struct sockaddr_in server_addr;
    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0) {
        perror("Alas! The socket could not be created.");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    inet_pton(AF_INET, client->server_ip, &server_addr.sin_addr);
    
    if (connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Alas! The connection to the server hath failed.");
        exit(EXIT_FAILURE);
    }
    
    noble_introduce(client);
}

void noble_send_command(FTPClient *client, const char *command) {
    send(client->sockfd, command, strlen(command), 0);
    send(client->sockfd, "\r\n", 2, 0); // Append CR LF
}

void noble_recv_response(FTPClient *client, char *response) {
    recv(client->sockfd, response, BUFFER_SIZE - 1, 0);
    printf("Server: %s\n", response);
}

void noble_login(FTPClient *client) {
    char response[BUFFER_SIZE];

    // Send USER command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s", client->username);
    noble_send_command(client, command);
    noble_recv_response(client, response);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s", client->password);
    noble_send_command(client, command);
    noble_recv_response(client, response);
}

void noble_set_transfer_mode(FTPClient *client, int mode) {
    char *mode_str = mode == 0 ? "I" : "A";
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "TYPE %s", mode_str);
    noble_send_command(client, command);
}

void noble_retrieve_file(FTPClient *client, const char *filename) {
    char response[BUFFER_SIZE];
    
    noble_send_command(client, "PASV"); // Enter Passive Mode
    noble_recv_response(client, response);
    
    // Parse IP and port from response (simplified)
    int p1, p2;
    sscanf(response, "%*s %*s %*s %*s %*s %d,%d", &p1, &p2);
    int data_port = p1 * 256 + p2;

    // Create a new socket for data transfer
    int data_sockfd;
    struct sockaddr_in data_addr;
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    inet_pton(AF_INET, client->server_ip, &data_addr.sin_addr);

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("The data connection could not be established.");
        return;
    }

    // Send RETR command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s", filename);
    noble_send_command(client, command);
    noble_recv_response(client, response);

    // Receive file data
    FILE *fp = fopen(filename, "wb");
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(data_sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
    }
    fclose(fp);

    // Close data connection
    close(data_sockfd);
    noble_recv_response(client, response);
}

void noble_disconnect(FTPClient *client) {
    noble_send_command(client, "QUIT");
    close(client->sockfd);
    printf("The noble FTP client hath departed from the realm.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <server_ip> <username> <password> <filename>\n", argv[0]);
        return 1;
    }

    FTPClient client;
    strcpy(client.server_ip, argv[1]);
    strcpy(client.username, argv[2]);
    strcpy(client.password, argv[3]);
    
    noble_connect(&client);
    noble_login(&client);
    noble_set_transfer_mode(&client, 1); // Binary mode
    noble_retrieve_file(&client, argv[4]);
    noble_disconnect(&client);

    return 0;
}