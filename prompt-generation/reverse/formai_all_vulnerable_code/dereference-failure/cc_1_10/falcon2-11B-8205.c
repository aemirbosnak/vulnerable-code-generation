//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    char buffer[256];
    char *word;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    word = argv[1];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    portno = htons(atoi(argv[2]));

    struct sockaddr_in serv_addr;
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    int num_matches = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen failed");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        if (strstr(buffer, word)!= NULL) {
            num_matches++;
        }
    }

    fclose(fp);

    sprintf(buffer, "%d\n", num_matches);

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    close(sockfd);
    return 0;
}