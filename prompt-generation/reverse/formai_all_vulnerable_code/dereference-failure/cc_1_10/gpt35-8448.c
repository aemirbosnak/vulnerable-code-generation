//FormAI DATASET v1.0 Category: Network Ping Test ; Style: surrealist
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void surrealistPing(char *ip) {
    
    printf("Initiating surrealist ping on address %s ...\n", ip);
    
    struct hostent *host;
    struct sockaddr_in addr;
    int sockfd;
    fd_set readfds;
    struct timeval timeout;
    socklen_t len;
    
    host = gethostbyname(ip);
    
    if (!host) {
        printf("Hostname could not be resolved!\n");
        return;
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr.s_addr = *(long*)(host->h_addr);
    
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (sockfd < 0) {
        printf("Could not create socket!\n");
        return;
    }
    
    int pingCounter = 0;
    
    while (pingCounter < 10) {
        
        printf("\n");
        
        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            printf("Could not connect to host %s!\n", ip);
            return;
        }
        
        char surrealistPing[50];
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        const char *hr = "Oink";
        const char *min = "Purr";
        const char *sec = "Moo";
        sprintf(surrealistPing, "%s %02d %s %02d %s\n", hr, tm->tm_hour, min, tm->tm_min, sec);
        
        int sent = send(sockfd, surrealistPing, strlen(surrealistPing), 0);
        
        if (sent < 0) {
            printf("Could not send ping request!\n");
            return;
        }
        
        timeout.tv_sec = 2;
        timeout.tv_usec = 0;
        
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        
        int ready = select(sockfd+1, &readfds, NULL, NULL, &timeout);
        
        if (ready < 0) {
            printf("Select error!\n");
            return;
        }
        
        if (ready == 0) {
            printf("Ping timeout!\n");
            return;
        }
        
        char receiveBuffer[1024] = {0};
        int received = recv(sockfd, receiveBuffer, 1024, 0);
        
        if (received < 0) {
            printf("No response to ping request!\n");
            return;
        }
        
        printf("Surrealist Ping Received from %s : %s\n", ip, receiveBuffer);
        
        close(sockfd);
        sleep(2);
        
        pingCounter++;
    }
    
    printf("\nSurrealist ping test completed successfully for address %s.\n", ip);

}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: surrealist_ping <IP address>\n");
        exit(1);
    }
    surrealistPing(argv[1]);
    return 0;
}