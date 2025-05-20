//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }
    printf("Socket created\n");

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Connection failed\n");
        return 1;
    }
    printf("Connected to server\n");

    float delay = 0.0f;
    float jitter = 0.0f;
    float packet_loss = 0.0f;

    char message[100];
    time_t t;

    while(1)
    {

        t = time(NULL);
        sprintf(message, "PING %d", t);
        send(sock, message, strlen(message), 0);

        clock_t start = clock();
        recv(sock, message, 100, 0);
        delay = (float)(clock() - start) / CLOCKS_PER_SEC;

        if(delay > 1.0f)
        {
            printf("Delay: %f seconds (high)\n", delay);
        }
        else
        {
            printf("Delay: %f seconds\n", delay);
        }
        
        if(jitter == 0.0f)
        {
            jitter = delay;
        }
        else
        {
            float deviation = delay - jitter;
            jitter = jitter + (deviation - jitter) / 16.0f;
            printf("Jitter: %f seconds\n", jitter);
        }

        if(rand() % 100 < 5)
        {
            printf("Packet loss: 1%%\n");
            packet_loss = 1.0f;
        }
        else if(packet_loss > 0.0f)
        {
            packet_loss = packet_loss / 2.0f;
            printf("Packet loss: %f%%\n", packet_loss * 100);
        }
        else
        {
            printf("Packet loss: 0%%\n");
        }

        sleep(1);
    }

    close(sock);
    return 0;
}