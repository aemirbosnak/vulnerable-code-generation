//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    /* Declare variables */
    int sockfd;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE], tmp[BUFFER_SIZE];
    char *domain_name = "example.com";
    char *sender_email = "knight@mydomain.com";
    char *recipient_email = "princess@royalcastle.com";
    char *subject = "Important message for the princess!";
    char *message = "Dearest princess, I hope this message finds you well. I have information that may prove crucial in the battle against the Dark Lord. Please reply at your earliest convenience. Yours truly, Knight.";

    /* Get IP address from domain name */
    struct hostent *server = gethostbyname(domain_name);
    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve domain name %s\n", domain_name);
        exit(-1);
    }

    /* Setup socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(-1);
    }

    /* Fill in server details */
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25);
    server_address.sin_addr = *((struct in_addr *)server->h_addr);

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        fprintf(stderr, "Error: Could not connect to server\n");
        exit(-1);
    }

    /* Read welcome message */
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    memset(buffer, 0, BUFFER_SIZE);

    /* Send HELO message */
    memset(tmp, 0, BUFFER_SIZE);
    sprintf(tmp, "HELO %s\r\n", domain_name);
    send(sockfd, tmp, strlen(tmp), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    memset(buffer, 0, BUFFER_SIZE);

    /* Send MAIL FROM message */
    memset(tmp, 0, BUFFER_SIZE);
    sprintf(tmp, "MAIL FROM: <%s>\r\n", sender_email);
    send(sockfd, tmp, strlen(tmp), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    memset(buffer, 0, BUFFER_SIZE);

    /* Send RCPT TO message */
    memset(tmp, 0, BUFFER_SIZE);
    sprintf(tmp, "RCPT TO: <%s>\r\n", recipient_email);
    send(sockfd, tmp, strlen(tmp), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    memset(buffer, 0, BUFFER_SIZE);

    /* Send DATA message */
    send(sockfd, "DATA\r\n", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    memset(buffer, 0, BUFFER_SIZE);

    /* Send email headers and message */
    memset(tmp, 0, BUFFER_SIZE);
    sprintf(tmp, "From: <%s>\r\n", sender_email);
    send(sockfd, tmp, strlen(tmp), 0);

    memset(tmp, 0, BUFFER_SIZE);
    sprintf(tmp, "To: <%s>\r\n", recipient_email);
    send(sockfd, tmp, strlen(tmp), 0);

    memset(tmp, 0, BUFFER_SIZE);
    sprintf(tmp, "Subject: %s\r\n", subject);
    send(sockfd, tmp, strlen(tmp), 0);

    memset(tmp, 0, BUFFER_SIZE);
    sprintf(tmp, "\r\n%s\r\n", message);
    send(sockfd, tmp, strlen(tmp), 0);

    /* Send QUIT message */
    send(sockfd, "QUIT\r\n", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    memset(buffer, 0, BUFFER_SIZE);

    /* Close socket */
    close(sockfd);

    return 0;
}