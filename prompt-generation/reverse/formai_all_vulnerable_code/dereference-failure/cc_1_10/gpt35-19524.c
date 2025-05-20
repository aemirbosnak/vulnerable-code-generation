//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024
#define IMAP_PORT 143

int connect_to_server(char *hostname, int port) {
    struct hostent *he;
    struct sockaddr_in server_addr;
    int sockfd;

    if ((he = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        return -1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        return -1;
    }

    return sockfd;
}

int main(int argc, char *argv[]) {
    char *hostname = NULL;
    char *username = NULL;
    char *password = NULL;
    int sockfd, bytes_received;
    char buf[BUF_SIZE];

    if (argc != 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    username = argv[2];
    password = argv[3];

    if ((sockfd = connect_to_server(hostname, IMAP_PORT)) == -1) {
        return 1;
    }

    /* Start IMAP connection */
    sprintf(buf, ". login %s %s\r\n", username, password);
    send(sockfd, buf, strlen(buf), 0);

    /* Receive and print server response */
    bytes_received = recv(sockfd, buf, BUF_SIZE, 0);
    buf[bytes_received] = '\0';
    printf("%s", buf);

    /* Send LIST command */
    sprintf(buf, ". list \"\" \"*\"\r\n");
    send(sockfd, buf, strlen(buf), 0);

    /* Receive and print server response */
    bytes_received = recv(sockfd, buf, BUF_SIZE, 0);
    buf[bytes_received] = '\0';
    printf("%s", buf);

    /* Send LOGOUT command */
    sprintf(buf, ". logout\r\n");
    send(sockfd, buf, strlen(buf), 0);

    /* Receive and print server response */
    bytes_received = recv(sockfd, buf, BUF_SIZE, 0);
    buf[bytes_received] = '\0';
    printf("%s", buf);

    close(sockfd);
    return 0;
}