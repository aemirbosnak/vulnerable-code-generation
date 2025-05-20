//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LEN 4096

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_MSG_LEN];
    if (argc < 3) {
        perror("Usage: ./smtp_client <ip_address> <port_no>");
        exit(EXIT_FAILURE);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(EXIT_FAILURE);
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }
    printf("Connnection established!\n");
    memset(buffer, 0, MAX_MSG_LEN);
    n = read(sockfd, buffer, MAX_MSG_LEN - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }
    buffer[MAX_MSG_LEN - 1] = '\0';
    printf("%s", buffer);
    printf("Ready to send email, please enter your message:\n");
    memset(buffer, 0, MAX_MSG_LEN);
    fgets(buffer, MAX_MSG_LEN - 1, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }
    printf("Message sent successfully!\n");
    memset(buffer, 0, MAX_MSG_LEN);
    n = read(sockfd, buffer, MAX_MSG_LEN - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }
    buffer[MAX_MSG_LEN - 1] = '\0';
    printf("%s", buffer);
    close(sockfd);
    return 0;
}