//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage:./ftp_client <IP_Address> <Port_Number>\n");
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Error creating socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        error("Error connecting to server");
    }

    printf("Connected to %s:%d\n", ip_address, port_number);

    while (1) {
        printf("Enter command (help for list of commands): ");
        fgets(send_buffer, BUFFER_SIZE, stdin);
        send(sockfd, send_buffer, strlen(send_buffer), 0);

        memset(recv_buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            error("Error receiving data");
        }
        printf("%s\n", recv_buffer);
    }

    close(sockfd);
    return 0;
}