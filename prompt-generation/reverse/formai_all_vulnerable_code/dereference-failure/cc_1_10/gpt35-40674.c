//FormAI DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

#define REQUEST_SIZE 32
#define RESPONSE_SIZE 1024

int main(int argc, char* argv[]) {
    int sockfd, port, num_responses = 0, num_requests = 0;
    struct hostent *host;
    struct in_addr ipv4addr;
    char *request_buf, *response_buf, host_addr[INET_ADDRSTRLEN];
    struct sockaddr_in serv_addr;
    socklen_t serv_addr_len = sizeof(serv_addr);

    if (argc != 3) {
        fprintf(stderr,"Usage: %s <hostname/ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, serv_addr_len);
    serv_addr.sin_family = AF_INET;

    if (inet_pton(AF_INET, argv[1], &ipv4addr) != 1) {
        if ((host = gethostbyname(argv[1])) == NULL) {
            fprintf(stderr, "Failed to resolve hostname: %s\n", argv[1]);
            exit(EXIT_FAILURE);
        } else {
            serv_addr.sin_addr = *((struct in_addr*)(host->h_addr_list[0]));
        }
    } else {
        serv_addr.sin_addr = ipv4addr;
    }

    port = atoi(argv[2]);
    serv_addr.sin_port = htons(port);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    request_buf = (char*)malloc(REQUEST_SIZE);
    memset(request_buf, 0, REQUEST_SIZE);
    sprintf(request_buf, "Ping Test Request #%d", num_requests);

    response_buf = (char*)malloc(RESPONSE_SIZE);
    memset(response_buf, 0, RESPONSE_SIZE);

    while (num_requests < 10) {
        if (sendto(sockfd, request_buf, strlen(request_buf) + 1, 0, (struct sockaddr*)&serv_addr, serv_addr_len) < 0) {
            perror("Failed to send Ping Test request");
            exit(EXIT_FAILURE);
        }

        if (recvfrom(sockfd, response_buf, RESPONSE_SIZE, 0, (struct sockaddr*)&serv_addr, &serv_addr_len) < 0) {
            perror("Failed to receive Ping Test response");
            exit(EXIT_FAILURE);
        } else {
            inet_ntop(AF_INET, &(serv_addr.sin_addr), host_addr, INET_ADDRSTRLEN);
            printf("Ping Test Response from %s:%d -> %s\n", host_addr, ntohs(serv_addr.sin_port), response_buf);
            num_responses++;
        }

        num_requests++;
        memset(request_buf, 0, REQUEST_SIZE);
        sprintf(request_buf, "Ping Test Request #%d", num_requests);

        sleep(1);
    }

    printf("Ping Test Complete. %d requests sent, %d responses received\n", num_requests, num_responses);

    free(request_buf);
    free(response_buf);

    close(sockfd);

    return 0;
}