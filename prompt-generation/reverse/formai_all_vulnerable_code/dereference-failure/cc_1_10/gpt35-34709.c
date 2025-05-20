//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_ADDR_LEN 80
#define MAX_LINE_LEN 1024

struct host{
    char name[MAX_ADDR_LEN];
    int num_ips;
    char ips[10][MAX_ADDR_LEN];
};

struct topology{
    struct host *hosts;
    int num_hosts;
};

/*
 * This function takes one IP address and returns the hostname
 */
char* get_hostname(char* ip_address){
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    char hostname[MAX_ADDR_LEN];
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);
    if (getnameinfo((struct sockaddr *)&addr, len,
        hostname, sizeof(hostname), NULL, 0, NI_NAMEREQD) != 0) {
            return NULL;
    }
    return strdup(hostname);
}

/*
 * This function reads a file containing the list of hosts and their IP addresses
 * It returns a topology structure containing the host names and their corresponding IP addresses
 */
struct topology* read_topology_file(char* filename){
    FILE *file;
    char line[MAX_LINE_LEN];
    int num_hosts, num_ips, i;
    struct host *hosts;
    struct topology* topology;
    topology = (struct topology*) malloc(sizeof(struct topology));
    file = fopen(filename,"r");
    if(file == NULL){
        perror("Cannot open topology file");
        return NULL;
    }
    fgets(line, MAX_LINE_LEN, file);
    sscanf(line, "%d", &num_hosts);
    hosts = (struct host*) malloc(sizeof(struct host) * num_hosts);
    for(i = 0; i < num_hosts; i++){
        fgets(line, MAX_LINE_LEN, file);
        sscanf(line, "%s %d", hosts[i].name, &num_ips);
        hosts[i].num_ips = num_ips;
        int j;
        for(j = 0; j < num_ips; j++){
            fgets(line, MAX_LINE_LEN, file);
            line[strlen(line)-1] = '\0';
            strcpy(hosts[i].ips[j], line);
        }
    }
    topology->hosts = hosts;
    topology->num_hosts = num_hosts;
    fclose(file);
    return topology;
}

/*
 * This function takes a topology object and prints it in a readable format
 */
void print_topology(struct topology* topology){
    int i, j;
    for(i = 0; i < topology->num_hosts; i++){
        printf("Host %d: %s\n", i+1, topology->hosts[i].name);
        for(j = 0; j < topology->hosts[i].num_ips; j++){
            printf("\tIP Address %d: %s\n", j+1, topology->hosts[i].ips[j]);
        }
    }
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <topology file>\n", argv[0]);
        exit(1);
    }
    struct topology* topology = read_topology_file(argv[1]);
    if(topology == NULL){
        printf("Error reading topology file\n");
        exit(1);
    }
    print_topology(topology);

    // Get hostname for each IP address
    int i, j;
    for(i = 0; i < topology->num_hosts; i++){
        for(j = 0; j < topology->hosts[i].num_ips; j++){
            char* hostname = get_hostname(topology->hosts[i].ips[j]);
            printf("Hostname for %s is %s\n", topology->hosts[i].ips[j], hostname);
            free(hostname);
        }
    }
    free(topology->hosts);
    free(topology);
    return 0;
}