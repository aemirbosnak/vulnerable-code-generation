//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(int argc, char *argv[]){

    char input[50], celsius, fahrenheit;
    int choice, len;

    printf("Enter temperature in Celsius or Fahrenheit: ");
    scanf("%s", input);

    len = strlen(input);

    if(strcmp(input+len-2, "C") == 0){
        celsius = 1;
        fahrenheit = 0;
    }
    else if(strcmp(input+len-2, "F") == 0){
        celsius = 0;
        fahrenheit = 1;
    }
    else{
        printf("Invalid input.\n");
        exit(0);
    }

    printf("Enter 1 to convert to Celsius or 2 to convert to Fahrenheit: ");
    scanf("%d", &choice);

    if(choice == 1){
        if(celsius == 1){
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", atof(input), (atof(input)*1.8)+32);
        }
        else{
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", atof(input), (atof(input)-32)/1.8);
        }
    }
    else if(choice == 2){
        if(celsius == 1){
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", atof(input), (atof(input)*1.8)+32);
        }
        else{
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", atof(input), (atof(input)-32)/1.8);
        }
    }
    else{
        printf("Invalid choice.\n");
        exit(0);
    }

    return 0;
}