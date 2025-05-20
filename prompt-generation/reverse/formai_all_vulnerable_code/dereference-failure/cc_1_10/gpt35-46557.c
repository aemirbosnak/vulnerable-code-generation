//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[4096];
    char recipient[100];
    
    if (argc < 2) {
        fprintf(stderr,"Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host '%s'\n", argv[1]);
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr,"Error: could not create socket\n");
        exit(1);
    }
    
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr,"Error: could not connect to socket\n");
        exit(1);
    }
    
    bzero(buffer, 4096);
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 4096);
    read(sockfd, buffer, 4096);
    printf("%s\n", buffer);
    
    bzero(recipient, 100);
    printf("Enter recipient email address: ");
    fgets(recipient, 100, stdin);
    strtok(recipient, "\n"); // remove trailing newline
    
    bzero(buffer, 4096);
    sprintf(buffer, "MAIL FROM: <%s>\r\n", argv[1]);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 4096);
    read(sockfd, buffer, 4096);
    printf("%s\n", buffer);
    
    bzero(buffer, 4096);
    sprintf(buffer, "RCPT TO: <%s>\r\n", recipient);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 4096);
    read(sockfd, buffer, 4096);
    printf("%s\n", buffer);
    
    bzero(buffer, 4096);
    sprintf(buffer, "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 4096);
    read(sockfd, buffer, 4096);
    printf("%s\n", buffer);
    
    bzero(buffer, 4096);
    printf("Enter email message (end message with '.\\n'): ");
    while (fgets(buffer, 4096, stdin) && strcmp(buffer, ".\n")) {
        write(sockfd, buffer, strlen(buffer));
        bzero(buffer, 4096);
    }
    
    bzero(buffer, 4096);
    sprintf(buffer, "\r\n.\r\n");
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 4096);
    read(sockfd, buffer, 4096);
    printf("%s\n", buffer);
    
    bzero(buffer, 4096);
    sprintf(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 4096);
    read(sockfd, buffer, 4096);
    printf("%s\n", buffer);
    
    close(sockfd);
    return 0;
}