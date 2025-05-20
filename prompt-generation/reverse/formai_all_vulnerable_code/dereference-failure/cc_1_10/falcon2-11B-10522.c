//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

void ftp_connect(char *host, char *user, char *pass) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in socket creation\n");
        exit(0);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        printf("Error in gethostbyname\n");
        exit(0);
    }

    portno = ntohs(*(unsigned short *)server->h_addr_list[0]);

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error in connect\n");
        exit(0);
    }

    fp = fopen("/etc/passwd", "r");
    if (fp == NULL) {
        printf("Error in fopen\n");
        exit(0);
    }

    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    char *host = "localhost";
    char *user = "ftp";
    char *pass = "ftp";
    char *command;

    ftp_connect(host, user, pass);

    printf("Please enter your command: ");
    scanf("%s", &command);

    while (strcmp(command, "quit")!= 0) {
        printf("%s\n", command);
        fflush(stdout);
        sleep(1);
        system(command);
        printf("Please enter your command: ");
        scanf("%s", &command);
    }

    return 0;
}