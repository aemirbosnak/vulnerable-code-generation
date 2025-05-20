//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    char file_name[256];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr.s_addr);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    printf("Connected to FTP server.\n");

    printf("Enter file name to download: ");
    fgets(file_name, 256, stdin);
    strtok(file_name, "\n"); // remove trailing newline character

    n = write(sockfd, file_name, strlen(file_name));
    if (n < 0) 
        error("ERROR writing to socket");

    FILE *fp;
    fp = fopen(file_name, "wb");

    printf("Downloading file %s...\n", file_name);

    while ((n = read(sockfd, buffer, 1024)) > 0)
    {
        fwrite(buffer, sizeof(char), n, fp);
    }

    if (n < 0)
        error("ERROR reading from socket");

    printf("File %s downloaded successfully.\n", file_name);

    fclose(fp);
    close(sockfd);

    return 0;
}