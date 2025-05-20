//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>

//Function to print a string
void print(char* str) {
    printf("%s", str);
}

//Function to read a line from the file
char* read_line(FILE* file) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    char* buffer = NULL;

    //Allocate memory for the line
    line = malloc(100);
    if (line == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    //Read the line from the file
    while ((read = getline(&buffer, &len, file))!= -1) {
        strncat(line, buffer, read);
    }

    //Free the memory allocated for the buffer
    free(buffer);

    //Add a null character to the end of the line
    line[strlen(line)] = '\0';

    return line;
}

//Function to count the number of words in a line
int count_words(char* line) {
    int count = 0;
    char* word = strtok(line, " ");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

//Function to print a line with the word count
void print_line(char* line, int count) {
    printf("%s (%d words)\n", line, count);
}

//Main function
int main(int argc, char** argv) {
    FILE* file;
    char* line;
    int count;

    //Open the file
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    //Read each line from the file and print it with the word count
    while ((line = read_line(file))!= NULL) {
        count = count_words(line);
        print_line(line, count);
    }

    //Close the file
    fclose(file);

    return 0;
}