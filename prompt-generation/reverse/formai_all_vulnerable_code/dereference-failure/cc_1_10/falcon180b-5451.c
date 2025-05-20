//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110
#define USERNAME "username"
#define PASSWORD "password"

int main() {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    char send_buff[BUFFER_SIZE];
    char recv_buff[BUFFER_SIZE];
    int n;
    char *user_input;
    int user_input_len;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed\n");
        exit(0);
    }

    host = gethostbyname("pop.gmail.com");
    if (host == NULL) {
        printf("Host not found\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    serv_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        exit(0);
    }

    while (1) {
        memset(send_buff, 0, BUFFER_SIZE);
        memset(recv_buff, 0, BUFFER_SIZE);

        printf("Enter command: ");
        fgets(send_buff, BUFFER_SIZE, stdin);

        if (strcmp(send_buff, "quit") == 0) {
            break;
        }

        n = send(sockfd, send_buff, strlen(send_buff), 0);
        if (n < 0) {
            printf("Send failed\n");
            exit(0);
        }

        n = recv(sockfd, recv_buff, BUFFER_SIZE, 0);
        if (n < 0) {
            printf("Receive failed\n");
            exit(0);
        }

        printf("Received response: %s\n", recv_buff);
    }

    close(sockfd);
    return 0;
}