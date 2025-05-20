//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

// Function to get the host IP address
struct sockaddr_in get_host_ip(char* host) {
    struct hostent* he;
    struct in_addr** addr_list;

    if ((he = gethostbyname(host)) == NULL) {
        printf("Error: could not resolve %s.", host);
        exit(1);
    }

    addr_list = (struct in_addr**) he->h_addr_list;

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *addr_list[0];
    server_address.sin_port = htons(25);

    return server_address;
}

// Function to send email
void send_email(char* host, char* sender, char* recipient, char* subject, char* body) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error: could not create socket.");
        exit(1);
    }

    struct sockaddr_in server_address = get_host_ip(host);

    if (connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error: could not connect to %s.", host);
        exit(1);
    }

    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: could not receive data from %s.", host);
        exit(1);
    }

    sprintf(buffer, "EHLO %s\r\n", host);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: could not send data to %s.", host);
        exit(1);
    }

    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: could not receive data from %s.", host);
        exit(1);
    }

    sprintf(buffer, "MAIL FROM:<%s>\r\n", sender);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: could not send data to %s.", host);
        exit(1);
    }

    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: could not receive data from %s.", host);
        exit(1);
    }

    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: could not send data to %s.", host);
        exit(1);
    }

    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: could not receive data from %s.", host);
        exit(1);
    }

    sprintf(buffer, "DATA\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: could not send data to %s.", host);
        exit(1);
    }

    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: could not receive data from %s.", host);
        exit(1);
    }

    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: could not send data to %s.", host);
        exit(1);
    }

    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: could not receive data from %s.", host);
        exit(1);
    }

    close(socket_fd);
}

int main() {
    char host[] = "smtp.gmail.com";
    char sender[] = "sender@gmail.com";
    char recipient[] = "recipient@gmail.com";
    char subject[] = "Test email";
    char body[] = "This is a test email.";

    send_email(host, sender, recipient, subject, body);

    return 0;
}