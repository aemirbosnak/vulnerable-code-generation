//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_SIZE 1000
#define PORT 21

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in addr;
    struct hostent *host;

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: Unknown host %s\n", argv[1]);
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)host->h_addr_list[0]));
    addr.sin_port = htons(PORT);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[MAX_SIZE];
    int n;

    // Login
    read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);
    write(sockfd, "USER anonymous\r\n", strlen("USER anonymous\r\n"));
    read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);
    write(sockfd, "PASS guest@\r\n", strlen("PASS guest@\r\n"));
    read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);

    // Enter Passive Mode
    write(sockfd, "PASV\r\n", strlen("PASV\r\n"));
    read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);
    char address[20];
    int port;
    for (int i = 0; i < strlen(buffer); i++) {
        if (isdigit(buffer[i])) {
            sscanf(&buffer[i], "%d,%d,%d,%d,%d,%d",
                   &n, &n, &n, &n, &port, &n);
            break;
        }
    }
    sprintf(address, "%d.%d.%d.%d", addr.sin_addr.s_addr&0xff,
            (addr.sin_addr.s_addr>>8)&0xff, (addr.sin_addr.s_addr>>16)&0xff,
            (addr.sin_addr.s_addr>>24)&0xff);

    // Connect to Data Channel
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(address);
    addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Retrieve file
    write(sockfd, "RETR welcome.msg\r\n", strlen("RETR welcome.msg\r\n"));
    read(sockfd, buffer, MAX_SIZE);
    if (strncmp(buffer, "550", 3) == 0) {
        printf("Error: File not found\n");
        exit(1);
    }
    FILE *fp = fopen("welcome.msg", "w");
    while ((n = read(sockfd, buffer, MAX_SIZE - 1)) > 0) {
        fwrite(buffer, n, 1, fp);
    }
    fclose(fp);

    // Close connection
    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);
    close(sockfd);

    return 0;
}