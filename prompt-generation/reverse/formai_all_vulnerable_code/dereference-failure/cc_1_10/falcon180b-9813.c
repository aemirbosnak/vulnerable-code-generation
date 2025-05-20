//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define PORT 25
#define BUFFER_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char** argv) {
    if(argc!= 5) {
        printf("Usage: %s <host> <username> <password> <recipient>\n", argv[0]);
        return 1;
    }

    char* host = argv[1];
    char* username = argv[2];
    char* password = argv[3];
    char* recipient = argv[4];

    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        die("Failed to create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        die("Failed to connect to server");
    }

    printf("Connected to %s\n", host);

    char* auth_string = malloc(strlen(username) + strlen(password) + 10);
    sprintf(auth_string, "AUTH LOGIN\r\n%s\r\n%s", username, password);

    send(sockfd, auth_string, strlen(auth_string), 0);
    free(auth_string);

    char* response = malloc(MAX_LINE_LENGTH);
    while(fgets(response, MAX_LINE_LENGTH, stdin)!= NULL) {
        send(sockfd, response, strlen(response), 0);
    }

    close(sockfd);

    return 0;
}