//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define FTP_PORT 21
#define COMMAND_BUFFER_SIZE 1024

typedef struct {
    int control_socket;
    int data_socket;
    char server_response[BUFFER_SIZE];
} FTPClient;

void init_client(FTPClient *ftp_client);
void connect_to_server(FTPClient *ftp_client, const char *server_ip);
void send_command(FTPClient *ftp_client, const char *command);
void receive_response(FTPClient *ftp_client);
void login(FTPClient *ftp_client, const char *username, const char *password);
void list_files(FTPClient *ftp_client);
void download_file(FTPClient *ftp_client, const char *filename);
void close_connection(FTPClient *ftp_client);

int main() {
    FTPClient ftp_client;
    init_client(&ftp_client);

    const char *server_ip = "127.0.0.1"; // replace with your FTP server IP
    connect_to_server(&ftp_client, server_ip);
    
    login(&ftp_client, "user", "pass"); // replace with your FTP credentials
    list_files(&ftp_client);
    download_file(&ftp_client, "test.txt"); // replace with your file name
    close_connection(&ftp_client);

    return 0;
}

void init_client(FTPClient *ftp_client) {
    ftp_client->control_socket = -1;
    ftp_client->data_socket = -1;
    memset(ftp_client->server_response, 0, BUFFER_SIZE);
}

void connect_to_server(FTPClient *ftp_client, const char *server_ip) {
    struct sockaddr_in server_addr;

    ftp_client->control_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (ftp_client->control_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(ftp_client->control_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(ftp_client->control_socket);
        exit(EXIT_FAILURE);
    }

    receive_response(ftp_client);
}

void send_command(FTPClient *ftp_client, const char *command) {
    send(ftp_client->control_socket, command, strlen(command), 0);
    send(ftp_client->control_socket, "\r\n", 2, 0);
}

void receive_response(FTPClient *ftp_client) {
    int bytes_received = recv(ftp_client->control_socket, ftp_client->server_response, sizeof(ftp_client->server_response) - 1, 0);
    if (bytes_received > 0) {
        ftp_client->server_response[bytes_received] = '\0';
        printf("Server: %s", ftp_client->server_response);
    }
}

void login(FTPClient *ftp_client, const char *username, const char *password) {
    char command[COMMAND_BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s", username);
    send_command(ftp_client, command);
    receive_response(ftp_client);

    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(ftp_client, command);
    receive_response(ftp_client);
}

void list_files(FTPClient *ftp_client) {
    send_command(ftp_client, "PASV");
    receive_response(ftp_client);
    
    // Here we should parse the PASV response to get the data connection details
    // For simplicity, we're skipping that step for now.

    send_command(ftp_client, "LIST");
    receive_response(ftp_client);
}

void download_file(FTPClient *ftp_client, const char *filename) {
    send_command(ftp_client, "RETR ");
    send_command(ftp_client, filename);
    receive_response(ftp_client);
    
    // Similar to the LIST command, we would handle data connection here.
}

void close_connection(FTPClient *ftp_client) {
    send_command(ftp_client, "QUIT");
    receive_response(ftp_client);
    close(ftp_client->control_socket);
}