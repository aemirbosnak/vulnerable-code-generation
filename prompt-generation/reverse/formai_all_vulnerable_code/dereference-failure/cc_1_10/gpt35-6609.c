//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>

int create_socket(char *host, int port)
{
    struct sockaddr_in server;
    struct hostent *hp;
    int sock;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    hp = gethostbyname(host);
    if (hp == NULL) {
        perror("Failed to get hostname");
        exit(1);
    }

    memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    return sock;
}

int main(int argc, char **argv)
{
    char *host;
    int port;
    char command[1024];
    char buffer[1024];
    int sock;
    int count;

    if (argc != 3) {
        puts("Usage: ftp_client <host> <port>");
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);

    sock = create_socket(host, port);
    puts("Connected to server");

    while (1) {
        printf("ftp> ");

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        if (strncmp(command, "quit", strlen("quit")) == 0) {
            break;
        }

        if (send(sock, command, strlen(command), 0) < 0) {
            perror("Failed to send command");
            exit(1);
        }

        count = recv(sock, buffer, sizeof(buffer), 0);

        if (count < 0) {
            perror("Failed to receive response");
            exit(1);
        }

        printf("%.*s", count, buffer);
    }

    close(sock);

    return 0;
}