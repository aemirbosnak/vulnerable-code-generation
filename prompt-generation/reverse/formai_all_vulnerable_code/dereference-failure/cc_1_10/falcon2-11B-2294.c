//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_EMAIL_LEN 256
#define MAX_PASSWORD_LEN 64
#define MAX_SERVER_IP_LEN 256
#define MAX_SERVER_PORT_LEN 256

// Function to connect to the IMAP server
int connect_to_server(char* email, char* password, char* server_ip, int port) {
    int sockfd, numbytes;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_EMAIL_LEN];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    // Resolve the server's IP address
    server = gethostbyname(server_ip);
    if (server == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Login to the server
    sprintf(buffer, "LOGIN %s %s", email, password);
    numbytes = write(sockfd, buffer, strlen(buffer));
    if (numbytes < 0) {
        printf("Error logging in to server\n");
        exit(1);
    }

    // Select the INBOX folder
    sprintf(buffer, "SELECT INBOX");
    numbytes = write(sockfd, buffer, strlen(buffer));
    if (numbytes < 0) {
        printf("Error selecting INBOX folder\n");
        exit(1);
    }

    // Fetch all emails from the INBOX folder
    sprintf(buffer, "LIST \"\" \"*\"");
    numbytes = write(sockfd, buffer, strlen(buffer));
    if (numbytes < 0) {
        printf("Error fetching emails\n");
        exit(1);
    }

    // Read the response from the server
    bzero(buffer, MAX_EMAIL_LEN);
    numbytes = read(sockfd, buffer, MAX_EMAIL_LEN);
    if (numbytes < 0) {
        printf("Error reading server response\n");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <email> <password>\n", argv[0]);
        exit(1);
    }

    char email[MAX_EMAIL_LEN];
    char password[MAX_PASSWORD_LEN];
    char server_ip[MAX_SERVER_IP_LEN];
    int port = 143;

    strcpy(email, argv[1]);
    strcpy(password, argv[2]);
    strcpy(server_ip, "localhost");

    connect_to_server(email, password, server_ip, port);

    return 0;
}