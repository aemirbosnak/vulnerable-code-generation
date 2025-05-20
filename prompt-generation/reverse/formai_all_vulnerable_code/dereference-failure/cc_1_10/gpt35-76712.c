//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MSG_SIZE 8192

// Function to print error messages
void print_error(const char* message) {
    perror(message);
    exit(1);
}

// Function to establish a connection with the server
int connect_to_server(const char* server_name, int portno) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent* server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        print_error("Error opening socket");
    }

    server = gethostbyname(server_name);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        print_error("Error connecting");
    }

    return sockfd;
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MSG_SIZE];
    char user[256];
    char password[256];
    char request[MSG_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    // Establish connection with the server
    sockfd = connect_to_server(argv[1], atoi(argv[2]));

    // Receive the welcome message from the server and print it
    bzero(buffer, MSG_SIZE);
    n = read(sockfd, buffer, MSG_SIZE-1);
    if (n < 0) {
        print_error("Error reading from socket");
    }
    printf("%s", buffer);

    // Get user input and send authentication request to the server
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", password);
    sprintf(request, "USER %s\r\n", user);
    write(sockfd, request, strlen(request));
    bzero(buffer, MSG_SIZE);
    n = read(sockfd, buffer, MSG_SIZE-1);
    if (n < 0) {
        print_error("Error reading from socket");
    }
    printf("%s", buffer);
    sprintf(request, "PASS %s\r\n", password);
    write(sockfd, request, strlen(request));
    bzero(buffer, MSG_SIZE);
    n = read(sockfd, buffer, MSG_SIZE-1);
    if (n < 0) {
        print_error("Error reading from socket");
    }
    printf("%s", buffer);

    // Send LIST request to the server and print the response
    sprintf(request, "LIST\r\n");
    write(sockfd, request, strlen(request));
    bzero(buffer, MSG_SIZE);
    n = read(sockfd, buffer, MSG_SIZE-1);
    if (n < 0) {
        print_error("Error reading from socket");
    }
    printf("%s", buffer);

    // Send RETR request to the server for the first email in the inbox and print the response
    sprintf(request, "RETR 1\r\n");
    write(sockfd, request, strlen(request));
    bzero(buffer, MSG_SIZE);
    n = read(sockfd, buffer, MSG_SIZE-1);
    if (n < 0) {
        print_error("Error reading from socket");
    }
    printf("%s", buffer);

    close(sockfd);
    return 0;
}