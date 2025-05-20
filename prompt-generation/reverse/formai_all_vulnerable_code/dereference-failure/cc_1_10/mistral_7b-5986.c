//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: puzzling
#include <stdio.h>
#include <string.h>
#define SIZE 100
char str[SIZE];
int main() {
    char *ptr1, *ptr2, *ptr3;
    int len, i;
    
    printf("Enter a string: ");
    fgets(str, SIZE, stdin);
    
    len = strlen(str);
    
    ptr1 = str + (len - 1); // point to last character
    ptr2 = str; // point to first character
    
    for(i = 0; i < len/2; i++) { // swap characters
        char temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1--;
        ptr2++;
    }
    
    printf("Reversed string: ");
    puts(str); // prints reversed string
    
    // now, let's find if the string is palindrome
    ptr1 = str;
    ptr3 = str + len - 1;
    
    while(ptr1 < ptr3) { // if strings are not equal, it's not a palindrome
        if(*ptr1 != *ptr3) {
            printf("Not a palindrome.\n");
            return 0;
        }
        ptr1++;
        ptr3--;
    }
    
    printf("Palindrome.\n");
    
    // now, let's print the string in Warnes's 61n rule
    for(i = len - 1; i >= 0; i--) { // print last character
        printf("%c", str[i]);
    }
    printf(" %c\n", str[0]); // print first character
    
    for(i = 1; i < len; i += 2) { // print every other character
        printf("%c%c", str[i], str[i+1]);
    }
    
    return 0;
}