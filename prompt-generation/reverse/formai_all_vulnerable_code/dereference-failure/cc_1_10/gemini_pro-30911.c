//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define MAX_BUF 1024

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <port> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "Error getting host by name: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buf[MAX_BUF];
    int n;

    // Read banner
    n = read(sockfd, buf, MAX_BUF);
    if (n == -1) {
        fprintf(stderr, "Error reading banner: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    // Send username
    sprintf(buf, "USER %s\r\n", username);
    write(sockfd, buf, strlen(buf));

    // Read response
    n = read(sockfd, buf, MAX_BUF);
    if (n == -1) {
        fprintf(stderr, "Error reading response: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    // Send password
    char password[MAX_LINE];
    printf("Password: ");
    fgets(password, MAX_LINE, stdin);
    sprintf(buf, "PASS %s\r\n", password);
    write(sockfd, buf, strlen(buf));

    // Read response
    n = read(sockfd, buf, MAX_BUF);
    if (n == -1) {
        fprintf(stderr, "Error reading response: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    // Send QUIT
    write(sockfd, "QUIT\r\n", 6);

    // Read response
    n = read(sockfd, buf, MAX_BUF);
    if (n == -1) {
        fprintf(stderr, "Error reading response: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    close(sockfd);

    return 0;
}