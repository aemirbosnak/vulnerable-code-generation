//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define BUFSIZE 256

void error_handle(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUFSIZE];
    int str_len, addr_size, data_speed;
    long long curr_time, prev_time;

    if(argc != 4) {
        printf("Usage: %s <IP> <port> <data speed>\n", argv[0]);
        exit(1);
    }

    if((sock = socket(PF_INET, SOCK_DGRAM, 0)) == -1)
        error_handle("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    addr_size = sizeof(serv_addr);

    strcpy(message, "Network Quality of Service (QoS) Monitor");

    prev_time = clock();

    while(1) {
        curr_time = clock();

        if(curr_time - prev_time >= 1000000 / atoi(argv[3])) {
            sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

            printf("Message sent: %s\n", message);

            str_len = recvfrom(sock, message, BUFSIZE-1, 0, NULL, NULL);
            if(str_len < 0) {
                printf("No response from server\n");
                continue;
            }
            message[str_len] = '\0';

            printf("Message received: %s\n\n", message);

            prev_time = curr_time;
        }
    }

    close(sock);

    return 0;
}