//GEMINI-pro DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PUZZLE_SIZE 100

char puzzle[PUZZLE_SIZE] = {0};

void init_puzzle() {
    for (int i = 0; i < PUZZLE_SIZE; i++) {
        puzzle[i] = ' ';
    }
}

void print_puzzle() {
    for (int i = 0; i < PUZZLE_SIZE; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        printf("%c", puzzle[i]);
    }
    printf("\n");
}

void solve_puzzle(char *buf, int len) {
    int x = 0, y = 0;
    for (int i = 0; i < len; i++) {
        switch (buf[i]) {
            case 'U':
                y--;
                break;
            case 'D':
                y++;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            default:
                break;
        }
        if (x < 0 || x >= 10 || y < 0 || y >= 10) {
            return;
        }
        if (puzzle[y * 10 + x] != ' ') {
            return;
        }
        puzzle[y * 10 + x] = '*';
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    init_puzzle();

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        return 1;
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            continue;
        }

        bzero(buffer, 256);
        int n = read(newsockfd, buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            close(newsockfd);
            continue;
        }

        solve_puzzle(buffer, n);

        n = write(newsockfd, puzzle, PUZZLE_SIZE);
        if (n < 0) {
            perror("ERROR writing to socket");
            close(newsockfd);
            continue;
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}