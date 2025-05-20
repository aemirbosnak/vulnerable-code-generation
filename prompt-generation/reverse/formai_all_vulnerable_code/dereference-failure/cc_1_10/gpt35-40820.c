//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void ftp_download(int sock, char *filename) {
    FILE *fp;
    char buffer[BUFFER_SIZE] = { 0 };
    int len, bytes_received;

    fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("Error opening %s\n", filename);
        exit(1);
    }

    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    while(bytes_received > 0) {
        fwrite(buffer, 1, bytes_received, fp);
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    int sock;
    char buffer[BUFFER_SIZE] = { 0 };

    if(argc < 3) {
        printf("Usage: %s IP PORT\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        printf("Failed to create socket\n");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        printf("Invalid address or address not supported\n");
        exit(1);
    }

    int connect_status = connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));
    if(connect_status < 0) {
        printf("Failed to connect to the server\n");
        exit(1);
    }

    // Send the request to get the list of files in the remote server
    strcpy(buffer, "LIST");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the list of files from the server
    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
    printf("List of files in the remote server:\n%s\n", buffer);

    // Download a file from the remote server
    char filename[256];
    printf("Enter the filename to download: ");
    scanf("%s", filename);

    strcpy(buffer, "GET ");
    strcat(buffer, filename);
    send(sock, buffer, strlen(buffer), 0);

    ftp_download(sock, filename);
    printf("File '%s' downloaded successfully!\n", filename);

    close(sock);
    return 0;
}