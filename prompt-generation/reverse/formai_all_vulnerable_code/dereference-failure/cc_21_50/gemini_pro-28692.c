//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];
    char command[BUFSIZE];
    char filename[BUFSIZE];
    int n, bytes_to_read;
    int portnum;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    portnum = atoi(argv[2]);

    /* create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* get the server's IP address */
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    /* set up the server's address */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portnum);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    /* connect to the server */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* main loop */
    while (1) {
        printf("ftp> ");
        fgets(command, BUFSIZE, stdin);

        /* parse the command */
        if (strncmp(command, "get", 3) == 0) {
            sscanf(command, "get %s", filename);
            bytes_to_read = atoi(command + 4);

            /* send the command to the server */
            n = write(sockfd, command, strlen(command));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            /* receive the file from the server */
            FILE *fp = fopen(filename, "w");
            if (fp == NULL) {
                perror("ERROR opening file");
                exit(1);
            }
            while (bytes_to_read > 0) {
                n = read(sockfd, buffer, BUFSIZE);
                if (n < 0) {
                    perror("ERROR reading from socket");
                    exit(1);
                }
                fwrite(buffer, 1, n, fp);
                bytes_to_read -= n;
            }
            fclose(fp);

            printf("File %s received.\n", filename);
        } else if (strncmp(command, "put", 3) == 0) {
            sscanf(command, "put %s", filename);

            /* send the command to the server */
            n = write(sockfd, command, strlen(command));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            /* send the file to the server */
            FILE *fp = fopen(filename, "r");
            if (fp == NULL) {
                perror("ERROR opening file");
                exit(1);
            }
            while (!feof(fp)) {
                n = fread(buffer, 1, BUFSIZE, fp);
                if (n < 0) {
                    perror("ERROR reading from file");
                    exit(1);
                }
                write(sockfd, buffer, n);
            }
            fclose(fp);

            printf("File %s sent.\n", filename);
        } else if (strncmp(command, "ls", 2) == 0) {
            /* send the command to the server */
            n = write(sockfd, command, strlen(command));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            /* receive the list of files from the server */
            while ((n = read(sockfd, buffer, BUFSIZE)) > 0) {
                printf("%s", buffer);
            }
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
        } else if (strncmp(command, "pwd", 3) == 0) {
            /* send the command to the server */
            n = write(sockfd, command, strlen(command));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            /* receive the current working directory from the server */
            n = read(sockfd, buffer, BUFSIZE);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
            printf("Current working directory: %s\n", buffer);
        } else if (strncmp(command, "quit", 4) == 0) {
            /* send the command to the server */
            n = write(sockfd, command, strlen(command));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            /* close the connection */
            close(sockfd);

            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}