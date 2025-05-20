//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void execute_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
}

void connect_to_ftp(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    host = gethostbyname(hostname);
    if (host == NULL) error("No such host");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Connection failed");

    // Getting server response
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    execute_command(sockfd, "USER anonymous");
    execute_command(sockfd, "PASS guest@example.com");
    
    // Main loop to take user input
    char command[BUFFER_SIZE];
    while (1) {
        printf("ftp> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting FTP client.\n");
            break;
        } else if (strcmp(command, "") != 0) {
            execute_command(sockfd, command);
        }
    }

    close(sockfd);
}

int main(void) {
    const char *hostname = "ftp.dlptest.com"; // Example FTP server
    connect_to_ftp(hostname);
    return 0;
}