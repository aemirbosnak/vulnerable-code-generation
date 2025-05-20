//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IMAP_PORT 993
#define MAX_BUF_SIZE 1024

const char* server_address = "mail.example.com";
const char* username = "[Your Email]";
const char* password = "[Your Password]";

void read_response(int sockfd) {
    char buf[MAX_BUF_SIZE];
    int n = read(sockfd, buf, MAX_BUF_SIZE);
    buf[n] = '\0';
    printf("%s", buf);
}

void send_command(int sockfd, const char* command) {
    char buf[MAX_BUF_SIZE];
    sprintf(buf, "%s\r\n", command);
    write(sockfd, buf, strlen(buf));
    read_response(sockfd);
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(IMAP_PORT);

    if (inet_pton(AF_INET, server_address, &servaddr.sin_addr) <= 0) {
        perror("Error: Cannot parse IP address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error: Connection failed");
        exit(EXIT_FAILURE);
    }

    read_response(sockfd); // Server greeting
    send_command(sockfd, "LOGIN");
    send_command(sockfd, username);
    send_command(sockfd, password);

    printf("\nSuccessfully connected to the IMAP server!\n");

    close(sockfd);
    return 0;
}