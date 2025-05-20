//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: optimized
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

//function to check if character is upper case letter
int is_upper(char c){
    if(c>='A' && c<='Z'){
        return 1;
    }
    return 0; 
}

//function to check if character is lower case letter
int is_lower(char c){
    if(c>='a' && c<='z'){
        return 1;
    }
    return 0; 
}

//function to check if character is digit
int is_digit(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    return 0; 
}

//function to check if character is special symbol
int is_special(char c){
    if(ispunct(c)){
        return 1;
    }
    return 0;
}

//function to check password strength
int check_password(char* password){
    int length=strlen(password);
    int upper=0,lower=0,digit=0,special=0;
    for(int i=0;i<length;i++){
        if(is_upper(password[i])) upper=1;
        else if(is_lower(password[i])) lower=1;
        else if(is_digit(password[i])) digit=1;
        else if(is_special(password[i])) special=1;
    }
    if(length<=8){
        printf("\nWeak Password! Password length should be greater than 8 characters.\n");
        return 0;
    }
    else if(upper==0 || lower==0 || digit==0 || special==0){
        printf("\nMedium Password! Password must contain at least one uppercase letter, one lowercase letter, one digit and one special symbol.\n");
        return 1;
    }
    else{
        printf("\nStrong Password! Password meets all the criteria for a strong password.\n");
        return 2;
    }
}

int main(){
    char* password=(char*)malloc(sizeof(char)*100);
    printf("Enter Password: ");
    fgets(password,100,stdin);
    int strength=check_password(password);
    free(password);
    return 0;
}