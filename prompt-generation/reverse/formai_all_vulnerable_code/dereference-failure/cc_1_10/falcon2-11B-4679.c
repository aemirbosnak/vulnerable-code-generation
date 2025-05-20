//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

// function to check if a given IP address is valid or not
int is_valid_ip(char* ip_address) {
    struct sockaddr_in client_address;
    struct hostent *host_ent;
    char* ip_copy = malloc(strlen(ip_address) + 1);
    strcpy(ip_copy, ip_address);
    int addrlen = sizeof(client_address);

    if ((host_ent = gethostbyname(ip_copy)) == NULL) {
        return 0;
    }

    if (inet_pton(AF_INET, ip_copy, &client_address) <= 0) {
        return 0;
    }

    return 1;
}

// function to check if a given port number is valid or not
int is_valid_port(int port) {
    return (port > 0 && port < 65536);
}

// function to check if a given TCP connection is valid or not
int is_valid_connection(int sockfd, int port) {
    struct sockaddr_in client_address;
    struct hostent *host_ent;
    char* ip_copy = malloc(INET_ADDRSTRLEN + 1);
    char* port_copy = malloc(7 + 1);

    if ((host_ent = gethostbyname("localhost")) == NULL) {
        return 0;
    }

    if (inet_pton(AF_INET, "127.0.0.1", &client_address) <= 0) {
        return 0;
    }

    if (is_valid_ip("127.0.0.1") == 0) {
        return 0;
    }

    if (is_valid_port(port) == 0) {
        return 0;
    }

    strcpy(ip_copy, inet_ntoa(client_address.sin_addr));
    sprintf(port_copy, "%d", port);

    if (strcmp(ip_copy, "127.0.0.1")!= 0) {
        return 0;
    }

    return 1;
}

// main function
int main() {
    int sockfd, port;
    struct sockaddr_in server_address;
    struct hostent *server_host_ent;

    if ((server_host_ent = gethostbyname("localhost")) == NULL) {
        printf("Error: Cannot find localhost\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: socket");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr = *((struct in_addr*)server_host_ent->h_addr);

    if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error: bind");
        return 1;
    }

    listen(sockfd, 5);

    while (1) {
        int client_sockfd, addrlen;
        struct sockaddr_in client_address;

        client_sockfd = accept(sockfd, (struct sockaddr*)&client_address, &addrlen);
        if (client_sockfd < 0) {
            perror("Error: accept");
            continue;
        }

        if (is_valid_connection(client_sockfd, ntohs(client_address.sin_port)) == 0) {
            close(client_sockfd);
            continue;
        }

        char message[100];
        if (read(client_sockfd, message, 100) > 0) {
            printf("Received message: %s\n", message);
        }

        if (write(client_sockfd, "HTTP/1.1 200 OK\r\n\r\n", 32)!= 32) {
            perror("Error: write");
            close(client_sockfd);
        }

        close(client_sockfd);
    }

    return 0;
}