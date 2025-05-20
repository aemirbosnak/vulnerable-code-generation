//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

// Define POP3 commands
#define POP3_USER       "USER"
#define POP3_PASS       "PASS"
#define POP3_STAT       "STAT"
#define POP3_LIST       "LIST"
#define POP3_RETR       "RETR"
#define POP3_QUIT       "QUIT"

// Function to connect to the server and authenticate
int connect_to_server(char *hostname, char *username, char *password) {
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    // Get the server address information
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Connect to the server
    portno = 110;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send username and password
    n = write(sockfd, username, strlen(username));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    n = write(sockfd, password, strlen(password));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Receive response
    char buf[1024];
    bzero(buf, 1024);
    n = read(sockfd, buf, 1024);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Response from server: %s\n", buf);

    // Disconnect from the server
    n = write(sockfd, POP3_QUIT, strlen(POP3_QUIT));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    close(sockfd);

    return 0;
}

// Function to retrieve messages
int get_messages(char *hostname, char *username, char *password) {
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buf[1024];

    // Get the server address information
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Connect to the server
    portno = 110;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send username and password
    n = write(sockfd, username, strlen(username));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    n = write(sockfd, password, strlen(password));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Receive response
    bzero(buf, 1024);
    n = read(sockfd, buf, 1024);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Response from server: %s\n", buf);

    // Disconnect from the server
    n = write(sockfd, POP3_QUIT, strlen(POP3_QUIT));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    close(sockfd);

    return 0;
}

int main() {
    char hostname[256];
    char username[256];
    char password[256];
    int portno;

    // Get the hostname and port number from the user
    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter port number: ");
    scanf("%d", &portno);

    // Get the username and password from the user
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Connect to the server and authenticate
    if (connect_to_server(hostname, username, password) < 0) {
        printf("Authentication failed\n");
        return 1;
    }

    // Retrieve messages
    if (get_messages(hostname, username, password) < 0) {
        printf("Failed to retrieve messages\n");
        return 1;
    }

    // Exit with success
    return 0;
}