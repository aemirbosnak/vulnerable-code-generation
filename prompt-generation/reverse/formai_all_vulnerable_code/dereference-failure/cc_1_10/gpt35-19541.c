//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LEN 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_LEN];
    char user[MAX_LEN];
    char pass[MAX_LEN];

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
        
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    printf("Connected to server %s:%d\n", argv[1], portno);

    /* Read server response */
    memset(buffer, 0, MAX_LEN);
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s\n", buffer);

    /* Send username */
    printf("Username: ");
    fgets(user, MAX_LEN, stdin);
    user[strcspn(user, "\n")] = 0;
    sprintf(buffer, "USER %s\r\n", user);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    /* Read server response */
    memset(buffer, 0, MAX_LEN);
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s\n", buffer);

    /* Send password */
    printf("Password: ");
    fgets(pass, MAX_LEN, stdin);
    pass[strcspn(pass, "\n")] = 0;
    sprintf(buffer, "PASS %s\r\n", pass);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    /* Read server response */
    memset(buffer, 0, MAX_LEN);
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s\n", buffer);

    /* Send STAT command */
    memset(buffer, 0, MAX_LEN);
    sprintf(buffer, "STAT\r\n");

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    /* Read server response */
    memset(buffer, 0, MAX_LEN);
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s\n", buffer);

    /* Send LIST command */
    memset(buffer, 0, MAX_LEN);
    sprintf(buffer, "LIST\r\n");

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");

    /* Read server response */
    memset(buffer, 0, MAX_LEN);
    while (1) {
        n = read(sockfd, buffer, MAX_LEN);
        if (n < 0) 
            error("ERROR reading from socket");

        printf("%s", buffer);

        if (strstr(buffer, ".\r\n") != NULL) break;

        memset(buffer, 0, MAX_LEN);
    }

    close(sockfd);
    return 0;
}