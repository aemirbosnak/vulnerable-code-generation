//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
/*
 * Building a FTP Client example program in a imaginative style
 *
 * This program allows the user to interact with a FTP server and perform
 * various operations such as uploading and downloading files, creating
 * directories, and listing the contents of a directory.
 *
 * Usage:
 *   ./ftp_client <host> <port> <username> <password>
 *
 * Example:
 *   ./ftp_client ftp.example.com 21 user1 pass123
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <host> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    const char *host = argv[1];
    const char *port = argv[2];
    const char *username = argv[3];
    const char *password = argv[4];

    struct addrinfo hints;
    struct addrinfo *result, *rp;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host, port, &hints, &result) != 0) {
        printf("Error: Could not resolve hostname\n");
        return 1;
    }

    int sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    if (connect(sock, result->ai_addr, result->ai_addrlen) != 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    freeaddrinfo(result);

    char buffer[BUFFER_SIZE];
    char *ptr;
    int n;

    // login
    ptr = buffer;
    n = snprintf(ptr, BUFFER_SIZE, "USER %s\r\n", username);
    if (n < 0) {
        printf("Error: Could not format USER command\n");
        return 1;
    }
    ptr += n;

    n = snprintf(ptr, BUFFER_SIZE, "PASS %s\r\n", password);
    if (n < 0) {
        printf("Error: Could not format PASS command\n");
        return 1;
    }
    ptr += n;

    if (send(sock, buffer, ptr - buffer, 0) < 0) {
        printf("Error: Could not send USER and PASS commands\n");
        return 1;
    }

    // list files
    ptr = buffer;
    n = snprintf(ptr, BUFFER_SIZE, "LIST\r\n");
    if (n < 0) {
        printf("Error: Could not format LIST command\n");
        return 1;
    }
    ptr += n;

    if (send(sock, buffer, ptr - buffer, 0) < 0) {
        printf("Error: Could not send LIST command\n");
        return 1;
    }

    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Could not receive LIST response\n");
        return 1;
    }

    // upload file
    ptr = buffer;
    n = snprintf(ptr, BUFFER_SIZE, "STOR myfile.txt\r\n");
    if (n < 0) {
        printf("Error: Could not format STOR command\n");
        return 1;
    }
    ptr += n;

    FILE *fp = fopen("myfile.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file for reading\n");
        return 1;
    }

    while ((n = fread(ptr, 1, BUFFER_SIZE, fp)) > 0) {
        if (send(sock, buffer, n, 0) < 0) {
            printf("Error: Could not send file data\n");
            return 1;
        }
    }

    fclose(fp);

    // download file
    ptr = buffer;
    n = snprintf(ptr, BUFFER_SIZE, "RETR myfile.txt\r\n");
    if (n < 0) {
        printf("Error: Could not format RETR command\n");
        return 1;
    }
    ptr += n;

    if (send(sock, buffer, ptr - buffer, 0) < 0) {
        printf("Error: Could not send RETR command\n");
        return 1;
    }

    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Could not receive file data\n");
        return 1;
    }

    fp = fopen("myfile.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file for writing\n");
        return 1;
    }

    while ((n = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        if (fwrite(buffer, 1, n, fp) < 0) {
            printf("Error: Could not write file data\n");
            return 1;
        }
    }

    fclose(fp);

    // logout
    ptr = buffer;
    n = snprintf(ptr, BUFFER_SIZE, "QUIT\r\n");
    if (n < 0) {
        printf("Error: Could not format QUIT command\n");
        return 1;
    }
    ptr += n;

    if (send(sock, buffer, ptr - buffer, 0) < 0) {
        printf("Error: Could not send QUIT command\n");
        return 1;
    }

    close(sock);

    return 0;
}