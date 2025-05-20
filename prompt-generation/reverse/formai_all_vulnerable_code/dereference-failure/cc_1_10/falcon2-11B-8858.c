//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 21
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];
    char filename[BUFSIZE];
    FILE *fp;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <filename>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    portno = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }

    sprintf(buffer, "USER anonymous\r\n");
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, "PASS %s\r\n", "your_password_here");
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, "PWD\r\n");
    write(sockfd, buffer, strlen(buffer));

    bzero(filename, BUFSIZE);
    while (fgets(filename, BUFSIZE, stdin)) {
        if (strcmp(filename, "QUIT\r\n") == 0)
            break;

        sprintf(buffer, "STOR %s\r\n", filename);
        write(sockfd, buffer, strlen(buffer));
        read(sockfd, buffer, BUFSIZE);

        if (strcmp(buffer, "150") == 0) {
            fp = fopen(filename, "w");
            while (fgets(buffer, BUFSIZE, stdin)!= NULL)
                write(fp, buffer, strlen(buffer));
            fclose(fp);
        } else {
            fprintf(stderr, "ERROR storing file\n");
        }
    }

    sprintf(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));

    close(sockfd);
    return 0;
}