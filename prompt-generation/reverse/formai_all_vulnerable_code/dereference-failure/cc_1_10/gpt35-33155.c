//FormAI DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to convert decimal to binary
char * decToBinary(int decimal_num) {
   int binary_num[100], i = 0;
   char *binStr = malloc(sizeof(char)*100);
   
   while(decimal_num > 0) {
      binary_num[i] = decimal_num%2;
      decimal_num = decimal_num/2;
      i++;
   }
   
   int j;
   for(j = i-1; j >= 0; j--) {
      sprintf(binStr + strlen(binStr), "%d", binary_num[j]);
   }
   
   return binStr;
}

//function to convert binary to decimal
int binaryToDecimal(char *binary_num) {
   int decimal_num = 0, i = 0;
   int len = strlen(binary_num);
   int base = 1;
   
   for (i = len - 1; i >= 0; i--) {
      if (binary_num[i] == '1')
         decimal_num += base;
      base = base * 2;
   }
   
   return decimal_num;
}

int main() {
   int choice = 0;
   int decimal_num;
   char *binary_num;

   while(1) {
      printf("Choose an option: \n");
      printf("1. Convert decimal to binary\n");
      printf("2. Convert binary to decimal\n");
      printf("3. Exit\n");
      
      scanf("%d", &choice);
      
      switch(choice) {
         case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal_num);
            
            binary_num = decToBinary(decimal_num);
            
            printf("Binary equivalent of %d is %s\n", decimal_num, binary_num);
            free(binary_num);
            break;
         case 2:
            printf("Enter a binary number: ");
            scanf("%s", binary_num);
            
            decimal_num = binaryToDecimal(binary_num);
            
            printf("Decimal equivalent of %s is %d\n", binary_num, decimal_num);
            break;
         case 3:
            exit(0);
            break;
         default:
            printf("Invalid choice\n");
            break;
      }
   }
   
   return 0;
}