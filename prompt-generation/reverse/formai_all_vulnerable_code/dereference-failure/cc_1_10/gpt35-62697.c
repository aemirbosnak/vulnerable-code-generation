//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

// Function to convert the given IP address to binary format
void convertToBinary(char *ipAddress, unsigned char *binaryAddress)
{
    int index = 0, byteIndex = 0, length = strlen(ipAddress);
    char temp[4] = {'\0'};
    while (index <= length)
    {
        if (isdigit(ipAddress[index]))
        {
            temp[byteIndex] = ipAddress[index];
            byteIndex++;
        }
        if (index == length || ipAddress[index] == '.')
        {
            binaryAddress[byteIndex - 1] = (unsigned char)atoi(temp);
            memset(temp, '\0', sizeof(temp));
            byteIndex = 0;
        }
        index++;
    }
}

int main(int argc, char *argv[])
{
    // Get the command line arguments
    if (argc != 3)
    {
        printf("Usage: ./scanner <ip_address> <port>\n");
        return 1;
    }

    char *targetIP = argv[1];
    int targetPort = atoi(argv[2]);

    unsigned char binaryAddress[4] = {0};
    convertToBinary(targetIP, binaryAddress);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket() error");
        return 1;
    }

    // Set socket options
    int optVal = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(optVal)) < 0)
    {
        perror("setsockopt() error");
        return 1;
    }

    // Set the target address
    struct sockaddr_in targetAddress;
    memset(&targetAddress, 0, sizeof(targetAddress));
    targetAddress.sin_family = AF_INET;
    targetAddress.sin_addr.s_addr = htonl((binaryAddress[0] << 24) | (binaryAddress[1] << 16) | (binaryAddress[2] << 8) | binaryAddress[3]);

    // Scan the target port
    int connectStatus = connect(sock, (struct sockaddr *)&targetAddress, sizeof(targetAddress));
    if (connectStatus < 0)
    {
        printf("Port %d is closed\n", targetPort);
    }
    else
    {
        printf("Port %d is open\n", targetPort);
    }

    close(sock);

    return 0;
}