//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 50
#define MAX_WORDS_PER_LINE 100

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char) *str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) end--;

    // Null terminate after last non-space character
    *(end + 1) = '\0';
}

int count_words(char *line) {
    int count = 0;
    char *token = strtok(line, " \t\n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    return count;
}

void parse_and_count(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int total_lines = 0, total_words = 0;

    while (fgets(line, sizeof(line), file)) {
        trim_whitespace(line);
        if (strlen(line) > 0) {
            total_lines++;
            char buffer[MAX_LINE_LENGTH];
            strcpy(buffer, line);  // Create a copy for word counting
            int words_in_line = count_words(buffer);
            total_words += words_in_line;
            printf("Line %d has %d words: %s\n", total_lines, words_in_line, line);
        }
    }

    printf("\nTotal Lines: %d\nTotal Words: %d\n", total_lines, total_words);
    fclose(file);
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void write_reversed_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    FILE *output_file = fopen("reversed_lines.txt", "w");
    if (output_file == NULL) {
        perror("Could not create output file");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        trim_whitespace(line);
        if (strlen(line) > 0) {
            reverse_string(line);
            fprintf(output_file, "%s\n", line);
        }
    }

    fclose(file);
    fclose(output_file);
    printf("Reversed lines written to reversed_lines.txt\n");
}

void find_and_replace(char *line, const char *to_find, const char *replace_with) {
    char buffer[MAX_LINE_LENGTH];
    char *pos, *start = line;
    int len_to_find = strlen(to_find);
    int len_replace_with = strlen(replace_with);
    buffer[0] = '\0';

    while ((pos = strstr(start, to_find)) != NULL) {
        strncat(buffer, start, pos - start);
        strcat(buffer, replace_with);
        start = pos + len_to_find;
    }
    strcat(buffer, start);
    strcpy(line, buffer);
}

void replace_in_file(const char *filename, const char *to_find, const char *replace_with) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    FILE *output_file = fopen("replaced_lines.txt", "w");
    if (!output_file) {
        perror("Unable to create output file");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        trim_whitespace(line);
        find_and_replace(line, to_find, replace_with);
        fprintf(output_file, "%s\n", line);
    }

    fclose(file);
    fclose(output_file);
    printf("Replaced lines written to replaced_lines.txt\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];

    parse_and_count(filename);
    write_reversed_lines(filename);

    const char *to_find = "old_word";
    const char *replace_with = "new_word";
    replace_in_file(filename, to_find, replace_with);
  
    return 0;
}