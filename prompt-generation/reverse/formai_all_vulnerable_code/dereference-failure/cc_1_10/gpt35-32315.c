//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_BUF 1024
#define POP3_PORT_NUM 110

int main(int argc, char *argv[]) {
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent *he;
    char buf[MAX_BUF + 1], user[MAX_BUF], pass[MAX_BUF];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <mail server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((he = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT_NUM);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server_addr.sin_zero), 0, 8);

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s\n", argv[1]);

    // Receive greeting message
    recv(sock_fd, buf, MAX_BUF, 0);
    printf("%s", buf);

    // Send user credentials
    printf("Username: ");
    fgets(user, MAX_BUF, stdin);
    send(sock_fd, user, strlen(user), 0);

    printf("Password: ");
    fgets(pass, MAX_BUF, stdin);
    send(sock_fd, pass, strlen(pass), 0);

    // Check authentication status
    recv(sock_fd, buf, MAX_BUF, 0);
    if (strstr(buf, "+OK") == NULL) {
        printf("Authentication failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Authentication successful!\n");

    // Send command to list messages
    send(sock_fd, "list\n", sizeof("list\n"), 0);
    recv(sock_fd, buf, MAX_BUF, 0);

    // Print message list
    printf("%s", buf);

    // Disconnect from server
    send(sock_fd, "quit\n", sizeof("quit\n"), 0);
    recv(sock_fd, buf, MAX_BUF, 0);

    printf("%s", buf);
    close(sock_fd);

    return 0;
}