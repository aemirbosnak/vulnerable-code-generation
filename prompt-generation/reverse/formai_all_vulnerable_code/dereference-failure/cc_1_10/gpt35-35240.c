//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>

#define MAX_HOSTS 1024 // maximum number of hosts to scan
#define BUFFER_SIZE 1024 // buffer size for storing data
#define PORT_NUM 80 // port number to scan

int num_hosts = 0; // counter to track number of hosts found
char **host_list = NULL; // pointer to host list

void *scan_host(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0); // create a socket for TCP connection

    if(sock < 0) {
        perror("socket() failed");
        pthread_exit(NULL);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_NUM);
    inet_aton((char *)arg, &server_addr.sin_addr);

    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        // failed to connect, host is down
        pthread_exit(NULL);
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", (char *)arg); // send a GET request to the host
    if(write(sock, buffer, strlen(buffer)) < 0) {
        perror("write() failed");
        pthread_exit(NULL);
    }

    if(read(sock, buffer, BUFFER_SIZE) > 0) {
        printf("%s\n", buffer); // print out the response from the server
    }

    close(sock);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    // check for host input
    if(argc < 2) {
        printf("Usage: %s <host1> [<host2> ...]\n", argv[0]);
        exit(-1);
    }

    // initialize host list
    host_list = (char **)malloc(sizeof(char *) * MAX_HOSTS);
    memset(host_list, 0, sizeof(char *) * MAX_HOSTS);

    for(int i = 1; i < argc; i++) {
        // check host name is valid
        struct hostent *he = gethostbyname(argv[i]);
        if(!he) {
            printf("Host not found: %s\n", argv[i]);
            continue;
        }

        // add host name to list
        host_list[num_hosts] = (char *)malloc(sizeof(char) * (strlen(he->h_name) + 1));
        memset(host_list[num_hosts], 0, sizeof(char) * (strlen(he->h_name) + 1));
        strcpy(host_list[num_hosts], he->h_name);
        num_hosts++;
    }

    // scan each host in the list
    pthread_t threads[MAX_HOSTS];
    int num_threads = 0;

    for(int i = 0; i < num_hosts; i++) {
        if(pthread_create(&threads[num_threads], NULL, scan_host, (void *)host_list[i]) == 0) {
            num_threads++;
        }
    }

    // wait for each thread to complete
    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // free memory
    for(int i = 0; i < num_hosts; i++) {
        free(host_list[i]);
    }
    free(host_list);

    return 0;
}