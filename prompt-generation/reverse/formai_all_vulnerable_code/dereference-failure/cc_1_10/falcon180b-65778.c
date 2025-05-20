//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server;
    int port;
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int bytes_received;
    int i;

    if (argc!= 4) {
        printf("Usage: %s <server> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    server = argv[1];
    port = atoi(argv[2]);
    strcpy(username, argv[3]);
    strcpy(password, argv[4]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    while (1) {
        printf("Enter command: ");
        fgets(command, BUFFER_SIZE, stdin);
        if (strcasecmp(command, "quit") == 0) {
            break;
        }

        send(sock, command, strlen(command), 0);
        bytes_received = recv(sock, response, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Disconnected\n");
            return 1;
        }

        response[bytes_received] = '\0';
        printf("Response: %s", response);
    }

    close(sock);
    return 0;
}