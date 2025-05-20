//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in addr;
    int sockfd, portno, n;
    unsigned char msg[100];
    char *command;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up address structure
    memset((char *)&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Read from file
    FILE *fp = fopen(argv[3], "r");
    if (fp == NULL) {
        printf("ERROR opening file");
        exit(1);
    }
    while (fgets(msg, sizeof(msg), fp)) {
        command = msg;
        n = strlen(command);
        strncpy(msg, command, n);
        msg[n] = '\0';
        if (write(sockfd, msg, strlen(msg)) < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
    fclose(fp);

    // Close socket
    close(sockfd);

    return 0;
}