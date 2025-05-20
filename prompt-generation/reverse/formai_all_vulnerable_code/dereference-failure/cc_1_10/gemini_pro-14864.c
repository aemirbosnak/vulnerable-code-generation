//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: post-apocalyptic
/*
 * **W a r n i n g: U n s a f e**
 * This code assumes you know what you are doing and should not be run on a system you care about.
 * Use at your own risk.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define DEST_IP "192.168.1.1"
#define DEST_PORT 1234
#define MESSAGE_LENGTH 1024

void manual_control(int sock)
{
    char buffer[MESSAGE_LENGTH];
    int n;

    while (1)
    {
        printf("> ");
        scanf("%s", buffer);

        if (strcmp(buffer, "quit") == 0)
        {
            printf("Exiting manual control.\n");
            break;
        }

        n = send(sock, buffer, strlen(buffer), 0);
        if (n < 0)
        {
            perror("sendto");
            break;
        }
    }
}

void autonomous_control(int sock)
{
    char buffer[MESSAGE_LENGTH];
    int n;
    int i = 0;

    while (1)
    {
        srand(time(NULL));
        int rand_num = rand() % 4;

        switch (rand_num)
        {
        case 0:
            strcpy(buffer, "forward");
            break;
        case 1:
            strcpy(buffer, "left");
            break;
        case 2:
            strcpy(buffer, "right");
            break;
        case 3:
            strcpy(buffer, "stop");
            break;
        }

        n = send(sock, buffer, strlen(buffer), 0);
        if (n < 0)
        {
            perror("sendto");
            break;
        }

        printf("Sent command: %s\n", buffer);
        i++;

        if (i >= 100)
        {
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[MESSAGE_LENGTH];
    int n;

    if (argc < 2)
    {
        printf("Usage: %s <mode>\n", argv[0]);
        printf("Mode can be either \"manual\" or \"autonomous\".\n");
        return 1;
    }

    if (strcmp(argv[1], "manual") == 0)
    {
        printf("Starting manual control.\n");
    }
    else if (strcmp(argv[1], "autonomous") == 0)
    {
        printf("Starting autonomous control.\n");
    }
    else
    {
        printf("Invalid mode. Please use either \"manual\" or \"autonomous\".\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(DEST_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(DEST_IP);

    if (strcmp(argv[1], "manual") == 0)
    {
        manual_control(sock);
    }
    else if (strcmp(argv[1], "autonomous") == 0)
    {
        autonomous_control(sock);
    }

    close(sock);

    return 0;
}