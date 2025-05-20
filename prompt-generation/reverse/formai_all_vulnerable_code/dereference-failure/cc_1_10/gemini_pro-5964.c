//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Cryptic
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define INDEX(x) ((x)=='a'?10:(x)=='b'?11:(x)=='c'?12:(x)=='d'?13:(x)=='e'?14:(x)=='f'?15:0)

bool is_hexa(char x){
    return (x>='0'&&x<='9')||(x>='a'&&x<='f')||(x>='A'&&x<='F');
}

int convert(char *str){
    int len=strlen(str);
    int ans=0;
    for(int i=len-1,j=1;i>=0;i--,j*=16)
        if(is_hexa(str[i]))
            ans+=j*INDEX(str[i]);
    return ans;
}

void twos_compliment(char *str, int arr[8]){
    for(int i=0,j=7;i<8;i++,j--)
        arr[i]=str[j];
    int carry=1;
    for(int i=7;i>=0;i--){
        if(arr[i]+carry==2){
            arr[i]=0;
            carry=1;
        }
        else if(arr[i]+carry==1){
            arr[i]=1;
            carry=0;
        }
        else
            carry=0;
    }
}

void display(int arr[8]){
    for(int i=0;i<8;i++)
        printf("%d",arr[i]);
}

int main(){
    //input
    char str[]="110";
    printf("Original Hexadecimal Number: %s\n",str);

    //convert
    printf("Equivalent decimal number: %d\n",convert(str));

    //twos_compliment
    int arr[8];
    twos_compliment(str,arr);
    printf("Twos complement of the binary equivalent: ");
    display(arr);
}