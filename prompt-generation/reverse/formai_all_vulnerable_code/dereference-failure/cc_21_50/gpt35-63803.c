//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* host = argv[1];
    int port = atoi(argv[2]);

    struct hostent* host_info;

    if ((host_info = gethostbyname(host)) == NULL) {
        printf("Could not resolve host %s\n", host);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = *((struct in_addr*)host_info->h_addr);

    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to %s:%d\n", host, port);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    int recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (recv_bytes < 0) {
        printf("Error while receiving message\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(buffer, "220") == NULL) {
        printf("Invalid response from server\n");
        exit(EXIT_FAILURE);
    }

    char helo[BUFFER_SIZE];
    sprintf(helo, "HELO %s\r\n", host);

    if (send(sockfd, helo, strlen(helo), 0) != strlen(helo)) {
        printf("Failed to send HELO command\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeof(buffer));

    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (recv_bytes < 0) {
        printf("Error while receiving message\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(buffer, "250") == NULL) {
        printf("Invalid response from server\n");
        exit(EXIT_FAILURE);
    }

    char from[BUFFER_SIZE];
    printf("From: ");
    fgets(from, BUFFER_SIZE, stdin);
    from[strcspn(from, "\n")] = 0;
    char from_command[BUFFER_SIZE];
    sprintf(from_command, "MAIL FROM:<%s>\r\n", from);

    if (send(sockfd, from_command, strlen(from_command), 0) != strlen(from_command)) {
        printf("Failed to send MAIL FROM command\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeof(buffer));

    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (recv_bytes < 0) {
        printf("Error while receiving message\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(buffer, "250") == NULL) {
        printf("Invalid response from server\n");
        exit(EXIT_FAILURE);
    }

    char to[BUFFER_SIZE];
    printf("To: ");
    fgets(to, BUFFER_SIZE, stdin);
    to[strcspn(to, "\n")] = 0;
    char to_command[BUFFER_SIZE];
    sprintf(to_command, "RCPT TO:<%s>\r\n", to);

    if (send(sockfd, to_command, strlen(to_command), 0) != strlen(to_command)) {
        printf("Failed to send RCPT TO command\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeof(buffer));

    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (recv_bytes < 0) {
        printf("Error while receiving message\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(buffer, "250") == NULL) {
        printf("Invalid response from server\n");
        exit(EXIT_FAILURE);
    }

    char subject[BUFFER_SIZE];
    printf("Subject: ");
    fgets(subject, BUFFER_SIZE, stdin);
    subject[strcspn(subject, "\n")] = 0;

    char data[] = "DATA\r\n";

    if (send(sockfd, data, strlen(data), 0) != strlen(data)) {
        printf("Failed to send DATA command\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeof(buffer));

    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (recv_bytes < 0) {
        printf("Error while receiving message\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(buffer, "354") == NULL) {
        printf("Invalid response from server\n");
        exit(EXIT_FAILURE);
    }

    char message[BUFFER_SIZE];
    printf("Message: ");

    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        if (strcmp(buffer, ".\n") == 0) {
            break;
        }

        strcat(message, buffer);
    }

    char end[] = "\r\n.\r\n";

    if (send(sockfd, message, strlen(message), 0) != strlen(message)) {
        printf("Failed to send message\n");
        exit(EXIT_FAILURE);
    }

    if (send(sockfd, end, strlen(end), 0) != strlen(end)) {
        printf("Failed to terminate message\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeof(buffer));

    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (recv_bytes < 0) {
        printf("Error while receiving message\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(buffer, "250") == NULL) {
        printf("Invalid response from server\n");
        exit(EXIT_FAILURE);
    }

    char quit[] = "QUIT\r\n";

    if (send(sockfd, quit, strlen(quit), 0) != strlen(quit)) {
        printf("Failed to send QUIT command\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeof(buffer));

    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (recv_bytes < 0) {
        printf("Error while receiving message\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(buffer, "221") == NULL) {
        printf("Invalid response from server\n");
        exit(EXIT_FAILURE);
    }

    printf("Message sent successfully\n");

    close(sockfd);
    return 0;
}