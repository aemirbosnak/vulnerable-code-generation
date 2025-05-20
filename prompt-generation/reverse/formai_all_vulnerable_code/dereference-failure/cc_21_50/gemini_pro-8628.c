//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in serv_addr;
    char buf[MAX_LINE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send USER command
    sprintf(buf, "USER %s\r\n", "username");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, MAX_LINE, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Invalid USER response received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send PASS command
    sprintf(buf, "PASS %s\r\n", "password");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, MAX_LINE, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Invalid PASS response received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send STAT command
    strcpy(buf, "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, MAX_LINE, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Invalid STAT response received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Parse response
    int num_messages, total_size;
    sscanf(buf, "+OK %d %d", &num_messages, &total_size);

    // Send LIST command
    strcpy(buf, "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, MAX_LINE, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Invalid LIST response received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Parse response
    int message_number, message_size;
    char *ptr;
    for (ptr = buf; ptr != NULL; ptr = strchr(ptr, '\n') + 1) {
        sscanf(ptr, "%d %d", &message_number, &message_size);
        printf("Message %d: %d bytes\n", message_number, message_size);
    }

    // Send QUIT command
    strcpy(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, MAX_LINE, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Invalid QUIT response received: %s\n", buf);
        return EXIT_FAILURE;
    }

    close(sockfd);
    return EXIT_SUCCESS;
}