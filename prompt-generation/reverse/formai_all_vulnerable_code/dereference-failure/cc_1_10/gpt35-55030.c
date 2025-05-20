//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return -1;
    }

    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        printf("Error connecting to server.\n");
        return -1;
    }

    printf("Connected to server.\n");

    while (1) {
        printf("Please enter a command: ");
        fgets(buffer, MAX_SIZE, stdin);

        if (strcmp(buffer, "quit\n") == 0 || strcmp(buffer, "exit\n") == 0) {
            break;
        }

        send(sockfd, buffer, strlen(buffer), 0);
        
        memset(buffer, '\0', sizeof(buffer));
        recv(sockfd, buffer, MAX_SIZE, 0);

        printf("%s", buffer);
    }
    
    close(sockfd);

    return 0;
}