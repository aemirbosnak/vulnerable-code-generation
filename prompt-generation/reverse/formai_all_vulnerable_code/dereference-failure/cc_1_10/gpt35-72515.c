//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024
#define MAX_IPS 256

int ping_ip(char *ip);
void *thread_func(void *arg);

struct addr_details {
    int index;
    char *ip;
};

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Usage: %s network_address\n", argv[0]);
        exit(1);
    }
    char *network_addr = argv[1];
    printf("Mapping network topology of %s\n", network_addr);
    printf("------------------------------------\n");

    pthread_t threads[MAX_THREADS];
    struct addr_details addrs[MAX_IPS];
    int i, thread_count = 0;

    for(i=1;i<=255;i++) {
        char *ip = (char *)malloc(BUFFER_SIZE);
        sprintf(ip, "%s.%d", network_addr, i);
        addrs[i-1].index = i-1;
        addrs[i-1].ip = ip;
        if(ping_ip(ip)) {
            if(pthread_create(&threads[thread_count], NULL, thread_func, &addrs[i-1])!=0) {
                perror("Thread Creation Failed");
                exit(1);
            }
            thread_count++;
        }
    }
    printf("Started %d thread(s) for active IPs\n", thread_count);

    for(i=0;i<thread_count;i++) {
        pthread_join(threads[i], NULL);
    }

    printf("------------------------------------\n");
    printf("End of network topology mapping of %s\n", network_addr);

    return 0;
}

int ping_ip(char *ip)
{
    int status = -1;
    char command[BUFFER_SIZE];
    sprintf(command, "ping -c 2 -t 1 %s > /dev/null", ip);
    status = system(command);
    if(status == 0) {
        return 1;
    }
    return 0;
}

void *thread_func(void *arg)
{
    struct addr_details *addrs = (struct addr_details *) arg;
    char command[BUFFER_SIZE];
    sprintf(command, "nmap -sP %s > %d.txt", addrs->ip, addrs->index);
    system(command);
    FILE *fp;
    char file_name[BUFFER_SIZE];
    sprintf(file_name, "%d.txt", addrs->index);
    if((fp = fopen(file_name, "r")) == NULL) {
        perror("Cannot open file");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    int count = 0;
    while(fgets(buffer, BUFFER_SIZE-1, fp) != NULL) {
        if(strstr(buffer, "Host is up")) {
            char *ip = strtok(buffer, " ");
            printf("%s is up\n", ip);
            count++;
        }
    }
    if(count == 1) {
        printf("%s is a standalone device\n", addrs->ip);
    }
    else if(count > 1) {
        printf("%s is connected to a switch/hub\n", addrs->ip);
    }
    fclose(fp);
    sprintf(command, "rm -f %d.txt", addrs->index);
    system(command);
    pthread_exit(NULL);
}