//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define HOST "smtp.gmail.com"
#define PORT "587"

#define BUFFER_SIZE 1024

char* read_input() {
    char* input = (char*) malloc(BUFFER_SIZE * sizeof(char));
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;
    return input;
}

int main() {
    int client_socket_fd;
    struct addrinfo hints, *server_info, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(HOST, PORT, &hints, &server_info) != 0) {
        perror("getaddrinfo");
        exit(1);
    }

    for (p = server_info; p != NULL; p = p->ai_next) {
        if ((client_socket_fd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(client_socket_fd, p->ai_addr, p->ai_addrlen) == -1) {
            close(client_socket_fd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to %s on port %s\n", HOST, PORT);
        exit(2);
    }

    freeaddrinfo(server_info);

    char buffer[BUFFER_SIZE];

    recv(client_socket_fd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s\n", buffer);

    send(client_socket_fd, "EHLO localhost\r\n", strlen("EHLO localhost\r\n"), 0);
    recv(client_socket_fd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s\n", buffer);

    char* email_address;
    printf("Enter your email address: ");
    email_address = read_input();

    sprintf(buffer, "MAIL FROM: <%s>\r\n", email_address);
    send(client_socket_fd, buffer, strlen(buffer), 0);
    recv(client_socket_fd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s\n", buffer);

    char* recipient;
    printf("Enter recipient email address: ");
    recipient = read_input();

    sprintf(buffer, "RCPT TO: <%s>\r\n", recipient);
    send(client_socket_fd, buffer, strlen(buffer), 0);
    recv(client_socket_fd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s\n", buffer);

    send(client_socket_fd, "DATA\r\n", strlen("DATA\r\n"), 0);
    recv(client_socket_fd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s\n", buffer);

    char* subject;
    printf("Enter email subject: ");
    subject = read_input();

    char* message;
    printf("Enter email message (press enter twice to finish):\n");
    message = (char*) malloc(BUFFER_SIZE * sizeof(char));
    int count = 0;
    while (1) {
        fgets(&message[count], BUFFER_SIZE - count, stdin);
        if (message[count] == '\n') {
            count++;
            fgets(&message[count], BUFFER_SIZE - count, stdin);
            if (message[count] == '\n') {
                break;
            }
        }
        count += strlen(&message[count]);
        if (count >= BUFFER_SIZE - 1) {
            break;
        }
    }

    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, message);
    send(client_socket_fd, buffer, strlen(buffer), 0);
    recv(client_socket_fd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s\n", buffer);

    send(client_socket_fd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    recv(client_socket_fd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s\n", buffer);

    close(client_socket_fd);

    return 0;
}