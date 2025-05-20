//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_LINE 1024
#define PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];
    char send_buffer[BUFFER_SIZE];

    if(argc < 4){
        printf("Usage:./smtp_client <server_ip> <server_port> <sender_email>\n");
        exit(0);
    }

    strcpy(send_buffer, "HELO ");
    strcat(send_buffer, argv[3]);
    strcat(send_buffer, "\r\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Error opening socket\n");
        exit(0);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("Error connecting to server\n");
        exit(0);
    }

    while(1){
        memset(buffer, 0, sizeof(buffer));
        if(recv(sockfd, buffer, MAX_LINE, 0) <= 0){
            printf("Error receiving data\n");
            exit(0);
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}