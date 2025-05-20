//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define MAX_PACKET_SIZE 500

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <number of packets>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: host not found\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    memcpy(&dest_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
    dest_addr.sin_port = htons(80); // HTTP port

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    char response[MAX_PACKET_SIZE];
    char* request = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, argv[1]);
    strcat(request, "\r\n\r\n");

    int n = send(sock, request, strlen(request), 0);
    if (n < 0) {
        perror("Error sending request");
        exit(EXIT_FAILURE);
    }

    n = recv(sock, response, MAX_PACKET_SIZE, 0);
    if (n < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    printf("Response: %s\n", response);

    close(sock);
    return 0;
}