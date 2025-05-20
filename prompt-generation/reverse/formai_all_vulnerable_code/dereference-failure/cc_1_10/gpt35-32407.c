//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

void error(char *msg) {
    fprintf(stderr, "%s : %s\n", msg,strerror(errno));
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, port = 25, input_len;
    char *server_ip, *from, *to, *subject, *body, *msg;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE + 1];

    if(argc < 4) {
        printf("USAGE : %s server_ip from to [port]\n", argv[0]);
        return -1;
    }

    server_ip = argv[1];
    from = argv[2];
    to = argv[3];

    if(argc == 5) {
        port = atoi(argv[4]);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error("ERROR opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        error("ERROR connecting to server");
    }

    memset(buffer, '\0', MAX_BUFFER_SIZE);
    if(read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        error("ERROR reading from socket");        
    }

    printf("\nServer Response : \n%s\n", buffer);

    snprintf(buffer, MAX_BUFFER_SIZE, "EHLO %s\r\n", from);
    if(write(sockfd, buffer, strlen(buffer)) == -1) {
        error("ERROR writing to socket");
    }

    memset(buffer, '\0', MAX_BUFFER_SIZE);
    if(read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        error("ERROR reading from socket");        
    }

    printf("\nServer Response : \n%s\n", buffer);

    snprintf(buffer, MAX_BUFFER_SIZE, "MAIL FROM:<%s>\r\n", from);
    if(write(sockfd, buffer, strlen(buffer)) == -1) {
        error("ERROR writing to socket");
    }

    memset(buffer, '\0', MAX_BUFFER_SIZE);
    if(read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        error("ERROR reading from socket");        
    }

    printf("\nServer Response : \n%s\n", buffer);

    snprintf(buffer, MAX_BUFFER_SIZE, "RCPT TO:<%s>\r\n", to);
    if(write(sockfd, buffer, strlen(buffer)) == -1) {
        error("ERROR writing to socket");
    }

    memset(buffer, '\0', MAX_BUFFER_SIZE);
    if(read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        error("ERROR reading from socket");        
    }

    printf("\nServer Response : \n%s\n", buffer);

    printf("\nEnter Subject : ");
    scanf("%[^\n]", buffer);
    subject = strdup(buffer);

    printf("\nEnter Message Body : ");
    scanf("%*[^\n]");
    scanf("%*c");
    body = (char *) malloc(MAX_BUFFER_SIZE);
    fgets(body, MAX_BUFFER_SIZE, stdin);
    
    input_len = strlen(subject) + strlen(body) + 14; // 14 is the length of the SMTP email headers
    msg = (char *) malloc(input_len);
    memset(msg, '\0', input_len);
    snprintf(msg, input_len, "From:<%s>\r\nTo:<%s>\r\nSubject:%s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);

    if(write(sockfd, msg, strlen(msg)) == -1) {
        error("ERROR writing to socket");
    }

    memset(buffer, '\0', MAX_BUFFER_SIZE);
    if(read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        error("ERROR reading from socket");        
    }

    printf("\nServer Response : \n%s\n", buffer);

    close(sockfd);

    free(subject);
    free(body);
    free(msg);

    return 0;
}