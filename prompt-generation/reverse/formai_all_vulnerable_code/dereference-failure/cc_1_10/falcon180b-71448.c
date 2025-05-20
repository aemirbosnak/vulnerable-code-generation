//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to reverse a string
void reverse(char* str, int start, int end){
    char temp;
    while(start < end){
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

//Function to check if a string is a palindrome
int isPalindrome(char* str, int start, int end){
    if(start >= end){
        return 1;
    }
    else if(*(str+start)!= *(str+end)){
        return 0;
    }
    else{
        return isPalindrome(str,start+1,end-1);
    }
}

//Function to generate all permutations of a string
void permute(char* str, int start, int end, char* output){
    if(start == end){
        printf("%s\n",output);
        return;
    }
    for(int i=start;i<=end;i++){
        strcpy(output+start,str+i);
        permute(str,start+1,end,output);
    }
}

int main(){
    char input[1000];
    printf("Enter a string: ");
    scanf("%s",input);
    int n = strlen(input);
    char* output = (char*)malloc(n*sizeof(char));
    strcpy(output,input);
    reverse(output,0,n-1);
    if(isPalindrome(output,0,n-1)){
        printf("Palindrome\n");
    }
    else{
        printf("Not a palindrome\n");
    }
    permute(output,0,n-1,"");
    return 0;
}