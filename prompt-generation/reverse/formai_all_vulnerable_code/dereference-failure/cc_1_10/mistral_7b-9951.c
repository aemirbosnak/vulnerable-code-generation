//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

void send_command(FILE *fd, const char *command) {
    fprintf(fd, "%s\r\n", command);
    fflush(fd);
}

int wait_for_response(FILE *fd) {
    char buffer[BUFFER_SIZE];
    int n;

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = fread(buffer, sizeof(char), BUFFER_SIZE, fd);
        if (n > 0) {
            buffer[n - 1] = '\0';
            if (strstr(buffer, "\r\n") != NULL) {
                return 1;
            }
        } else {
            perror("Error reading from socket");
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    FILE *fd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Error converting IP address");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    fd = fdopen(sockfd, "w+");

    send_command(fd, "HELO Client\r\n");
    wait_for_response(fd);

    send_command(fd, "MAIL FROM:<client@example.com>\r\n");
    wait_for_response(fd);

    send_command(fd, "RCPT TO:<recipient@example.com>\r\n");
    wait_for_response(fd);

    send_command(fd, "DATA\r\n");
    wait_for_response(fd);

    fputs("From: client@example.com\r\n", fd);
    fputs("To: recipient@example.com\r\n", fd);
    fputs("Subject: Test Email\r\n\r\n", fd);

    fputs("Hello World!", fd);
    fputs("\r\n.", fd);

    wait_for_response(fd);

    fclose(fd);
    close(sockfd);

    return 0;
}