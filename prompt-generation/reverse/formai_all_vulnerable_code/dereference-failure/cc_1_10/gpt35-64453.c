//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 80
#define TEST_TIMEOUT 5    //in seconds

int main(int argc, char **argv)
{
    char *url, *host, *path, *get_request;
    struct sockaddr_in server_address;
    int sockfd, bytes_sent, bytes_received, total_bytes_received;
    socklen_t server_size = sizeof(server_address);
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;
    double elapsed_time;
    
    if(argc != 2)
    {
        printf("Usage: %s url\n", argv[0]);
        exit(1);
    }
    
    url = argv[1];
    printf("Testing speed of %s...\n", url);
    
    //Parse URL and create GET request
    host = strtok(url, "/");
    path = strtok(NULL, "");
    if(path == NULL)
        path = "";
    get_request = malloc(strlen(path) + strlen(host) + 15);
    sprintf(get_request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    
    //Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("Error: could not create socket\n");
        exit(1);
    }
    
    //Set server address
    memset(&server_address, 0, server_size);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(host);
    if(server_address.sin_addr.s_addr == -1)
    {
        printf("Error: invalid IP address\n");
        exit(1);
    }
    server_address.sin_port = htons(DEFAULT_PORT);
    
    //Connect to server
    if(connect(sockfd, (struct sockaddr*)&server_address, server_size) < 0)
    {
        printf("Error: could not connect to server\n");
        exit(1);
    }
    
    //Send GET request
    bytes_sent = send(sockfd, get_request, strlen(get_request), 0);
    if(bytes_sent < 0)
    {
        printf("Error: could not send request\n");
        exit(1);
    }
    
    //Receive data
    total_bytes_received = 0;
    time(&start_time);
    while(1)
    {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if(bytes_received < 0)
        {
            printf("Error: could not receive data\n");
            exit(1);
        }
        if(bytes_received == 0)       //Connection closed
            break;
        total_bytes_received += bytes_received;
    }
    time(&end_time);
    close(sockfd);
    
    //Print result
    elapsed_time = difftime(end_time, start_time);
    printf("Received %d bytes in %.2f seconds, at a speed of %.2f bytes/sec.\n", total_bytes_received, elapsed_time, (double)total_bytes_received / elapsed_time);
    free(get_request);
    return 0;
}