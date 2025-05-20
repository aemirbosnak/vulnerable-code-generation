//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE_BUFF 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_receive(int sockfd, char *send_msg, char *receive_msg, int receive_msg_size) {
    if(send(sockfd, send_msg, strlen(send_msg), 0) == -1) {
        error("Error sending message.\n");
    }
    if(recv(sockfd, receive_msg, receive_msg_size, 0) == -1) {
        error("Error receiving message.\n");
    }
}

int main(int argc, char *argv[]) {
    char *email = "example@email.com";
    char *password = "password";
    char *imap_server = "imap.gmail.com";
    char *imap_port = "993";
    char receive_buffer[MAX_LINE_BUFF];

    struct hostent *he;
    struct sockaddr_in server;

    // Resolve host
    if((he = gethostbyname(imap_server)) == NULL) {
        error("Error resolving hostname.\n");
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1) {
        error("Error creating socket.\n");
    }

    // Configure server
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(imap_port));
    server.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server.sin_zero), '\0', 8);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1) {
        error("Error connecting to server.\n");
    }

    // Receive server greeting
    memset(receive_buffer, '\0', MAX_LINE_BUFF);
    if(recv(sockfd, receive_buffer, MAX_LINE_BUFF-1, 0) == -1) {
        error("Error receiving server greeting.\n");
    }
    printf("%s\n", receive_buffer);

    // Send login request
    char *login_request = calloc(MAX_LINE_BUFF, sizeof(char));
    snprintf(login_request, MAX_LINE_BUFF, "a001 LOGIN %s %s\n", email, password);
    send_receive(sockfd, login_request, receive_buffer, MAX_LINE_BUFF-1);
    printf("%s\n", receive_buffer);

    // Send Select inbox request
    char *select_inbox_request = "a002 SELECT INBOX\n";
    send_receive(sockfd, select_inbox_request, receive_buffer, MAX_LINE_BUFF-1);
    printf("%s\n", receive_buffer);

    // Send list email request
    char *list_email_request = "a003 FETCH 1:* ALL\n";
    send_receive(sockfd, list_email_request, receive_buffer, MAX_LINE_BUFF-1);
    printf("%s\n", receive_buffer);

    // Close socket
    close(sockfd);

    return 0;
}