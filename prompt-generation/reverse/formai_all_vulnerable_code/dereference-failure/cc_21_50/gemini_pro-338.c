//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LEN 1024
#define MAX_CMDS 10
#define POP3_PORT 110

char *cmds[] = {"USER", "PASS", "STAT", "LIST", "RETR", "DELE", "TOP", "QUIT"};
char *user, *pass;

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_LEN], cmd[MAX_LEN], arg[MAX_LEN];
    int i, n;
    FILE *fp;

    user = "your_username";
    pass = "your_password";

    printf("Enter server IP: ");
    scanf("%s", buffer);
    server = gethostbyname(buffer);
    if (server == NULL) {
        printf("Error: no such host '%s'\n", buffer);
        return 1;
    }

    portno = POP3_PORT;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: socket creation failed\n");
        return 1;
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: connection failed\n");
        return 1;
    }

    printf("Connected to %s:%d\n", buffer, portno);

    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0) {
        printf("Error: read failed\n");
        return 1;
    }
    printf("%s", buffer);

    sprintf(cmd, "USER %s\r\n", user);
    n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        printf("Error: write failed\n");
        return 1;
    }
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0) {
        printf("Error: read failed\n");
        return 1;
    }
    printf("%s", buffer);

    sprintf(cmd, "PASS %s\r\n", pass);
    n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        printf("Error: write failed\n");
        return 1;
    }
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0) {
        printf("Error: read failed\n");
        return 1;
    }
    printf("%s", buffer);

    while (1) {
        printf("Enter command: ");
        scanf("%s", cmd);
        for (i = 0; i < MAX_CMDS; i++) {
            if (strcmp(cmd, cmds[i]) == 0) {
                break;
            }
        }
        if (i == MAX_CMDS) {
            printf("Invalid command\n");
            continue;
        }
        if (strcmp(cmd, "QUIT") == 0) {
            break;
        }
        if (i >= 2 && i <= 5) {
            printf("Enter argument: ");
            scanf("%s", arg);
            sprintf(buffer, "%s %s\r\n", cmd, arg);
        } else {
            sprintf(buffer, "%s\r\n", cmd);
        }
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            printf("Error: write failed\n");
            return 1;
        }
        n = read(sockfd, buffer, MAX_LEN);
        if (n < 0) {
            printf("Error: read failed\n");
            return 1;
        }
        printf("%s", buffer);
        if (i == 4) {
            sscanf(buffer, "+OK %d %d", &n, &i);
            fp = fopen("email.txt", "w");
            if (fp == NULL) {
                printf("Error: could not open file\n");
                return 1;
            }
            while (n--) {
                n = read(sockfd, buffer, MAX_LEN);
                if (n < 0) {
                    printf("Error: read failed\n");
                    return 1;
                }
                fwrite(buffer, 1, n, fp);
            }
            fclose(fp);
            printf("Email saved to 'email.txt'\n");
        }
    }

    close(sockfd);
    return 0;
}