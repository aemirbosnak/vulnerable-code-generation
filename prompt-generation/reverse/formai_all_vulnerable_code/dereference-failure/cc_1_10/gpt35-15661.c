//FormAI DATASET v1.0 Category: Socket programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9000

int main(int argc, char *argv[])
{
    if(argc < 2){
        fprintf(stderr, "Usage: %s [number]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int number = atoi(argv[1]);
    int sockfd, newsockfd, len, n;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }
    listen(sockfd, 5);
    len = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &len);

    if(newsockfd < 0){
        perror("ERROR on accept");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    memset(buffer, 0, 256);
    n = read(newsockfd, buffer, 255);
    if(n < 0){
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("Here is the mathematical expression: %s%s\n", buffer, argv[1]);
    int result = atoi(buffer) + number;
    printf("The result of the expression is %d\n", result);

    memset(buffer, 0, 256);
    sprintf(buffer, "%d", result);
    n = write(newsockfd, buffer, strlen(buffer));
    if(n < 0){
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }
    close(newsockfd);
    close(sockfd);
    return 0;
}