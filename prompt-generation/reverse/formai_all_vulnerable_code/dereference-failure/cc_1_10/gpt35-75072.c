//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110 // POP3 port

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s server_address username\n", argv[0]);
        exit(1);
    }

    char *server_address = argv[1];
    char *username = argv[2];
    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket");
        exit(1);
    }

    // Get host by name
    struct hostent *server = gethostbyname(server_address);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host: %s\n", server_address);
        exit(1);
    }

    // Fill in server address information
    struct sockaddr_in server_address_info;
    memset(&server_address_info, 0, sizeof(server_address_info));
    server_address_info.sin_family = AF_INET;
    server_address_info.sin_port = htons(PORT);
    memcpy(&server_address_info.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address_info, sizeof(server_address_info)) < 0) {
        perror("Connect");
        exit(1);
    }

    // Read greeting message
    char buffer[1024];
    bzero(buffer, 1024);
    read(sockfd, buffer, 1024);
    printf("%s", buffer);

    // Send username and password
    char message[256];
    sprintf(message, "USER %s\r\n", username);
    write(sockfd, message, strlen(message));
    bzero(buffer, 1024);
    read(sockfd, buffer, 1024);
    printf("%s", buffer);

    sprintf(message, "PASS %s\r\n", password);
    write(sockfd, message, strlen(message));
    bzero(buffer, 1024);
    read(sockfd, buffer, 1024);
    printf("%s", buffer);

    // List messages
    sprintf(message, "LIST\r\n");
    write(sockfd, message, strlen(message));
    bzero(buffer, 1024);
    read(sockfd, buffer, 1024);
    printf("%s", buffer);

    // Quit session
    sprintf(message, "QUIT\r\n");
    write(sockfd, message, strlen(message));

    // Close socket
    close(sockfd);

    printf("Email retrieval successful!\n");

    return 0;
}