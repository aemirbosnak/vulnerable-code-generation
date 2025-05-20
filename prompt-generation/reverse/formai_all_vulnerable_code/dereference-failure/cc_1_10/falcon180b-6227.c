//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char *username = "anonymous";
    char *password = "password";
    char *command = "LIST";
    char buffer[BUFFER_SIZE];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname("ftp.example.com");

    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = *(unsigned long *)host->h_addr;

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    if (send(sock, username, strlen(username), 0) == -1) {
        printf("Error sending username\n");
        exit(1);
    }

    if (send(sock, password, strlen(password), 0) == -1) {
        printf("Error sending password\n");
        exit(1);
    }

    if (send(sock, command, strlen(command), 0) == -1) {
        printf("Error sending command\n");
        exit(1);
    }

    while ((n = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}