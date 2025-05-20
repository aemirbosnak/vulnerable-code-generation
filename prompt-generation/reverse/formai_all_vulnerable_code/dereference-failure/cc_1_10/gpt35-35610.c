//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate(char* ip, char* mask){
  int octet[4], octet_mask[4], subnet_mask[4];
  sscanf(ip, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);
  sscanf(mask, "%d.%d.%d.%d", &octet_mask[0], &octet_mask[1], &octet_mask[2], &octet_mask[3]);
  for (int i = 0; i < 4; i++){
    subnet_mask[i] = octet[i] & octet_mask[i];
  }
  int num_hosts = 1;
  for (int i = 0; i < 4; i++){
    num_hosts *= (255 - octet_mask[i]) + 1;
  }
  num_hosts -= 2;
  printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
  printf("Number of Hosts in this subnet: %d\n", num_hosts);
}

int main(){
  char *ip_address = malloc(sizeof(char) * 20);
  char *subnet_mask = malloc(sizeof(char) * 20);
  printf("Enter the IP Address (e.g. 192.168.10.1): ");
  scanf("%s", ip_address);
  printf("Enter the Subnet Mask (e.g. 255.255.255.0): ");
  scanf("%s", subnet_mask);
  printf("\n");

  int num_periods = 0;
  for (int i = 0; i < strlen(ip_address); i++){
    if(ip_address[i] == '.'){
      num_periods++;
    }
  }
  if(num_periods != 3){
    printf("Invalid IP address format...\n");
    return 0;
  }

  num_periods = 0;
  for (int i = 0; i < strlen(subnet_mask); i++){
    if(subnet_mask[i] == '.'){
      num_periods++;
    }
  }
  if(num_periods != 3){
    printf("Invalid Subnet mask format...\n");
    return 0;
  }

  calculate(ip_address, subnet_mask);
  
  free(ip_address);
  free(subnet_mask);
  return 0;
}