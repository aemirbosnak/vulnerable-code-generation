//FormAI DATASET v1.0 Category: Email Client ; Style: rigorous
/* 
  Unique C Email Client Example Program
  Author: [Your Name Here]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    char hostname[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char recipient[BUFFER_SIZE];
    char body[BUFFER_SIZE];

    // Get Server Hostname
    printf("Enter server hostname: ");
    fgets(hostname, BUFFER_SIZE, stdin);
    strtok(hostname, "\n");

    // Get Server Port Number
    printf("Enter server port number: ");
    scanf("%d", &portno);

    // Clear stdin Buffer
    while((getchar()) != '\n');

    // Get Username And Password
    printf("Enter your username: ");
    fgets(username, BUFFER_SIZE, stdin);
    strtok(username, "\n");

    printf("Enter your password: ");
    fgets(password, BUFFER_SIZE, stdin);
    strtok(password, "\n");

    // Get Recipient And Body
    printf("Enter recipient's email address: ");
    fgets(recipient, BUFFER_SIZE, stdin);
    strtok(recipient, "\n");

    printf("Enter email body: ");
    fgets(body, BUFFER_SIZE, stdin);
    strtok(body, "\n");

    // Create Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get Server By Hostname
    server = gethostbyname(hostname);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Build Server Address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect To Server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Authenticate With Username And Password
    sprintf(buffer, "USER %s\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';

    sprintf(buffer, "PASS %s\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';

    printf("%s\n", buffer);

   // Send Email
    sprintf(buffer, "MAIL FROM:<%s>\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';

    sprintf(buffer, "RCPT TO:<%s>\n", recipient);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';

    sprintf(buffer, "DATA\n");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';

    sprintf(buffer, "Subject: Test Email\n%s\n.\n", body);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';

    sprintf(buffer, "QUIT\n");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}