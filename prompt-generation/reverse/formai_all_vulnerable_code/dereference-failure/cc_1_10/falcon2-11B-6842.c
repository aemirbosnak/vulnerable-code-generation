//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <strings.h>

#define PORT 993
#define MAXLINE 1024

void send_imap_command(int sockfd, char *command);
int receive_imap_response(int sockfd, char *response);
int establish_connection(char *host, int port);
void free_resources(char *host, int port);

int main() {
    char host[256];
    int port = PORT;
    char command[MAXLINE];
    char response[MAXLINE];

    printf("Enter the hostname: ");
    scanf("%s", host);

    int sockfd = establish_connection(host, port);
    if (sockfd < 0) {
        printf("Failed to establish connection\n");
        return 1;
    }

    while (1) {
        printf("Enter the IMAP command: ");
        scanf("%s", command);

        send_imap_command(sockfd, command);
        if (receive_imap_response(sockfd, response) < 0) {
            printf("Failed to receive response\n");
            break;
        }
        printf("%s\n", response);
    }

    free_resources(host, port);
    return 0;
}

void send_imap_command(int sockfd, char *command) {
    int len = strlen(command);
    send(sockfd, command, len, 0);
    printf("Sent command: %s\n", command);
}

int receive_imap_response(int sockfd, char *response) {
    int n = read(sockfd, response, MAXLINE);
    if (n < 0) {
        return -1;
    }
    response[n] = '\0';
    printf("Received response: %s\n", response);
    return n;
}

int establish_connection(char *host, int port) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        return -1;
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        return -1;
    }

    return sockfd;
}

void free_resources(char *host, int port) {
    close(establish_connection(host, port));
}