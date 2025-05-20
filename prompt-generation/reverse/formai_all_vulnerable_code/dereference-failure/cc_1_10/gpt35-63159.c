//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#define MAX_BUFFER 1024
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define MAX_COMMAND 255
#define MAX_EMAILS 100

int main(int argc, char* argv[]) {

    // Check for correct number of arguments
    if (argc != 3) {
        printf("Error: Please include the server address and port number.\n");
        exit(1);
    }

    // Get server information
    char* server_name = argv[1];
    char* port = argv[2];
    struct hostent* server = gethostbyname(server_name);
    if (server == NULL) {
        printf("Error: Could not find server.\n");
        exit(1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    // Connect to server
    struct sockaddr_in server_address;
    bzero((char*) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(port));
    if (connect(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to server.\n");
        exit(1);
    }

    // Get username and password
    char username[MAX_USERNAME];
    printf("Username: ");
    fgets(username, MAX_USERNAME, stdin);
    username[strcspn(username, "\n")] = '\0';
    char password[MAX_PASSWORD];
    printf("Password: ");
    fgets(password, MAX_PASSWORD, stdin);
    password[strcspn(password, "\n")] = '\0';

    // Log in to server
    char login_command[MAX_COMMAND];
    snprintf(login_command, MAX_COMMAND, "LOGIN %s %s\r\n", username, password);
    write(sockfd, login_command, strlen(login_command));
    char buffer[MAX_BUFFER];
    if (read(sockfd, buffer, MAX_BUFFER) < 0) {
        printf("Error: Could not read server response.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Check for login success
    if (!strstr(buffer, "OK")) {
        printf("Error: Login failed.\n");
        exit(1);
    }

    // List emails
    write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
    bzero(buffer, MAX_BUFFER);
    if (read(sockfd, buffer, MAX_BUFFER) < 0) {
        printf("Error: Could not read server response.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Parse email list
    char* tokens[MAX_EMAILS];
    tokens[0] = strtok(buffer, " \r\n");
    int count = 1;
    while ((tokens[count] = strtok(NULL, " \r\n")) != NULL) {
        count++;
    }

    // Print email list
    printf("You have %d email(s):\n", count / 2);
    for (int i = 0; i < count; i += 2) {
        printf("%s %s\n", tokens[i], tokens[i+1]);
    }

    // Exit program
    write(sockfd, "LOGOUT\r\n", strlen("LOGOUT\r\n"));
    close(sockfd);
    return 0;
}