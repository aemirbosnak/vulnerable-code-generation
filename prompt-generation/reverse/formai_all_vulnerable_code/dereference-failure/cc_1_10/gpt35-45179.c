//FormAI DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function for beautifying html code
void beautify_html(char *code)
{
    int i, j = 0, spaces = 0;
    int size = strlen(code);

    for (i = 0; i < size; i++) {

        //if opening bracket is found
        if (code[i] == '<') {

            //check if it is closing bracket
            if (code[i + 1] == '/') {
                spaces -= 4;
                j -= 4;
            }

            //if not closing tag, add spaces and newline before tag
            else {
                printf("\n");
                for (int x = 0; x < spaces; x++)
                    printf(" ");
                spaces += 4;
            }
        }

        //print character
        printf("%c", code[i]);

        //if closing bracket is found
        if (code[i] == '>') {

            //check if it is closing bracket
            if (code[i - 1] == '/') {
                spaces -= 4;
                j -= 4;
            }

            //if opening tag, add newline after tag
            else {
                printf("\n");
                for (int x = 0; x < spaces; x++)
                    printf(" ");
            }
        }

        //if space is found, skip adding extra space
        if (code[i] == ' ')
            continue;

        j++;
        if (j > 80) {
            printf("\n");
            j = 0;
            for (int x = 0; x < spaces; x++)
                printf(" ");
        }
    }
}

//main function
int main()
{
    char code[10000];
    printf("Enter HTML code to beautify: \n");
    fgets(code, 10000, stdin);
    printf("\n\nOriginal HTML code:\n%s\n\n", code);
    printf("Beautified HTML code:\n");
    beautify_html(code);
    return 0;
}