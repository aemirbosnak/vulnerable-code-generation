//FormAI DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int startport, endport;
    
    //Check if user input correct number of arguments
    if(argc != 4)
    {
        printf("Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        return 0;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //Check if socket creation was successful
    if(sockfd < 0)
    {
        printf("\nSocket creation error \n");
        return 0;
    }

    //Prepare the sockaddr_in structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    
    //Loop through all the ports and check if they are open or not
    for(int i = atoi(argv[2]); i <= atoi(argv[3]); i++)
    {
        serv_addr.sin_port = htons(i);

        //Connect to the specified IP address and port number
        if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        {
            printf("Port %d: Closed\n", i);
        }
        else
        {
            printf("Port %d: Open\n", i);
        }
    }

    return 0;
}