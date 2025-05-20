//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21 // Port Number for FTP Command Channel
#define BUFSIZE 1024 // Buffer for Receiving/Sending Data

void ftp_client(int sockfd);

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in srvaddr;
    struct hostent *host;

    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "usage: %s <server address or hostname>\n", argv[0]);
        exit(1);
    }

    // Create the Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }

    // Get the server's address
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname error");
        exit(1);
    }

    // Create the Server Address
    memset(&srvaddr, 0, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(PORT);
    memcpy(&srvaddr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*) &srvaddr, sizeof(srvaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Start the FTP Client
    ftp_client(sockfd);

    // Close the Socket
    close(sockfd);

    return 0;
}

void ftp_client(int sockfd) {
    char buf[BUFSIZE];
    ssize_t n;

    // Read the FTP Welcome Message
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    printf("%.*s\n", (int) n, buf);

    // Login to the Server
    printf("Username: ");
    fflush(stdout);
    fgets(buf, BUFSIZE, stdin);
    write(sockfd, buf, strlen(buf));
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    printf("%.*s\n", (int) n, buf);

    printf("Password: ");
    fflush(stdout);
    fgets(buf, BUFSIZE, stdin);
    write(sockfd, buf, strlen(buf));
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    printf("%.*s\n", (int) n, buf);

    // Enter Passive Mode
    write(sockfd, "PASV\r\n", 7);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    printf("%.*s\n", (int) n, buf);

    // Change to Root Directory
    write(sockfd, "CWD /\r\n", 7);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    printf("%.*s\n", (int) n, buf);

    // List the Contents of Root Directory
    write(sockfd, "LIST\r\n", 6);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    printf("%.*s\n", (int) n, buf);

    // Quit the FTP Session
    write(sockfd, "QUIT\r\n", 6);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    printf("%.*s\n", (int) n, buf);
}