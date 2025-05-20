//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include<stdio.h>
#include<stdlib.h>

int main() {
    char input[1000];
    printf("Enter the input\n");
    gets(input);
    int i = 0;
    while(input!='\0') {
        switch(input[i]){
            case 'a':
                printf("ab");
                break;
            case 'b':
                printf("cd");
                break;
            case 'c':
                printf("ef");
                break;
            case 'd':
                printf("gh");
                break;
            case 'e':
                printf("ij");
                break;
            case 'f':
                printf("kl");
                break;
            case 'g':
                printf("mn");
                break;
            case 'h':
                printf("op");
                break;
            case 'i':
                printf("qr");
                break;
            case 'j':
                printf("st");
                break;
            case 'k':
                printf("uv");
                break;
            case 'l':
                printf("wx");
                break;
            case 'm':
                printf("yz");
                break;
            case 'n':
                printf("12");
                break;
            case 'o':
                printf("34");
                break;
            case 'p':
                printf("56");
                break;
            case 'q':
                printf("78");
                break;
            case 'r':
                printf("90");
                break;
            case 's':
                printf("!@");
                break;
            case 't':
                printf("#$");
                break;
            case 'u':
                printf("%^");
                break;
            case 'v':
                printf("&*");
                break;  
            default:
                printf("\nUnknown input characters");
            }
            i++;
        }
        printf("\n");
        return 0;
    }