//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE 1024
#define MAX_USERNAME 64
#define MAX_PASSWORD 64
#define MAX_COMMAND 1024
#define MAX_RESPONSE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];
    char username[MAX_USERNAME] = "";
    char password[MAX_PASSWORD] = "";
    char command[MAX_COMMAND] = "";
    char response[MAX_RESPONSE] = "";
    
    printf("POP3 Client\n");
    
    if (argc < 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }
    
    strcpy(sendline, "USER ");
    strcat(sendline, argv[2]);
    strcat(sendline, "\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    
    strcpy(sendline, "PASS ");
    strcat(sendline, argv[3]);
    strcat(sendline, "\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    
    while (1) {
        memset(recvline, 0, MAX_LINE);
        n = recv(sockfd, recvline, MAX_LINE, 0);
        if (n <= 0) {
            printf("Disconnected from server\n");
            close(sockfd);
            return 0;
        }
        recvline[n-2] = '\0';
        printf("%s", recvline);
        
        if (strstr(recvline, "+OK")) {
            strcpy(command, "STAT\r\n");
            send(sockfd, command, strlen(command), 0);
        } else if (strstr(recvline, "+OK")) {
            strcpy(command, "RETR 1\r\n");
            send(sockfd, command, strlen(command), 0);
        } else if (strstr(recvline, "+OK")) {
            strcpy(command, "DELE 1\r\n");
            send(sockfd, command, strlen(command), 0);
        } else if (strstr(recvline, "+OK")) {
            strcpy(command, "QUIT\r\n");
            send(sockfd, command, strlen(command), 0);
            close(sockfd);
            return 0;
        }
    }
    
    return 0;
}