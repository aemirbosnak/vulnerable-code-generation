//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int n;
    char *message = "From: you@domain.com\r\n";
    char *subject = "Subject: Test\r\n\r\n";
    char *data = "Hello World!\r\n";
    int len = strlen(message) + strlen(subject) + strlen(data);
    char *full_message = malloc(len);
    strcpy(full_message, message);
    strcat(full_message, subject);
    strcat(full_message, data);

    if (argc!= 3) {
        printf("Usage:./client <ip_address> <port_number>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    send(sockfd, full_message, len, 0);

    close(sockfd);
    exit(0);
}