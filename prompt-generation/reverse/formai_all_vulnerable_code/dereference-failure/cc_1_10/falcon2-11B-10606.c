//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

/* SMTP client structure */
typedef struct smtpClient {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];
} smtpClient;

int main(int argc, char *argv[]) {
    /* Create a new SMTP client instance */
    smtpClient *smtp = malloc(sizeof(smtpClient));
    
    /* Initialize server address */
    memset(&smtp->serverAddr, 0, sizeof(smtp->serverAddr));
    smtp->serverAddr.sin_family = AF_INET;
    smtp->serverAddr.sin_port = htons(25);
    smtp->serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    /* Connect to server */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    if (connect(sockfd, (struct sockaddr *)&smtp->serverAddr, sizeof(struct sockaddr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    /* Send HELO command */
    strcpy(smtp->buffer, "HELO ");
    strcat(smtp->buffer, argv[1]);
    if (send(sockfd, smtp->buffer, strlen(smtp->buffer), 0) == -1) {
        perror("Error sending HELO command");
        exit(EXIT_FAILURE);
    }
    
    /* Send MAIL FROM command */
    strcpy(smtp->buffer, "MAIL FROM: ");
    strcat(smtp->buffer, argv[2]);
    if (send(sockfd, smtp->buffer, strlen(smtp->buffer), 0) == -1) {
        perror("Error sending MAIL FROM command");
        exit(EXIT_FAILURE);
    }
    
    /* Send RCPT TO command */
    strcpy(smtp->buffer, "RCPT TO: ");
    strcat(smtp->buffer, argv[3]);
    if (send(sockfd, smtp->buffer, strlen(smtp->buffer), 0) == -1) {
        perror("Error sending RCPT TO command");
        exit(EXIT_FAILURE);
    }
    
    /* Send DATA command */
    strcpy(smtp->buffer, "DATA\r\n");
    if (send(sockfd, smtp->buffer, strlen(smtp->buffer), 0) == -1) {
        perror("Error sending DATA command");
        exit(EXIT_FAILURE);
    }
    
    /* Send message body */
    strcpy(smtp->buffer, "Subject: Test message\r\n");
    strcat(smtp->buffer, "This is a test message.\r\n.\r\n");
    if (send(sockfd, smtp->buffer, strlen(smtp->buffer), 0) == -1) {
        perror("Error sending message body");
        exit(EXIT_FAILURE);
    }
    
    /* Send QUIT command */
    strcpy(smtp->buffer, "QUIT\r\n");
    if (send(sockfd, smtp->buffer, strlen(smtp->buffer), 0) == -1) {
        perror("Error sending QUIT command");
        exit(EXIT_FAILURE);
    }
    
    /* Close socket */
    close(sockfd);
    
    /* Free memory */
    free(smtp);
    
    return 0;
}