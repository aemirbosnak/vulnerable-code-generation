//FormAI DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// Function to count the number of spaces in a row
int countSpaces(char *line) {
    int count = 0;
    int i = 0;
    while (line[i] == ' ') {
        count++;
        i++;
    }
    return count;
}

// Function to remove leading and trailing spaces from a line
void trim(char *line) {
    char *end;
    end = line + strlen(line) - 1;
    while(end > line && isspace(*end)) end--;
    *(end+1) = '\0';

    while(*line && isspace(*line)) line++;
    if (line != end) {
        memmove(line, end+1, strlen(end+1)+1);
    }
}

// Function to beautify the HTML code
void beautify(char *fileContent, int fileLength) {
    int i = 0;
    int spaces = 0;
    char *line = strtok(fileContent, "\n");

    while (line != NULL) {
        trim(line);

        if (strlen(line) == 0) {
            printf("\n");
            line = strtok(NULL, "\n");
            continue;
        }

        spaces += countSpaces(line);

        if (strstr(line, "</") != NULL) {
            spaces -= 2;
        }

        if (spaces < 0) {
            spaces = 0;
        }

        for (i = 0; i < spaces; i++) {
            printf(" ");
        }

        printf("%s\n", line);

        if (strstr(line, "<") != NULL && strstr(line, "</") == NULL && strstr(line, "/>") == NULL) {
            spaces += 2;
        }

        line = strtok(NULL, "\n");
    }
}

// Function to read the contents of an HTML file
void readFile(char *fileName) {
    FILE *fp;
    char *content;
    long fileSize;

    fp = fopen(fileName, "rb");

    if (fp != NULL) {
        fseek(fp, 0, SEEK_END);
        fileSize = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        content = malloc(fileSize + 1);
        fread(content, fileSize, 1, fp);
        fclose(fp);

        content[fileSize] = '\0';

        beautify(content, fileSize);

        free(content);
    }
}

int main() {
    char fileName[255];

    printf("Enter name of HTML file: ");
    scanf("%s", fileName);

    readFile(fileName);

    return 0;
}