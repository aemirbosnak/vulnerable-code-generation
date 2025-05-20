//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<time.h>
#include<errno.h>
#include<netdb.h>

struct hostent *server;
int sockfd;
struct sockaddr_in serv_addr;
char buffer[1025];

int main(int argc, char *argv[])
{
    int valread;
    char *ptr;
    int i,j;
    int count = 0;
    int total = 0;
    double speed;
    struct timeval start, end;
    char *serv_ip;
    int serv_port;
    char *serv_name;
    char *proto;

    if(argc!= 4)
    {
        printf("Usage: %s <server> <port> <protocol>\n", argv[0]);
        return 0;
    }

    serv_name = argv[1];
    serv_port = atoi(argv[2]);
    proto = argv[3];

    server = gethostbyname(serv_name);

    if(server == NULL)
    {
        printf("No such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("socket creation error\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serv_port);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("connection error\n");
        exit(0);
    }

    printf("Connected to %s on port %d\n", serv_name, serv_port);

    gettimeofday(&start, NULL);

    while(1)
    {
        if((valread = read(sockfd, buffer, 1024)) <= 0)
        {
            printf("disconnected from server\n");
            close(sockfd);
            exit(0);
        }

        buffer[valread] = '\0';
        total += valread;
        count++;

        if(count == 10)
        {
            gettimeofday(&end, NULL);
            speed = (double)total/10;
            printf("Total data received = %d bytes\n", total);
            printf("Data transfer speed = %lf bytes/sec\n", speed);

            close(sockfd);
            exit(0);
        }
    }

    return 0;
}