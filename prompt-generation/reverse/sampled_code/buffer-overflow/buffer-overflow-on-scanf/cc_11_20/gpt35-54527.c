//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include<stdio.h>

int main() {
  int subnetMask = 24;
  int bitsInSubnet = 32 - subnetMask;
  int i,j,k,n;
  int binary[32] = {0};

  printf("Enter the IP address: \n");
  for(i=0; i<4; i++) {
    scanf("%d.", &n);
    for(j=7, k=0; j>=0; j--, k++) {
      binary[i*8+k] = (n >> j) & 1;
    }
  }

  // Display the binary representation of the IP address
  printf("\n\nBinary representation of the IP address: ");
  for(i=0; i<32; i++) {
    printf("%d", binary[i]);
    if(i%8 == 7) printf(".");
  }

  // Display the number of bits in the subnet mask
  printf("\n\nNumber of bits in the subnet mask: %d", bitsInSubnet);

  // Calculate the subnet ID
  int subnet[32] = {0};
  for(i=0; i<subnetMask; i++) {
    subnet[i] = binary[i];
  }

  // Display the binary representation of the subnet ID
  printf("\n\nBinary representation of the subnet ID: ");
  for(i=0; i<32; i++) {
    printf("%d", subnet[i]);
    if(i%8 == 7) printf(".");
  }

  // Calculate the broadcast address
  int broadcast[32] = {0};
  for(i=0; i<bitsInSubnet; i++) {
    broadcast[subnetMask+i] = 1;
  }

  // Display the binary representation of the broadcast address
  printf("\n\nBinary representation of the broadcast address: ");
  for(i=0; i<32; i++) {
    printf("%d", broadcast[i]);
    if(i%8 == 7) printf(".");
  }

  // Calculate the number of hosts
  int hosts = 1;
  for(i=0; i<bitsInSubnet; i++) {
    hosts *= 2;
  }
  hosts -= 2; // Subtract network and broadcast addresses

  // Display the number of hosts
  printf("\n\nNumber of hosts: %d\n\n", hosts);

  return 0;
}