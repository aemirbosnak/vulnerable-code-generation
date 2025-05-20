//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <time.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 3000 // 3 seconds

void print_error(char *error_message){
    fprintf(stderr, "%s\n", error_message);
    exit(1);
}

void monitor_QoS(char *hostname){
    struct hostent *host = gethostbyname(hostname);
    if(host == NULL){
        print_error("Error: Could not resolve hostname.");
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd == -1){
        print_error("Error: Could not create socket.");
    }

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = TIMEOUT * 1000;
    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1){
        print_error("Error: Could not set timeout.");
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *((struct in_addr*) host->h_addr_list[0]);
    server_address.sin_port = htons(0);

    if(bind(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) == -1){
        print_error("Error: Could not bind socket.");
    }

    char buffer[BUFFER_SIZE];
    memset(&buffer, 0, sizeof(buffer));
    sprintf(buffer, "PING");

    struct sockaddr_in target_address;
    memset(&target_address, 0, sizeof(target_address));
    target_address.sin_family = AF_INET;
    target_address.sin_port = htons(7);
    target_address.sin_addr = *((struct in_addr*) host->h_addr_list[0]);

    clock_t start_time = clock();
    int bytes_sent = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*) &target_address, sizeof(target_address));
    if(bytes_sent == -1){
        print_error("Error: Could not send data.");
    }

    memset(&buffer, 0, sizeof(buffer));
    socklen_t target_address_length = sizeof(target_address);
    int bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*) &target_address, &target_address_length);
    if(bytes_received == -1){
        printf("Host: %s, Response: TIMEOUT\n", hostname);
    }else{
        clock_t end_time = clock();
        double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000; // in milliseconds
        printf("Host: %s, Response: %s", hostname, buffer);
        printf("Elapsed Time: %.2fms\n", elapsed_time);
    }

    close(sockfd);
}

int main(int argc, char *argv[]){
    if(argc < 2){
        print_error("Usage: ./qos_monitor <hostname>");
    }
    monitor_QoS(argv[1]);
    return 0;
}