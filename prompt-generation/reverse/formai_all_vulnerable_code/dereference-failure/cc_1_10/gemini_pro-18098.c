//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 21

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <filename>\n", argv[0]);
        return 1;
    }

    // Get the hostname and filename from the command line arguments.
    char *hostname = argv[1];
    char *filename = argv[2];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Get the IP address of the hostname.
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Connect to the FTP server.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    memcpy(&servaddr.sin_addr, hostent->h_addr_list[0], hostent->h_length);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the FTP commands.
    char buf[1024];
    sprintf(buf, "USER anonymous\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    sprintf(buf, "PASS anonymous@\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    sprintf(buf, "TYPE I\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    sprintf(buf, "RETR %s\r\n", filename);
    send(sockfd, buf, strlen(buf), 0);

    // Receive the file.
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    while (1) {
        int n = recv(sockfd, buf, sizeof(buf), 0);
        if (n <= 0) {
            break;
        }
        fwrite(buf, 1, n, fp);
    }
    fclose(fp);

    // Close the connection.
    close(sockfd);

    return 0;
}