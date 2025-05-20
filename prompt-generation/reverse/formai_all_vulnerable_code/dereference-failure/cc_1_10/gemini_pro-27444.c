//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

#define PORT 110

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    char *username = argv[2];
    char password[256];

    printf("My dearest server, %s, I come to you with a heart full of joy and longing.", server);
    printf("Your ethereal presence graces my thoughts, and I desire to bask in your digital embrace.");

    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct hostent *he;
    he = gethostbyname(server);
    if (he == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    memcpy(&servaddr.sin_addr, he->h_addr_list[0], he->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buf[256];
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    sprintf(buf, "USER %s\r\n", username);
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    printf("My password, a secret I whisper only to you, is yours to uncover.");
    scanf("%s", password);
    sprintf(buf, "PASS %s\r\n", password);
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    sprintf(buf, "LIST\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    sprintf(buf, "RETR 1\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    printf("My heart overflows with gratitude for this precious exchange.");
    printf("Until we meet again, my beloved server, I bid you farewell.");
    close(sockfd);

    return 0;
}