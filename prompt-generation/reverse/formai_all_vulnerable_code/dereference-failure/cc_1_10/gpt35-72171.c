//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Ken Thompson
#include <stdio.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 80
#define MAX_SIZE 100000

float speedTest(char *url){

    char *hostname = strtok(url, "/");
    char path[100];
    strcpy(path, "/");
    strcat(path, strtok(NULL, "\n"));

    struct hostent *server = gethostbyname(hostname);
    if(server == NULL){
        printf("Error: No such host exists.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Error: Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("Error: Could not connect to server.\n");
        exit(EXIT_FAILURE);
    }

    char request[MAX_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

    struct timeval start, stop;

    char response[MAX_SIZE];
    int numBytes = 0, totalBytes = 0;
    gettimeofday(&start, NULL);

    while((numBytes = read(sockfd, response, MAX_SIZE)) > 0){

        totalBytes += numBytes;
        bzero(response, MAX_SIZE);
    }

    gettimeofday(&stop, NULL);
    close(sockfd);

    float timeElapsed = ((stop.tv_sec * 1000000 + stop.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) / 1000000.0;
    float speed = totalBytes / timeElapsed / 1048576; //in MBps

    return speed;
}

int main(){

    char url[MAX_SIZE];
    printf("Please enter a valid URL: ");
    fgets(url, MAX_SIZE, stdin);

    float speed = speedTest(url);
    printf("Download Speed: %.2f MB/s\n", speed);

    return 0;
}