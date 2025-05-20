//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * Function to remove unwanted characters from a string and @ symbol from email ids
 * @param {char *} s - input string
 * @return {char *} - sanitized string
 */
char *sanitize(char *s) {
    char *result = malloc(strlen(s)+1); // allocate memory for resultant string
    int i, j;
    j = 0; // counter for resultant string

    // iterate through input string character by character
    for(i=0; s[i]!='\0'; i++) {
        // check if character is alphanumeric or spaces, if not then skip it
        if(isalnum(s[i]) || s[i]==' ') {
            result[j++] = s[i];
        }
        // check if character is @ symbol in email id, if not then skip it
        else if(s[i]=='@') {
            result[j++] = s[i]; // include @ symbol in resultant string
            i++; // skip to next character
            // iterate through email id to remove unwanted characters
            while(s[i]!='\0' && s[i]!='.') {
                // check if character is alphanumeric, if not then skip it
                if(isalnum(s[i])) {
                    result[j++] = s[i];
                }
                i++; // move to next character
            }
            // include . (dot) symbol if present in email id
            if(s[i]=='.') {
                result[j++] = s[i];
            }
        }
    }
    result[j] = '\0'; // append null character at the end of resultant string
    return result; // return sanitized string
}

int main() {
    char input[100]; // input buffer
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // read input from user

    char *output = sanitize(input); // call sanitize function to sanitize input string
    printf("Sanitized string: %s", output); // print sanitized string

    free(output); // free memory allocated for output string
    return 0;
}