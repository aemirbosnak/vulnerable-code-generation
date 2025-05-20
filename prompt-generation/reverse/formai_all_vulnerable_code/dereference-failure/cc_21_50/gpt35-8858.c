//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct hostent *host;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER] = {0};
    
    if (argc < 2) {
        printf("Please provide a hostname for the SMTP server.\n");
        return -1;
    }
    
    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        return -1;
    }
    
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr = *((struct in_addr *) host->h_addr);
    
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("connect");
        return -1;
    }
    
    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        return -1;
    }
    
    printf("%s", buffer);
    
    char *username = "<your SMTP username>";
    char *password = "<your SMTP password>";
    char *recipient = "<recipient email address>";
    char *subject = "Test email from my SMTP client";
    char *message = "This is a test message sent from my SMTP client";

    char helo_command[MAX_BUFFER] = {'\0'};
    sprintf(helo_command, "EHLO %s\r\n", argv[1]);
    if (send(client_socket, helo_command, strlen(helo_command), 0) < 0) {
        perror("send");
        return -1;
    }

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        return -1;
    }

    printf("%s", buffer);

    char auth_command[MAX_BUFFER] = {'\0'};
    sprintf(auth_command, "AUTH LOGIN\r\n");
    if (send(client_socket, auth_command, strlen(auth_command), 0) < 0) {
        perror("send");
        return -1;
    }

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        return -1;
    }

    printf("%s", buffer);

    char user_command[MAX_BUFFER] = {'\0'};
    sprintf(user_command, "%s\r\n", username);
    if (send(client_socket, user_command, strlen(user_command), 0) < 0) {
        perror("send");
        return -1;
    }

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        return -1;
    }

    printf("%s", buffer);

    char pass_command[MAX_BUFFER] = {'\0'};
    sprintf(pass_command, "%s\r\n", password);
    if (send(client_socket, pass_command, strlen(pass_command), 0) < 0) {
        perror("send");
        return -1;
    }

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        return -1;
    }

    printf("%s", buffer);

    char mail_from_command[MAX_BUFFER] = {'\0'};
    sprintf(mail_from_command, "MAIL FROM: <%s>\r\n", username);
    if (send(client_socket, mail_from_command, strlen(mail_from_command), 0) < 0) {
        perror("send");
        return -1;
    }

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        return -1;
    }

    printf("%s", buffer);

    char rcpt_to_command[MAX_BUFFER] = {'\0'};
    sprintf(rcpt_to_command, "RCPT TO: <%s>\r\n", recipient);
    if (send(client_socket, rcpt_to_command, strlen(rcpt_to_command), 0) < 0) {
        perror("send");
        return -1;
    }

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        return -1;
    }

    printf("%s", buffer);
    
    char data_command[MAX_BUFFER] = {'\0'};
    sprintf(data_command, "DATA\r\n");
    if (send(client_socket, data_command, strlen(data_command), 0) < 0) {
        perror("send");
        return -1;
    }

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        return -1;
    }

    printf("%s", buffer);

    char message_content[MAX_BUFFER] = {'\0'};
    sprintf(message_content, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", 
            username, recipient, subject, message);
    if (send(client_socket, message_content, strlen(message_content), 0) < 0) {
        perror("send");
        return -1;
    }

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        return -1;
    }

    printf("%s", buffer);

    char quit_command[MAX_BUFFER] = {'\0'};
    sprintf(quit_command, "QUIT\r\n");
    if (send(client_socket, quit_command, strlen(quit_command), 0) < 0) {
        perror("send");
        return -1;
    }

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        return -1;
    }

    printf("%s", buffer);

    close(client_socket);

    return 0;
}