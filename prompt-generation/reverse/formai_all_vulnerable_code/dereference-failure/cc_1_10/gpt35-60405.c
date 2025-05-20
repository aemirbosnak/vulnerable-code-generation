//FormAI DATASET v1.0 Category: HTML beautifier ; Style: creative
#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fp, *out;
    char file_name[100];
    char c;
    int flag = 0;
    int num_of_spaces = 0;

    printf("Enter the name of the HTML file to be beautified: ");
    scanf("%s", file_name);

    // Open the input file
    fp = fopen(file_name, "r"); 

    // Check if input file exists
    if (fp == NULL) {
        printf("Unable to open file. \n");
        exit(1);
    }

    // Open a new output file
    out = fopen("beautified.html", "w");

    // Check if output file exists
    if (out == NULL) {
        printf("Unable to create the output file. \n");
        exit(1);
    }

    while ((c = fgetc(fp)) != EOF) {
        if (c == '<') {
            flag = 1;
        }

        if (flag == 1) {
            fputc(c, out);

            if (c == '>') {
                flag = 0;

                if (num_of_spaces > 0) {
                    fputc('\n', out);
                    num_of_spaces = 0;
                }
            }

            if (c == ' ') {
                num_of_spaces++;
            }
        }

        else {
            fputc(c, out);
        }
    }

    // Close both files
    fclose(fp);
    fclose(out);

    printf("Beautified HTML code has been written to beautified.html");

    return 0;
}