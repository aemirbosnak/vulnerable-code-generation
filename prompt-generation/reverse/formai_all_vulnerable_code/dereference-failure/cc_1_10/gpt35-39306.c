//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<arpa/inet.h>
#include<net/if.h>
#include<ctype.h>

#define MAX_INTERFACE_NAME_LENGTH 256
#define MAX_IPV4_LENGTH 16
#define MAX_MAC_ADDR_LENGTH 18

void print_header()
{
    printf("\n**********************************************************\n");
    printf("\t C Wireless Network Scanner Example Program \n");
    printf("**********************************************************\n\n");
} 

void print_interface_details(char* ifName, char* ip_address, char* mac_address)
{
  printf("\tInterface Name    : %s\n",ifName);
  printf("\tIP Address        : %s\n",ip_address);
  printf("\tMAC Address       : %s\n\n",mac_address);
}

void display_interfaces()
{
    int fd;
    struct ifreq ifr;
    char ifName[MAX_INTERFACE_NAME_LENGTH];
    char ip_address[MAX_IPV4_LENGTH];
    char mac_address[MAX_MAC_ADDR_LENGTH];

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    printf("List of available network interfaces: \n\n");

    for(int idx=1;;idx++)
    {
        memset(&ifr, 0, sizeof(struct ifreq));
        ifr.ifr_ifindex = idx;

        if(ioctl(fd,SIOCGIFNAME,&ifr) != 0)
            break;

        strcpy(ifName,ifr.ifr_name);
     
        strcpy(ifr.ifr_name,ifName);
         
        if(ioctl(fd,SIOCGIFADDR,&ifr) == 0)
            strcpy(ip_address,inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
          
        if(ioctl(fd,SIOCGIFHWADDR,&ifr) == 0)
        {
            sprintf(mac_address,"%02x:%02x:%02x:%02x:%02x:%02x",
            (unsigned char)ifr.ifr_hwaddr.sa_data[0],
            (unsigned char)ifr.ifr_hwaddr.sa_data[1],
            (unsigned char)ifr.ifr_hwaddr.sa_data[2],
            (unsigned char)ifr.ifr_hwaddr.sa_data[3],
            (unsigned char)ifr.ifr_hwaddr.sa_data[4],
            (unsigned char)ifr.ifr_hwaddr.sa_data[5]
            );
        }

        print_interface_details(ifName, ip_address, mac_address);
    }
    close(fd);
}

int main()
{
   print_header();
   display_interfaces();
   
   return 0;
}