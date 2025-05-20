//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <errno.h>

#define MAX_BUFFER 1024
#define MAX_DEVICES 1000

typedef struct Device{
    char* name;
    char* ip_address;
    int port;
} Device;

int main(){
    Device devices[MAX_DEVICES];
    int num_devices = 0;

    //get list of network interfaces
    struct ifaddrs *ifaddr, *ifa;
    if(getifaddrs(&ifaddr) == -1){
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    //iterate through network interfaces
    for(ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next){
        if(ifa->ifa_addr == NULL){
            continue;
        }
        
        //get device name
        char name[MAX_BUFFER];
        strcpy(name, ifa->ifa_name);

        //check if device already in list
        int i;
        int device_found = 0;
        for(i = 0; i < num_devices; i++){
            if(strcmp(devices[i].name, name) == 0){
                device_found = 1;
                break;
            }
        }
        
        //get IP address
        char addr_str[INET_ADDRSTRLEN];
        void *addr;
        if(ifa->ifa_addr->sa_family == AF_INET){
            addr = &((struct sockaddr_in *) ifa->ifa_addr)->sin_addr;
            inet_ntop(AF_INET, addr, addr_str, INET_ADDRSTRLEN);
        }
        else if(ifa->ifa_addr->sa_family == AF_INET6){
            addr = &((struct sockaddr_in6 *) ifa->ifa_addr)->sin6_addr;
            inet_ntop(AF_INET6, addr, addr_str, INET_ADDRSTRLEN);
        }
        else{
            continue;
        }

        //add new device to list
        if(!device_found){
            Device new_device;
            new_device.name = malloc(sizeof(char) * (strlen(name)+1));
            strcpy(new_device.name, name);
            new_device.ip_address = malloc(sizeof(char) * (strlen(addr_str)+1));
            strcpy(new_device.ip_address, addr_str);
            new_device.port = -1;
            devices[num_devices] = new_device;
            num_devices++;
        }
    }

    //free memory
    freeifaddrs(ifaddr);

    //print list of devices
    printf("List of Devices:\n");
    int i;
    for(i = 0; i < num_devices; i++){
        printf("Name: %s | IP Address: %s | Port: %d\n", devices[i].name, devices[i].ip_address, devices[i].port);
    }

    return 0;
}