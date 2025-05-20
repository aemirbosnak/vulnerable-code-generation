//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25
#define MAX_MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <email-address>\n", argv[0]);
        return 1;
    }

    char email_address[128];
    strcpy(email_address, argv[1]);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    struct hostent *server = gethostbyname("localhost");
    if (server == NULL) {
        perror("gethostbyname");
        return 1;
    }

    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char message[MAX_MESSAGE_SIZE];
    strcpy(message, "Subject: SMTP Client Test\r\n");
    strcat(message, "From: ");
    strcat(message, email_address);
    strcat(message, "\r\n");
    strcat(message, "To: ");
    strcat(message, email_address);
    strcat(message, "\r\n\r\n");
    strcat(message, "This is a test message.");

    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("send");
        return 1;
    }

    char response[MAX_MESSAGE_SIZE];
    if (recv(socket_fd, response, MAX_MESSAGE_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("Response: %s\n", response);

    close(socket_fd);

    return 0;
}