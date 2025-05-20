//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16

typedef struct
{
  char ip_addr[MAX_IP_LEN];
  int cidr;
  char subnet_mask[MAX_IP_LEN]; 
  char network_address[MAX_IP_LEN];
  char broadcast_address[MAX_IP_LEN];
} ip_info;

int power(int base, int exponent)
{
  int result = 1;
  while(exponent > 0)
  {
    result *= base;
    exponent--;
  }
  return result;
}

int binary_to_decimal(char *binary)
{
  int decimal = 0;
  int binary_len = strlen(binary);
  for(int i=0; i<binary_len; i++)
  {
    if(binary[i] == '1')
      decimal += power(2, binary_len-i-1);
  }
  return decimal;
}

char* decimal_to_binary(int decimal)
{
  char *binary = (char*) malloc(9 * sizeof(char));
  for(int i=0; i<8; i++)
  {
    if(decimal % 2 == 0)
      binary[7-i] = '0';
    else
      binary[7-i] = '1';
    decimal /= 2;
  }
  binary[8] = '\0';
  return binary;
}

void calculate_subnet_mask(int cidr, char *subnet_mask)
{
  int full_octets, partial_octet;
  full_octets = cidr / 8;
  partial_octet = cidr % 8;
  for(int i=0; i<full_octets; i++)
    strcat(subnet_mask, "255.");
  if(partial_octet == 0)
    strcat(subnet_mask, "0.0.0");
  else
  {
    char partial_octet_binary[9];
    memset(partial_octet_binary, '\0', 9);
    for(int i=0; i<partial_octet; i++)
      strcat(partial_octet_binary, "1");
    for(int i=0; i<8-partial_octet; i++)
      strcat(partial_octet_binary, "0");
    strcat(subnet_mask, decimal_to_binary(binary_to_decimal(partial_octet_binary)));
    strcat(subnet_mask, ".0.0");
  }
}

void calculate_network_address(char *ip_addr, char *subnet_mask, char *network_address)
{
  char *ip_addr_tokens[4];
  char *subnet_mask_tokens[4];
  char *ip_addr_token;
  char *subnet_mask_token;
  int ip_addr_int, subnet_mask_int, network_address_int;

  for(int i=0; i<4; i++)
  {
    ip_addr_tokens[i] = (char*) malloc(4*sizeof(char));
    subnet_mask_tokens[i] = (char*) malloc(4*sizeof(char));
    memset(ip_addr_tokens[i], '\0', 4);
    memset(subnet_mask_tokens[i], '\0', 4);
  }

  ip_addr_token = strtok(ip_addr, ".");
  subnet_mask_token = strtok(subnet_mask, ".");

  for(int i=0; i<4; i++)
  {
    strcpy(ip_addr_tokens[i], ip_addr_token);
    strcpy(subnet_mask_tokens[i], subnet_mask_token);
    ip_addr_token = strtok(NULL, ".");
    subnet_mask_token = strtok(NULL, ".");
  }

  for(int i=0; i<4; i++)
  {
    ip_addr_int = atoi(ip_addr_tokens[i]);
    subnet_mask_int = atoi(subnet_mask_tokens[i]);
    network_address_int = ip_addr_int & subnet_mask_int;
    char *network_address_octet = decimal_to_binary(network_address_int);
    strcat(network_address, network_address_octet);
    free(network_address_octet);
    if(i < 3)
      strcat(network_address, ".");
  }

  for(int i=0; i<4; i++)
  {
    free(ip_addr_tokens[i]);
    free(subnet_mask_tokens[i]);
  }
}

void calculate_broadcast_address(char *ip_addr, char *subnet_mask, char *broadcast_address)
{
  char *network_address = (char*) malloc(MAX_IP_LEN*sizeof(char));
  memset(network_address, '\0', MAX_IP_LEN);
  calculate_network_address(ip_addr, subnet_mask, network_address);

  char *subnet_mask_complement = (char*) malloc(MAX_IP_LEN*sizeof(char));
  memset(subnet_mask_complement, '\0', MAX_IP_LEN);

  for(int i=0; i<strlen(subnet_mask); i++)
  {
    if(subnet_mask[i] == '0')
      subnet_mask_complement[i] = '1';
    else
      subnet_mask_complement[i] = '0';
  }

  char *subnet_mask_complement_tokens[4];
  char *subnet_mask_complement_token;
  int subnet_mask_complement_int;

  for(int i=0; i<4; i++)
  {
    subnet_mask_complement_tokens[i] = (char*) malloc(4*sizeof(char));
    memset(subnet_mask_complement_tokens[i], '\0', 4);
  }

  subnet_mask_complement_token = strtok(subnet_mask_complement, ".");

  for(int i=0; i<4; i++)
  {
    strcpy(subnet_mask_complement_tokens[i], subnet_mask_complement_token);
    subnet_mask_complement_token = strtok(NULL, ".");
  }

  for(int i=0; i<4; i++)
  {
    subnet_mask_complement_int = atoi(subnet_mask_complement_tokens[i]);
    char *broadcast_address_octet = decimal_to_binary(subnet_mask_complement_int | binary_to_decimal(network_address+i*8));
    strcat(broadcast_address, broadcast_address_octet);
    free(broadcast_address_octet);
    if(i < 3)
      strcat(broadcast_address, ".");
  }

  free(subnet_mask_complement);
  free(network_address);
  for(int i=0; i<4; i++)
    free(subnet_mask_complement_tokens[i]);
}

void parse_ip_address(char *ip_addr, ip_info *ip_details)
{
  char *ip_addr_token;
  ip_addr_token = strtok(ip_addr, "/");

  strcpy(ip_details->ip_addr, ip_addr_token);

  ip_addr_token = strtok(NULL, "/");
  ip_details->cidr = atoi(ip_addr_token);

  memset(ip_details->subnet_mask, '\0', MAX_IP_LEN);
  calculate_subnet_mask(ip_details->cidr, ip_details->subnet_mask);

  memset(ip_details->network_address, '\0', MAX_IP_LEN);
  calculate_network_address(ip_details->ip_addr, ip_details->subnet_mask, ip_details->network_address);

  memset(ip_details->broadcast_address, '\0', MAX_IP_LEN);
  calculate_broadcast_address(ip_details->ip_addr, ip_details->subnet_mask, ip_details->broadcast_address);
}

void print_ip_info(ip_info *ip_details)
{
  printf("IP Address: %s/%d\n", ip_details->ip_addr, ip_details->cidr);
  printf("Subnet Mask: %s\n", ip_details->subnet_mask);
  printf("Network Address: %s\n", ip_details->network_address);
  printf("Broadcast Address: %s\n", ip_details->broadcast_address);
}

int main()
{
  char ip_addr[MAX_IP_LEN];
  printf("Enter IP Address with CIDR notation (e.g. 192.168.0.1/24): ");
  scanf("%s", ip_addr);

  ip_info ip_details;
  parse_ip_address(ip_addr, &ip_details);

  print_ip_info(&ip_details);

  return 0;
}