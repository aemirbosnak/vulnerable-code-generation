//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
/*
 * This is a simple FTP client program in C.
 * It supports basic commands such as ls, get, put, and quit.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server_addr;

    // check if hostname is provided
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // get server address
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *username = "anonymous";
    char *password = "anonymous@example.com";
    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        printf("> ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);

        int len = recv(sock, buffer, BUFFER_SIZE, 0);
        if (len <= 0) {
            printf("Server disconnected\n");
            break;
        }

        buffer[len] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}