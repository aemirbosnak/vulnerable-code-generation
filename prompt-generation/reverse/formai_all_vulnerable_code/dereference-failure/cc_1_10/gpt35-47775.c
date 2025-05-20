//FormAI DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to convert RGB to Hexadecimal
char* RGBtoHex(int r, int g, int b) {
  char* hex = (char*)malloc(sizeof(char)*8);
  sprintf(hex, "#%02X%02X%02X", r, g, b); //format string to add leading 0's

  return hex;
}

//Function to convert Hexadecimal to RGB
void HexToRGB(char* hex, int* r, int* g, int* b) {

  //strip the '#' symbol from the front of the hexadecimal string
  if (hex[0] == '#') {
    hex++;
  }

  //split the hexadecimal string into three parts for Red, Green and Blue values
  char r_hex[3] = {hex[0], hex[1], '\0'};
  char g_hex[3] = {hex[2], hex[3], '\0'};
  char b_hex[3] = {hex[4], hex[5], '\0'};

  //convert hexadecimal strings to integer values
  *r = (int)strtol(r_hex, NULL, 16);
  *g = (int)strtol(g_hex, NULL, 16);
  *b = (int)strtol(b_hex, NULL, 16);

}

int main() {

  int r, g, b; //variables to store RGB values
  char hex[8]; //variable to store Hexadecimal value
  
  printf("------ RGB to Hexadecimal Converter ------\n");
  
  //Get inputs for RGB values from user
  printf("Enter the Red value (0-255): ");
  scanf("%d", &r);
  printf("Enter the Green value (0-255): ");
  scanf("%d", &g);
  printf("Enter the Blue value (0-255): ");
  scanf("%d", &b);
  
  //Convert RGB to Hexadecimal
  char* hex_val = RGBtoHex(r, g, b);
  printf("The Hexadecimal value is: %s \n", hex_val);

  //Get input for Hexadecimal value from user
  printf("\n------ Hexadecimal to RGB Converter ------\n");
  printf("Enter the Hexadecimal value (e.g #FF00FF): ");
  scanf("%s", hex);
  
  //Convert Hexadecimal to RGB
  int r_val, g_val, b_val;
  HexToRGB(hex, &r_val, &g_val, &b_val);
  printf("The RGB values are: %d, %d, %d", r_val, g_val, b_val);

  return 0;
}