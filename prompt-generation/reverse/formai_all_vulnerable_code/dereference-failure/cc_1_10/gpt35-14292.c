//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    // Get IP address of hostname
    struct hostent *he;
    he = gethostbyname(hostname);

    if (he == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    char *ip = inet_ntoa(*((struct in_addr *)he->h_addr_list[0]));
    printf("Connecting to %s (%s:%d)...\n", hostname, ip, port);

    // Open the socket
    int client_sock;
    struct sockaddr_in server_addr;
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        perror("socket");
        exit(1);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the server
    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Read greeting message
    char buffer[BUFSIZE];
    if (read(client_sock, buffer, BUFSIZE) < 0) {
        perror("read");
        exit(1);
    }
    printf("Server says: %s", buffer);

    // Send login information
    char login[BUFSIZE];
    snprintf(login, BUFSIZE, "a001 LOGIN %s\r\n", username);
    if (send(client_sock, login, strlen(login), 0) < 0) {
        perror("send");
        exit(1);
    }
    printf("Login command sent.\n");

    // Read response to login command
    if (read(client_sock, buffer, BUFSIZE) < 0) {
        perror("read");
        exit(1);
    }
    printf("Server says: %s", buffer);

    // Close the socket
    close(client_sock);
    return 0;
}