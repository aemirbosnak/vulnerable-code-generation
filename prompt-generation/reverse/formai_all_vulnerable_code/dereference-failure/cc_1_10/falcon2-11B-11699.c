//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFSIZE 1024
#define HOST "example.com"
#define PORT 110

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buff[BUFFSIZE], username[50], password[50], *ptr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Resolve hostname
    if ((server = gethostbyname(HOST)) == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Copy in the address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Prompt for username
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove trailing newline

    // Prompt for password
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove trailing newline

    // Send username and password
    ptr = buff;
    strcat(ptr, "USER ");
    strcat(ptr, username);
    strcat(ptr, " ");
    strcat(ptr, password);
    n = send(sockfd, buff, strlen(buff), 0);
    if (n < 0) {
        perror("ERROR sending data");
        exit(1);
    }

    // Read response
    ptr = buff;
    n = recv(sockfd, ptr, BUFFSIZE, 0);
    if (n <= 0) {
        perror("ERROR reading data");
        exit(1);
    }
    ptr[n] = '\0';

    // Display response
    printf("%s", ptr);

    // Close socket
    close(sockfd);

    return 0;
}