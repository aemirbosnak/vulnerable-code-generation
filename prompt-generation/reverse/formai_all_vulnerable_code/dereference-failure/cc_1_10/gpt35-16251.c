//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_LEN 1024

typedef struct {
    char *from;
    char *to;
    char *subject;
    char *message;
} email_t;

int main(int argc, char* argv[]) {
    int sockfd, port;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_MESSAGE_LEN] = {0};
    char *server_host, *from_address, *to_address, *subject, *message;
    email_t email;
    
    if (argc != 3) {
        fprintf(stderr,"Usage: %s <server_host> <port>\n", argv[0]);
        return 1;
    }
    
    server_host = argv[1];
    port = atoi(argv[2]);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }
    
    server = gethostbyname(server_host);
    
    if (server == NULL) {
        fprintf(stderr,"Error: Host not found\n");
        return 1;
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }
    
    printf("Connected to server %s:%d\n", server_host, port);
    
    printf("Enter your email address: ");
    scanf("%ms", &from_address);
    
    printf("Enter recipient's email address: ");
    scanf("%ms", &to_address);
    
    printf("Enter email subject: ");
    scanf("%ms", &subject);
    
    printf("Enter email message: ");
    scanf("\n");
    message = (char *) malloc(MAX_MESSAGE_LEN * sizeof(char));
    fgets(message, MAX_MESSAGE_LEN, stdin);
    
    email.from = from_address;
    email.to = to_address;
    email.subject = subject;
    email.message = message;
    
    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", email.from, email.to, email.subject, email.message);
    
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error writing to server");
        return 1;
    }
    
    printf("Email sent successfully!\n");
    
    close(sockfd);
    free(from_address);
    free(to_address);
    free(subject);
    free(message);
    
    return 0;
}