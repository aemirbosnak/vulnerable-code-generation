//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
    char symbol[5];
    float price;
} Stock;

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    bcopy((char *) server->h_addr,
         (char *) &serv_addr.sin_addr.s_addr,
         server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Connected to stock market server.\n");

    char request[BUFFER_SIZE];
    strcpy(request, "GET ALL PRICES\n");

    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("ERROR sending request");
    }

    Stock stocks[10];
    int num_stocks = 0;

    char response[BUFFER_SIZE];
    while (recv(sockfd, response, BUFFER_SIZE, 0) > 0) {
        if (strstr(response, "Symbol:") != NULL) {
            sscanf(response, "Symbol: %s Price: %f", stocks[num_stocks].symbol, &stocks[num_stocks].price);
            num_stocks++;
        }
    }

    printf("Current stock prices:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: %.2f\n", stocks[i].symbol, stocks[i].price);
    }

    close(sockfd);
    return 0;
}