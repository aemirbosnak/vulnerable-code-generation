//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define MAX_MSG_SIZE 1000

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_MSG_SIZE];
    int n;
    char client_msg[MAX_MSG_SIZE];
    int client_msg_length = 0;

    if (argc!= 2) {
        printf("Usage: %s <hostname> \n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(1);
    }

    portno = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    while (1) {
        n = read(sockfd, buffer, MAX_MSG_SIZE);
        if (n <= 0) {
            printf("ERROR reading from socket\n");
            break;
        }
        printf("%s", buffer);

        printf("\nEnter your message : ");
        fgets(client_msg, MAX_MSG_SIZE, stdin);
        client_msg_length = strlen(client_msg);
        if (send(sockfd, client_msg, client_msg_length, 0) < 0) {
            perror("ERROR sending message");
            exit(1);
        }
    }

    return 0;
}