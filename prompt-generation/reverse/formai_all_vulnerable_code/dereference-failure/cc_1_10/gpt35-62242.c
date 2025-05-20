//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110 // POP3 Port
#define BUF_SIZE 1024
#define CRLF "\r\n"

int read_response(int sockfd, char* buffer) {
    int n = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    if (n < 0) {
        perror("Error reading response from server");
        return -1;
    }
    buffer[n] = '\0';
    printf("%s", buffer);
    return 0;
}

int main(int argc, char** argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent* server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get server host by name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    // Set server address properties
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr*) server->h_addr);
    bzero(&(server_addr.sin_zero), 8);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(struct sockaddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read server welcome message
    char* buffer = (char*) malloc(BUF_SIZE * sizeof(char));
    read_response(sockfd, buffer);
    free(buffer);

    // Send user credentials
    char user[BUF_SIZE];
    bzero(user, BUF_SIZE);
    printf("Username: ");
    fgets(user, BUF_SIZE, stdin);

    char* pass = getpass("Password: "); // read user's password

    char* auth_cmd = (char*) malloc((strlen(user) + strlen(pass) + 16) * sizeof(char));
    sprintf(auth_cmd, "USER %s" CRLF "PASS %s" CRLF, user, pass);

    if (send(sockfd, auth_cmd, strlen(auth_cmd), 0) < 0) {
        perror("Error sending auth command");
        exit(1);
    }
    free(auth_cmd);

    // Read server response to auth commands
    buffer = (char*) malloc(BUF_SIZE * sizeof(char));
    read_response(sockfd, buffer);

    // Send LIST command to server
    char* list_cmd = "LIST" CRLF;
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) < 0) {
        perror("Error sending LIST command");
        exit(1);
    }

    // Read server response to LIST command
    bzero(buffer, BUF_SIZE);
    read_response(sockfd, buffer);

    // Parse message sizes from the server response
    strtok(buffer, CRLF); // discard the first line (response message header)
    char* token = strtok(NULL, CRLF);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, CRLF);
    }
    free(buffer);

    // Send QUIT command to server
    char* quit_cmd = "QUIT" CRLF;
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) < 0) {
        perror("Error sending QUIT command");
        exit(1);
    }

    // Read server response to QUIT command
    buffer = (char*) malloc(BUF_SIZE * sizeof(char));
    read_response(sockfd, buffer);
    free(buffer);

    // Close the connection to the server
    close(sockfd);

    return 0;
}