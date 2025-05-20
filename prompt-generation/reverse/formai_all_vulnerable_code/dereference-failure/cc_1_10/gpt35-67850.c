//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void clearInputBuffer(){
    while ( getchar() != '\n' );
}

char* convertToBinary(int num){
    int binary[32];
    int i=0;
    while(num>0){
        binary[i++]=num%2;
        num/=2;
    }
    int j=0;
    char* binaryString = malloc(33*sizeof(char));
    for(i=i-1;i>=0;i--){
        binaryString[j++]=(char)binary[i]+'0';
    }
    binaryString[j]='\0';
    return binaryString;
}

int convertToDecimal(char* binary){
    int decimal=0;
    int len = strlen(binary);
    for(int i=len-1;i>=0;i--){
        if(binary[i]=='1'){
            decimal+=pow(2,len-1-i);
        }
    }
    return decimal;
}

int main(){
    printf("Welcome to Binary Converter by Ken Thompson!\n");
    char choice;
    do{
        printf("\nPlease select an option:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Exit the program\n");
        printf("\nEnter your choice: ");
        scanf("%c",&choice);
        clearInputBuffer();
        switch (choice)
        {
        case '1':
            printf("\nEnter decimal number to convert to binary: ");
            int decimal;
            scanf("%d",&decimal);
            clearInputBuffer();
            printf("Binary equivalent of %d is: %s\n",decimal,convertToBinary(decimal));
            break;
        case '2':
            printf("\nEnter binary number to convert to decimal: ");
            char binary[33];
            fgets(binary,sizeof(binary),stdin);
            binary[strcspn(binary, "\n")] = '\0';
            printf("Decimal equivalent of %s is: %d\n",binary,convertToDecimal(binary));
            break;
        case '3':
            printf("\nExiting program. Goodbye!\n");
            exit(0);
        default:
            printf("\nInvalid option selected. Please try again.\n");
            break;
        }
    }while(1);
    return 0;
}