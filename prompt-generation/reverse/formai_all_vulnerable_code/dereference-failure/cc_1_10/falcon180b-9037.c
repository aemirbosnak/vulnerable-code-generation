//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0

char *server_name;
int server_port;
char *username;
char *password;
int sockfd;
struct sockaddr_in server_addr;

void error_handling(char *message);

int main(int argc, char **argv) {
    if (argc!= 7) {
        printf("Usage:./pop3_client <server_name> <server_port> <username> <password> <send_email_address> <email_subject> <email_body>\n");
        exit(1);
    }

    server_name = argv[1];
    server_port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("Error creating socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_name, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("Error connecting to server");
    }

    char *send_email_address = argv[5];
    char *email_subject = argv[6];
    char *email_body = argv[7];

    char *email_message = malloc(strlen(email_subject) + strlen(email_body) + 100);
    sprintf(email_message, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", username, send_email_address, email_subject, email_body);

    send(sockfd, email_message, strlen(email_message), 0);

    close(sockfd);

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}