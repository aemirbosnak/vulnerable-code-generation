//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE], filename[256];
    FILE *fp = NULL;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error("ERROR opening socket");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
        error("ERROR connecting");

    printf("Connected to FTP server.\n");

    while (1) {
        printf("Enter filename to download from server: ");
        bzero(filename, 256);
        fgets(filename, 256, stdin);
        filename[strcspn(filename, "\n")] = '\0';

        if (strlen(filename) == 0)
            continue;

        sprintf(buffer, "RETR %s\r\n", filename);

        if (send(sockfd, buffer, strlen(buffer), 0) == -1)
            error("ERROR sending command");

        n = recv(sockfd, buffer, BUFSIZE, 0);

        if (n == -1)
            error("ERROR receiving response");

        if (strncmp(buffer, "550", 3) == 0) {
            printf("File does not exist on server.\n");
            continue;
        }

        fp = fopen(filename, "w");
        fwrite(buffer, 1, n, fp);

        while (n == BUFSIZE) {
            n = recv(sockfd, buffer, BUFSIZE, 0);

            if (n == -1)
                error("ERROR receiving data");

            fwrite(buffer, 1, n, fp);
        }

        fclose(fp);

        printf("File downloaded successfully.\n");
    }

    close(sockfd);

    return 0;
}