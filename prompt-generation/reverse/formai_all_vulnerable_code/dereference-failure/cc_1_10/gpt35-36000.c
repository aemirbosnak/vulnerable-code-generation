//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include<stdio.h>

//Function to check if the input character is a valid C cat language character
int isValidCCatChar(char c){
    return (c == 'c' || c == 'a' || c == 't' || c == 'C' || c == 'A' || c == 'T' || c == ' ' || c == '\n');
}

//Function to translate C cat language into English
char* toEnglish(char* cCat){
    char* english = malloc(sizeof(char) * strlen(cCat));   //Allocate memory for the English string
    int i, j = 0;
    for(i=0; cCat[i]!='\0'; i++){
        if(isValidCCatChar(cCat[i])){   //Check if the character is a valid C cat language character
            switch(cCat[i]){
                case 'c':
                    english[j++] = 's';
                    english[j++] = 'p';
                    english[j++] = 'r';
                    english[j++] = 'o';
                    english[j++] = 'c';
                    english[j++] = 'k';
                    english[j++] = '\0';
                    break;
                case 'a':
                    english[j++] = 'l';
                    english[j++] = 'e';
                    english[j++] = 'r';
                    english[j++] = 't';
                    english[j++] = '\0';
                    break;
                case 't':
                    english[j++] = 'l';
                    english[j++] = 'e';
                    english[j++] = 'x';
                    english[j++] = '\0';
                    break;
                case 'C':
                    english[j++] = 'S';
                    english[j++] = 'u';
                    english[j++] = 'b';
                    english[j++] = 'l';
                    english[j++] = 'i';
                    english[j++] = 'm';
                    english[j++] = 'i';
                    english[j++] = 'n';
                    english[j++] = 'a';
                    english[j++] = 'l';
                    english[j++] = '\0';
                    break;
                case 'A':
                    english[j++] = 'R';
                    english[j++] = 'e';
                    english[j++] = 't';
                    english[j++] = 'u';
                    english[j++] = 'r';
                    english[j++] = 'n';
                    english[j++] = '\0';
                    break;
                case 'T':
                    english[j++] = 'P';
                    english[j++] = 'u';
                    english[j++] = 'r';
                    english[j++] = 'r';
                    english[j++] = '\0';
                    break;
                case ' ':
                    english[j++] = ' ';
                    english[j++] = '\0';
                    break;
                case '\n':
                    english[j++] = '\n';
                    english[j++] = '\0';
                    break;
            }
        }
        else{
            english[j++] = '\0';
            printf("Invalid C cat language character found: %c\n", cCat[i]);
            break;
        }
    }
    return english;
}

int main(){
    char cCat[] = "cat\ncat c a t\nCAT C A T";
    char* english = toEnglish(cCat);
    printf("%s\n", english);
    free(english);
    return 0;
}