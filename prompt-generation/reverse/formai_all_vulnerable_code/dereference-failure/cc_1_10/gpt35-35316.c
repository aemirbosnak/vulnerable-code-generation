//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void print_error(char* error_message) {
    printf("I'm sorry, ");
    printf("%s", error_message);
    exit(1);
}

int main() {
    char* hostname = "imap.example.com";
    char* username = "user";
    char* password = "password";

    // Connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        print_error("I cannot create socket.");
    }

    struct hostent* server = gethostbyname(hostname);

    if(server == NULL) {
        print_error("I cannot find host.");
    }

    struct sockaddr_in server_address;
    bzero((char*)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(143);

    if(connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        print_error("I cannot connect to server.");
    }

    // Login to server
    char message[1024];
    int n;

    memset(message, 0, 1024);

    n = sprintf(message, "%s%s", "a001 LOGIN ", username);
    write(sockfd, message, n);

    memset(message, 0, 1024);
    n = read(sockfd, message, 1024);

    if(n < 0) {
        print_error("I cannot read server response.");
    }

    char response_code[4];
    memcpy(response_code, &message[0], 3);
    response_code[3] = '\0';

    if(strcmp(response_code, "a01") != 0) {
        print_error("I cannot authenticate to server.");
    }

    // Navigate mailbox
    memset(message, 0, 1024);
    n = sprintf(message, "a002 SELECT INBOX");
    write(sockfd, message, n);

    memset(message, 0, 1024);
    n = read(sockfd, message, 1024);

    if(n < 0) {
        print_error("I cannot read server response.");
    }

    memcpy(response_code, &message[0], 3);
    response_code[3] = '\0';

    if(strcmp(response_code, "a02") != 0) {
        print_error("I cannot select mailbox.");
    }

    printf("Connection to %s successful.\n", hostname);
    printf("Username: %s\n", username);
    printf("Mailbox: %s\n", "INBOX");

    // Close connection
    memset(message, 0, 1024);
    n = sprintf(message, "a003 LOGOUT");
    write(sockfd, message, n);

    close(sockfd);

    printf("Connection to %s closed.\n", hostname);

    return 0;
}