//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define SIZE_MAX 1024
#define SECONDS_PERNANOSECOND 1000000000

typedef struct _Result
{
    double upload;
    double download;
} Result;

int get_ip_address(char *hostname, char *ip_address)
{
    struct hostent *host;
    host = gethostbyname(hostname);
    if (host == NULL)
    {
        return -1;
    }
    else
    {
        strcpy(ip_address, inet_ntoa(*(struct in_addr *)host->h_addr));
        return 0;
    }
}

int create_socket(int *sock)
{
    *sock = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int connect_to_server(int sock, char *ip_address)
{
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    int status = connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
    if (status < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int send_data(int sock)
{
    char data[SIZE_MAX];
    memset(data, 'a', SIZE_MAX);
    int status = send(sock, data, SIZE_MAX, 0);
    if (status < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int receive_data(int sock)
{
    char data[SIZE_MAX];
    int status = recv(sock, data, SIZE_MAX, 0);
    if (status < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

Result calculate_speed(struct timeval start, struct timeval end)
{
    Result result;
    struct timeval diff;
    diff.tv_sec = end.tv_sec - start.tv_sec;
    diff.tv_usec = end.tv_usec - start.tv_usec;
    double duration = (double)diff.tv_sec + (double)diff.tv_usec / SECONDS_PERNANOSECOND;
    result.upload = SIZE_MAX / duration;
    result.download = SIZE_MAX / duration;
    return result;
}

int main()
{
    int sock;
    Result result;
    struct timeval start, end;
    char ip_address[SIZE_MAX];
    get_ip_address("www.google.com", ip_address);
    create_socket(&sock);
    connect_to_server(sock, ip_address);
    gettimeofday(&start, NULL);
    send_data(sock);
    receive_data(sock);
    gettimeofday(&end, NULL);
    result = calculate_speed(start, end);
    printf("Upload speed: %.2f MB/s\n", result.upload);
    printf("Download speed: %.2f MB/s\n", result.download);
    close(sock);
    return 0;
}