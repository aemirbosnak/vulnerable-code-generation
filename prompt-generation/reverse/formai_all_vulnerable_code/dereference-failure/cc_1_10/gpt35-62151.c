//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define BUFSIZE 8192

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];
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
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    printf("Welcome to My FTP Client! Let's Download a File: \n");

    int n;
    char cmd[BUFSIZE];

    while (1) {
        bzero(buffer, BUFSIZE);
        bzero(cmd, BUFSIZE);
        printf("ftp> ");
        fgets(cmd, BUFSIZE - 1, stdin);
        cmd[strcspn(cmd, "\n")] = '\0';

        n = write(sockfd, cmd, strlen(cmd));
        if (n < 0) 
             error("ERROR writing to socket");

        if (strcmp(cmd, "quit") == 0) {
            printf("Closing Connection: Goodbye!\n");
            break;
        }
        else if (strncmp(cmd, "get", 3) == 0) {
            char filename[BUFSIZE];
            FILE *fp;
            int filesize;
            bzero(filename, BUFSIZE);
            strcpy(filename, strtok(cmd + 4, " \n"));

            fp = fopen(filename, "wb");
            if (fp == NULL) {
                printf("ERROR: Unable to Open File.\n");
                continue;
            }

            read(sockfd, buffer, BUFSIZE - 1);
            sscanf(buffer, "%d", &filesize);

            bzero(buffer, BUFSIZE);
            while ((n = read(sockfd, buffer, BUFSIZE - 1)) > 0) {
                fwrite(buffer, sizeof(char), n, fp);
                if (n < BUFSIZE) break;
                bzero(buffer, BUFSIZE);
            }

            printf("Download Complete: %s [%d bytes]\n", filename, filesize);
            fclose(fp);
        }
        else {
            do {
                bzero(buffer, BUFSIZE);
                n = read(sockfd, buffer, BUFSIZE - 1);
                if (n < 0) 
                     error("ERROR reading from socket");
                printf("%s", buffer);
            } while (n == BUFSIZE - 1);
        }
    }

    close(sockfd);
    return 0;
}