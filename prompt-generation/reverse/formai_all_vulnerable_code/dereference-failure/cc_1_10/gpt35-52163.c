//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define buffer_size 1024

void sendCommand(int sockfd, char* command) {
    char buffer[buffer_size];
    memset(buffer, 0, buffer_size);
    strcat(command, "\r\n");
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, buffer, buffer_size, 0);
    printf("%s\n", buffer);
}

void readResponse(int sockfd) {
    char buffer[buffer_size];
    memset(buffer, 0, buffer_size);
    recv(sockfd, buffer, buffer_size, 0);
    printf("%s\n", buffer);
}

int main() {
    char *hostname = "imap.gmail.com";
    struct hostent *host_info = gethostbyname(hostname);
    struct sockaddr_in server_address;
    int sockfd;

    if (host_info == NULL) {
        printf("Error getting host by name\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(993);
    server_address.sin_addr = *(struct in_addr *)host_info->h_addr;
    memset(&(server_address.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    readResponse(sockfd);

    sendCommand(sockfd, "a001 LOGIN user@gmail.com password");

    sendCommand(sockfd, "a002 SELECT INBOX");

    sendCommand(sockfd, "a003 FETCH 1 FULL");

    sendCommand(sockfd, "a004 LOGOUT");

    close(sockfd);

    return 0;
}