//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXIMUM_BUFFER_SIZE 1024

struct email {
    char* from_email_address;
    char* to_email_address;
    char* subject;
    char* message;
};

int validate_field(char* field) {
    if (field == NULL || strlen(field) == 0) {
        return 0;
    }
    
    return 1;
}

int send_email(struct email email) {
    int socketfd;
    struct sockaddr_in server_address;
    char buffer[MAXIMUM_BUFFER_SIZE] = {0};

    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation error\n");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(socketfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Connection error\n");
        return -1;
    }

    if (recv(socketfd, buffer, MAXIMUM_BUFFER_SIZE, 0) < 0) {
        printf("Receiving error\n");
        return -1;
    }

    printf("%s", buffer);

    sprintf(buffer, "EHLO localhost\r\n");

    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        printf("Sending error\n");
        return -1;
    }

    if (recv(socketfd, buffer, MAXIMUM_BUFFER_SIZE, 0) < 0) {
        printf("Receiving error\n");
        return -1;
    }

    printf("%s", buffer);

    sprintf(buffer, "MAIL FROM:<%s>\r\n", email.from_email_address);

    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        printf("Sending error\n");
        return -1;
    }

    if (recv(socketfd, buffer, MAXIMUM_BUFFER_SIZE, 0) < 0) {
        printf("Receiving error\n");
        return -1;
    }

    printf("%s", buffer);

    sprintf(buffer, "RCPT TO:<%s>\r\n", email.to_email_address);

    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        printf("Sending error\n");
        return -1;
    }

    if (recv(socketfd, buffer, MAXIMUM_BUFFER_SIZE, 0) < 0) {
        printf("Receiving error\n");
        return -1;
    }

    printf("%s", buffer);

    sprintf(buffer, "DATA\r\n");

    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        printf("Sending error\n");
        return -1;
    }

    if (recv(socketfd, buffer, MAXIMUM_BUFFER_SIZE, 0) < 0) {
        printf("Receiving error\n");
        return -1;
    }

    printf("%s", buffer);

    sprintf(buffer, "From: %s\r\n", email.from_email_address);

    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        printf("Sending error\n");
        return -1;
    }

    sprintf(buffer, "To: %s\r\n", email.to_email_address);

    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        printf("Sending error\n");
        return -1;
    }

    sprintf(buffer, "Subject: %s\r\n", email.subject);

    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        printf("Sending error\n");
        return -1;
    }

    sprintf(buffer, "\r\n%s\r\n.\r\n", email.message);

    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        printf("Sending error\n");
        return -1;
    }

    if (recv(socketfd, buffer, MAXIMUM_BUFFER_SIZE, 0) < 0) {
        printf("Receiving error\n");
        return -1;
    }

    printf("%s\n", buffer);

    sprintf(buffer, "QUIT\r\n");

    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        printf("Sending error\n");
        return -1;
    }

    close(socketfd);

    return 0;
}

int main() {
    struct email email;

    email.from_email_address = strdup("sender@example.com");
    email.to_email_address = strdup("recipient@example.com");
    email.subject = strdup("Test email");
    email.message = strdup("This is a test email");

    if (!validate_field(email.from_email_address)) {
        printf("Invalid sender email address\n");
        exit(-1);
    }

    if (!validate_field(email.to_email_address)) {
        printf("Invalid recipient email address\n");
        exit(-1);
    }

    if (!validate_field(email.subject)) {
        printf("Invalid email subject\n");
        exit(-1);
    }

    if (!validate_field(email.message)) {
        printf("Invalid email message\n");
        exit(-1);
    }

    if (send_email(email) == -1) {
        printf("Failed to send email\n");
        exit(-1);
    }

    printf("Email sent successfully\n");

    free(email.from_email_address);
    free(email.to_email_address);
    free(email.subject);
    free(email.message);

    return 0;
}