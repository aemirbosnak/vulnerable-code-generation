//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define FTP_PORT 21

void usage() {
    fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", __FILE__);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage();
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "ERROR: %s: %s\n", hostname, hstrerror(h_errno));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buf[1024];
    int n, i;

    // Receive the welcome message
    n = read(sockfd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    // Send the username
    i = sprintf(buf, "USER %s\r\n", username);
    n = write(sockfd, buf, i);
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the username response
    n = read(sockfd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    // Send the password
    i = sprintf(buf, "PASS %s\r\n", password);
    n = write(sockfd, buf, i);
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the password response
    n = read(sockfd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    // Send the PASV command
    i = sprintf(buf, "PASV\r\n");
    n = write(sockfd, buf, i);
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the PASV response
    n = read(sockfd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    // Parse the IP address and port from the PASV response
    char *ip_address = strtok(buf, ",");
    char *port = strtok(NULL, ",");
    int data_port = atoi(port);

    // Close the control connection
    close(sockfd);

    // Open the data connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(data_port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the LIST command
    i = sprintf(buf, "LIST\r\n");
    n = write(sockfd, buf, i);
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the LIST response
    while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
        printf("%s", buf);
    }

    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Close the data connection
    close(sockfd);

    return 0;
}