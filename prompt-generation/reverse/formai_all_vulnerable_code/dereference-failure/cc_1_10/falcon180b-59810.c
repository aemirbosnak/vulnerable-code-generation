//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char buffer[BUFFER_SIZE];
    FILE *fp;
    char *filename;
    int len;

    // Check if the correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <port_number> <filename>\n");
        exit(1);
    }

    // Convert the server IP and port number from string to integer
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    host_info = gethostbyname(argv[1]);
    if (host_info == NULL) {
        printf("Error: Invalid server IP\n");
        exit(1);
    }
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    // Send the filename to the server
    len = strlen(argv[3]);
    send(sock, argv[3], len, 0);

    // Receive the file from the server
    fp = fopen(argv[3], "wb");
    if (fp == NULL) {
        printf("Error: Could not open file for writing\n");
        exit(1);
    }
    while ((len = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, len, fp);
    }
    fclose(fp);

    // Close the socket
    close(sock);

    printf("File transfer completed successfully!\n");

    return 0;
}