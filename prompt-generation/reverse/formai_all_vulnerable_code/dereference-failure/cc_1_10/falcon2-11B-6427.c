//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

// Function to get the local IP address
void get_ip_address(char *ip_address) {
    int sockfd, n;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    gethostname(server->h_name, sizeof(server->h_name));
    server->h_length = sizeof(server->h_name);

    inet_ntop(AF_INET, &((struct sockaddr_in*)server->h_addr)->sin_addr, ip_address, sizeof(ip_address));
    close(sockfd);
}

// Function to send a message to the server
void send_message(int sockfd, char *message) {
    int n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("Error writing to socket");
    }
}

// Function to receive a message from the server
void receive_message(int sockfd, char *message, int max_length) {
    int n = read(sockfd, message, max_length);
    if (n < 0) {
        perror("Error reading from socket");
    }
}

int main(int argc, char *argv[]) {
    char message[256];
    char ip_address[16];

    get_ip_address(ip_address);
    printf("Your local IP address is: %s\n", ip_address);

    int sockfd, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int opt = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(8080);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    while (1) {
        printf("> ");
        fgets(message, sizeof(message), stdin);
        send_message(sockfd, message);
        receive_message(sockfd, message, sizeof(message));
        printf("%s\n", message);
    }
    close(sockfd);
    return 0;
}