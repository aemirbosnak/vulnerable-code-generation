//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FTPClient {
    char host[256];
    int port;
    char username[256];
    char password[256];
    int socket_fd;
    FILE *file_ptr;
} FTPClient;

FTPClient* ftp_client_init(char *host, int port, char *username, char *password) {
    FTPClient *client = malloc(sizeof(FTPClient));

    strcpy(client->host, host);
    client->port = port;
    strcpy(client->username, username);
    strcpy(client->password, password);

    client->socket_fd = socket(AF_INET, SOCK_STREAM, htons(port));
    client->file_ptr = NULL;

    return client;
}

void ftp_client_connect(FTPClient *client) {
    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(client->port);
    sock_addr.sin_addr.s_addr = inet_addr(client->host);

    if (connect(client->socket_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to %s on port %d\n", client->host, client->port);
}

void ftp_client_upload(FTPClient *client, char *file_name) {
    FILE *file_ptr = fopen(file_name, "r");
    if (file_ptr == NULL) {
        perror("Error opening file");
        exit(1);
    }

    client->file_ptr = file_ptr;

    char buffer[MAX_BUFFER_SIZE];
    int read_bytes;
    while ((read_bytes = fread(buffer, 1, MAX_BUFFER_SIZE, file_ptr)) > 0) {
        write(client->socket_fd, buffer, read_bytes);
    }

    fclose(file_ptr);
}

void ftp_client_download(FTPClient *client, char *file_name) {
    FILE *file_ptr = fopen(file_name, "w");
    if (file_ptr == NULL) {
        perror("Error opening file");
        exit(1);
    }

    client->file_ptr = file_ptr;

    char buffer[MAX_BUFFER_SIZE];
    int read_bytes;
    while ((read_bytes = read(client->socket_fd, buffer, MAX_BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, read_bytes, file_ptr);
    }

    fclose(file_ptr);
}

void ftp_client_close(FTPClient *client) {
    close(client->socket_fd);
    free(client);
}

int main() {
    FTPClient *client = ftp_client_init("localhost", 21, "username", "password");
    ftp_client_connect(client);

    ftp_client_upload(client, "test.txt");
    ftp_client_download(client, "test.txt");

    ftp_client_close(client);

    return 0;
}