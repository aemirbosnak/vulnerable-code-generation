//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 80

void checkUptime(char *url){
    struct sockaddr_in serverAddr;
    struct hostent *server;
    int sockfd, status;
    char buffer[256];
    time_t currTime;
    time(&currTime);
    printf("Checking uptime for %s at %s\n", url, ctime(&currTime));
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Couldn't create socket.");
        exit(1);
    }
    server = gethostbyname(url);
    if(server == NULL){
        printf("Error: No such host %s", url);
        exit(2);
    }
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serverAddr.sin_addr.s_addr,
          server->h_length);
    serverAddr.sin_port = htons(PORT);
    status = connect(sockfd, (struct sockaddr *)&serverAddr,sizeof(serverAddr));
    if(status < 0){
        perror("Error connecting to host.");
        exit(3);
    }
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "GET / HTTP/1.0\r\n\r\n");
    status = write(sockfd, buffer, strlen(buffer));
    if(status < 0){
        perror("Error writing to socket.");
        exit(4);
    }
    memset(buffer, 0, sizeof(buffer));
    status = read(sockfd, buffer, sizeof(buffer)-1);
    if(status < 0){
        perror("Error reading from socket.");
        exit(5);
    }
    printf("%s is UP!\n", url);
    close(sockfd);
}

int main(){
    char urls[5][30] = {"www.google.com", "www.github.com", "www.facebook.com", "www.youtube.com", "www.linkedin.com"};
    int i;
    while(1){
        for(i=0; i<5; i++){
            checkUptime(urls[i]);
        }
        sleep(60);
    }
    return 0;
}