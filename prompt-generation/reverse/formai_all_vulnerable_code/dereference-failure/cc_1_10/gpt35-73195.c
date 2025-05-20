//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAXSIZE 1024

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXSIZE];
    char username[MAXSIZE];
    char password[MAXSIZE];
    char email[MAXSIZE];
    char *ptr;
    
    printf("Enter POP3 server name: ");
    fgets(buffer, MAXSIZE, stdin);
    strtok(buffer, "\n");
    server = gethostbyname(buffer);
    
    if (server == NULL) {
        fprintf(stderr, "Error: no such host.\n");
        exit(0);
    }
    
    printf("Enter POP3 server port number: ");
    fgets(buffer, MAXSIZE, stdin);
    portno = atoi(buffer);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        perror("Error opening socket.\n");
        exit(0);
    }
    
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server ->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting.\n");
        exit(0);
    }
    
    n = recv(sockfd, buffer, MAXSIZE, 0);
    buffer[n] = '\0';
    printf("%s", buffer);
    
    printf("Enter username: ");
    fgets(username, MAXSIZE, stdin);
    printf("Enter password: ");
    fgets(password, MAXSIZE, stdin);
    
    snprintf(buffer, MAXSIZE, "USER %s", username);
    send(sockfd, buffer, strlen(buffer), 0);
    
    n = recv(sockfd, buffer, MAXSIZE, 0);
    buffer[n] = '\0';
    printf("%s", buffer);
    
    snprintf(buffer, MAXSIZE, "PASS %s", password);
    send(sockfd, buffer, strlen(buffer), 0);
    
    n = recv(sockfd, buffer, MAXSIZE, 0);
    buffer[n] = '\0';
    printf("%s", buffer);
    
    snprintf(buffer, MAXSIZE, "LIST");
    send(sockfd, buffer, strlen(buffer), 0);
    
    n = recv(sockfd, buffer, MAXSIZE, 0);
    buffer[n] = '\0';
    printf("%s", buffer);
    
    printf("Enter email number to read: ");
    fgets(email, MAXSIZE, stdin);
    ptr = strtok(email, "\n");
    
    snprintf(buffer, MAXSIZE, "RETR %s", ptr);
    send(sockfd, buffer, strlen(buffer), 0);
    
    n = recv(sockfd, buffer, MAXSIZE, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);
    
    close(sockfd);
    return 0;
}