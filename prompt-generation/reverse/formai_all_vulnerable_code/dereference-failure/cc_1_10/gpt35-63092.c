//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAXBUFSIZE 1024

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAXBUFSIZE], username[MAXBUFSIZE], password[MAXBUFSIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    printf("POP3 Connection Established. Enter your username: ");
    fgets(username, MAXBUFSIZE, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter your password: ");
    fgets(password, MAXBUFSIZE, stdin);
    password[strcspn(password, "\n")] = '\0';

    /* Send username and password */
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    recv(sockfd, buffer, MAXBUFSIZE, 0);

    if (buffer[0] != '+') {
        printf("Authentication Error: %s", buffer);
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    recv(sockfd, buffer, MAXBUFSIZE, 0);

    if (buffer[0] != '+') {
        printf("Authentication Error: %s", buffer);
        exit(1);
    }

    printf("Authentication successful.\n");

    /* Receive list of emails */
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    recv(sockfd, buffer, MAXBUFSIZE, 0);

    if (buffer[0] != '+') {
        printf("Error: %s", buffer);
        exit(1);
    }

    printf("%s", buffer);

    while (1) {
        printf("Enter email number to retrieve (or 'q' to quit): ");
        fgets(buffer, MAXBUFSIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (!strcmp(buffer, "q")) {
            break;
        }

        /* Retrieve email */
        sprintf(buffer, "RETR %s\r\n", buffer);
        send(sockfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));

        recv(sockfd, buffer, MAXBUFSIZE, 0);

        if (buffer[0] != '+') {
            printf("Error: %s", buffer);
            exit(1);
        }

        while (1) {
            n = recv(sockfd, buffer, MAXBUFSIZE - 1, 0);

            if (n <= 0) {
                break;
            }

            buffer[n] = '\0';
            printf("%s", buffer);
        }

        printf("\n");
    }

    /* Quit */
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    recv(sockfd, buffer, MAXBUFSIZE, 0);

    if (buffer[0] != '+') {
        printf("Error: %s", buffer);
        exit(1);
    }

    printf("Disconnected from POP3 server.\n");

    close(sockfd);

    return 0;
}