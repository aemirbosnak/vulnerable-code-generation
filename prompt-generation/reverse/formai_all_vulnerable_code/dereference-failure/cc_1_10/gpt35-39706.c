//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <time.h>

#define BUFSIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n, i, str_len, total_packets = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE], ip[16], run_time[10], buf[BUFSIZE], str[20], temp[20];
    float pdr, avg_delay, overall_pdr = 0, overall_avg_delay = 0;
    time_t start, current;
    
    if (argc < 4) {
       fprintf(stderr,"usage %s hostname port runtime\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0)
        error("ERROR opening socket");
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    time(&start);

    while (1) {
        time(&current);
        sprintf(run_time, "%d", (int)difftime(current, start));
        if (atoi(run_time) >= atoi(argv[3])) {
            printf("Program has been running for %d seconds.\n", atoi(run_time));
            printf("\nOverall Performance:");
            printf("\n---------------------");
            printf("\n%d packets were received in total.", total_packets);
            printf("\nAverage Delivery Ratio: %.2f%%", overall_pdr);
            printf("\nAverage Delay: %.2f ms\n", overall_avg_delay);
            close(sockfd);
            exit(0);
        }
        
        for (i = 0; i < BUFSIZE; i++) {
            buffer[i] = 0;
        }
        
        sprintf(ip, "%u.%u.%u.%u\n", rand() % 256, rand() % 256, rand() % 256, rand() % 256);
        str_len = rand() % BUFSIZE + 1;
        for (i = 0; i < str_len; i++) {
            buffer[i] = rand() % 94 + 32; 
        }
        buffer[str_len] = '\0';
        
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }
        
        n = read(sockfd, buf, BUFSIZE-1);
        if (n > 0) {
            sscanf(buf, "%f,%f", &pdr, &avg_delay);
            overall_pdr = (overall_pdr * (float)total_packets + pdr) / (float)++total_packets;
            overall_avg_delay = (overall_avg_delay * (float)total_packets + avg_delay) / (float)total_packets;
            sprintf(str, "%.2f%%", pdr);
            sprintf(temp, "%.2f", avg_delay);
            printf("\nPacket %d:", total_packets);
            printf("\n------------");
            printf("\nIP Address: %s", ip);
            printf("\nPacket Data: %s", buffer);
            printf("\nDelivery Ratio: %s", str);
            printf("\nDelay: %s ms", temp);
        }
    }

    return 0;
}