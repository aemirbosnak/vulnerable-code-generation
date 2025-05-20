//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 21
#define MAXSIZE 1024

char* host = "ftp.server.com";

void login(int sockfd, char* user, char* pass) {
    char buffer[MAXSIZE];
    int n;
    bzero(buffer, MAXSIZE);

    // Send "USER [username]\r\n" command.
    sprintf(buffer, "USER %s\r\n", user);
    write(sockfd, buffer, strlen(buffer));

    // Receive response.
    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE);
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send "PASS [password]\r\n" command.
    sprintf(buffer, "PASS %s\r\n", pass);
    write(sockfd, buffer, strlen(buffer));

    // Receive response.
    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE);
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Logged in as %s.\n", user);
}

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAXSIZE];
    char user[100], pass[100];

    // Open socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        fprintf(stderr, "Error: Could not open socket.\n");

    // Get IP address of the FTP server.
    server = gethostbyname(host);
    if (server == NULL)
        fprintf(stderr, "Error: Could not find host %s.\n", host);

    // Initialize server address struct.
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to server.
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        fprintf(stderr, "Error: Could not connect to server.\n");

    // Receive greetings message.
    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE);
    if (n < 0)
        fprintf(stderr, "Error: Could not receive message from server.\n");
    printf("%s", buffer);

    // Login to FTP server.
    printf("Enter username: ");
    fgets(user, 100, stdin);
    strtok(user, "\n");

    printf("Enter password: ");
    fgets(pass, 100, stdin);
    strtok(pass, "\n");

    login(sockfd, user, pass);

    close(sockfd);

    return 0;
}