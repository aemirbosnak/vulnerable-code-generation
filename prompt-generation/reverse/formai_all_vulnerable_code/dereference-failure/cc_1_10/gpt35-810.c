//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define PACKET_SIZE 1024

bool network_available;

void* monitor_network(void* arg)
{
    while(true)
    {
        // Ping a reliable server to check internet connection
        struct addrinfo hints;
        struct addrinfo *result, *rp;
        int sockfd;
        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = 0;
        hints.ai_protocol = IPPROTO_TCP;
        if (getaddrinfo("8.8.8.8", "80", &hints, &result) != 0) 
        {
            network_available = false;
        }
        for (rp = result; rp != NULL; rp = rp->ai_next) 
        {
            sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
            if (sockfd == -1)
            {
                continue;
            }
            if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1)
            {
                network_available = true;
                break;
            }
            close(sockfd);
        }
        freeaddrinfo(result);
        sleep(2); // Check every 2 seconds
    }
}

int main(int argc, char const *argv[])
{
    network_available = true;
    pthread_t network_thread;
    pthread_create(&network_thread, NULL, monitor_network, NULL);
    // Start network monitoring in a separate thread
    
    while(true)
    {
        if(network_available)
        {
            // Open socket connection and send QoS data to server
            struct sockaddr_in serv_addr;
            int sockfd = 0, valread;
            char buffer[PACKET_SIZE] = {0};
            if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            {
                printf("\n Socket creation error \n");
                return -1;
            }
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(PORT);
            if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
            {
                printf("\nInvalid address/ Address not supported \n");
                return -1;
            }
            if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
            {
                printf("\nConnection Failed \n");
                return -1;
            }
            // Generate fake QoS data
            int download_speed = rand() % 100 + 1;
            int upload_speed = rand() % 100 + 1;
            int latency = rand() % 1000 + 1;
            sprintf(buffer, "DOWNLOAD:%d UPLOAD:%d LATENCY:%d", download_speed, upload_speed, latency);
            send(sockfd , buffer , strlen(buffer) , 0 );
            printf("QoS data sent: %s\n", buffer);
            valread = read( sockfd , buffer, PACKET_SIZE);
            printf("%s\n",buffer );
            close(sockfd);
        }
        else
        {
            printf("Network not available, retrying in 5 seconds\n");
            sleep(5);
        }
    }
    return 0;
}