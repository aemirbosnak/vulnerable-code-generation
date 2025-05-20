//FormAI DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 25

int main(int argc, char *argv[]) {
    
    // Check if arguments are provided
    if (argc < 3) {
        printf("Usage: %s <server> <email_address>\n", argv[0]);
        exit(1);
    }

    // Get server information
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    // Create socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server.sin_zero), '\0', 8);    

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive welcome message
    char buffer[1024];
    memset(buffer, 0, 1024);
    if (recv(sockfd, buffer, 1024, 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buffer);

    // Login
    printf("Enter username: ");
    char username[50];
    fgets(username, 50, stdin);
    printf("Enter password: ");
    char password[50];
    fgets(password, 50, stdin);
    
    char login[100];
    sprintf(login, "AUTH LOGIN %s %s", username, password);
    send(sockfd, login, strlen(login), 0);

    // Send email
    printf("To: ");
    char to[50];
    fgets(to, 50, stdin);
    printf("Subject: ");
    char subject[50];
    fgets(subject, 50, stdin);
    printf("Message: ");
    char message[500];
    fgets(message, 500, stdin);

    char email[1000];
    sprintf(email, "MAIL FROM: <%s>\nRCPT TO: <%s>\nDATA\nSubject: %s\n%s.\nQUIT", argv[2], to, subject, message);
    send(sockfd, email, strlen(email), 0);

    // Close socket
    close(sockfd);

    return 0;
}