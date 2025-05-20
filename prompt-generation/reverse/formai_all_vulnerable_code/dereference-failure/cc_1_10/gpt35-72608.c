//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 2048

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
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

    printf("Welcome to FTP client\n");
    printf("Type 'help' to get started\n");

    while (1) {
        printf("ftp> ");
        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);

        if (strncmp(buffer, "help", 4) == 0) {
            printf("Here are the available commands:\n");
            printf("help\t\t- show this help message\n");
            printf("quit\t\t- exit the FTP client\n");
            printf("get [path]\t- download a file\n");
            printf("put [path]\t- upload a file\n");

        } else if (strncmp(buffer, "quit", 4) == 0) {
            n = write(sockfd, buffer, strlen(buffer));
            close(sockfd);
            return 0;

        } else if (strncmp(buffer, "get", 3) == 0) {
            n = write(sockfd, buffer, strlen(buffer));
            bzero(buffer, BUFFER_SIZE);
            n = read(sockfd, buffer, BUFFER_SIZE);
            if (n < 0) 
                error("ERROR reading from socket");
            printf("%s", buffer);

            char *token = strtok(buffer, " ");
            char *filename = strtok(NULL, " ");
            if (filename != NULL) {
                FILE *fp = fopen(filename, "w");
                while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
                    fwrite(buffer, sizeof(char), n, fp);
                }
                fclose(fp);
                printf("File saved as %s\n", filename);
            }

        } else if (strncmp(buffer, "put", 3) == 0) {
            n = write(sockfd, buffer, strlen(buffer));
            bzero(buffer, BUFFER_SIZE);
            n = read(sockfd, buffer, BUFFER_SIZE);
            if (n < 0) 
                error("ERROR reading from socket");
            printf("%s", buffer);

            char *token = strtok(buffer, " ");
            char *filename = strtok(NULL, " ");
            if (filename != NULL) {
                FILE *fp = fopen(filename, "r");
                if (fp != NULL) {
                    while ((n = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
                        write(sockfd, buffer, n);
                    }
                    fclose(fp);
                    printf("%s uploaded successfully\n", filename);
                } else {
                    printf("Failed to open %s\n", filename);
                }
            }
        } else {
            printf("Unknown command. Type 'help' for help.\n");
        }
    }
}