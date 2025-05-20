//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

void print_usage() {
    printf("Usage: text_processor <filename> <option>\n");
    printf("Options:\n");
    printf("  1. --count    : Count lines in the text file\n");
    printf("  2. --search <word> : Search for a specific word in the text file\n");
    printf("  3. --replace <old> <new> : Replace occurrences of one word with another\n");
    printf("  4. --sort    : Sort the lines in the text file alphabetically\n");
    printf("  5. --reverse  : Reverse the contents of the file\n");
}

void count_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    int count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        count++;
    }

    fclose(file);
    printf("Total lines: %d\n", count);
}

void search_word(const char *filename, const char *word) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, word)) {
            printf("Found '%s' in line %d: %s", word, line_number, line);
            found = 1;
        }
        line_number++;
    }

    if (!found) {
        printf("The word '%s' was not found in the file.\n", word);
    }

    fclose(file);
}

void replace_word(const char *filename, const char *old_word, const char *new_word) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char *lines[MAX_LINES];
    char line[MAX_LINE_LENGTH];
    int count = 0;

    // Read all lines into memory
    while (fgets(line, sizeof(line), file) && count < MAX_LINES) {
        lines[count] = strdup(line);  // Duplicate the line to avoid losing it
        count++;
    }
    fclose(file);

    // Replace occurrences
    for (int i = 0; i < count; i++) {
        char *pos = strstr(lines[i], old_word);
        while (pos != NULL) {
            char temp[MAX_LINE_LENGTH];
            strncpy(temp, lines[i], pos - lines[i]);
            temp[pos - lines[i]] = '\0';
            sprintf(temp + (pos - lines[i]), "%s%s", new_word, pos + strlen(old_word));
            strcpy(lines[i], temp);
            pos = strstr(lines[i], old_word);  // Find next occurrence
        }
    }

    // Write back the modified lines to the file
    file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }
    for (int i = 0; i < count; i++) {
        fputs(lines[i], file);
        free(lines[i]);  // Free duplicated line
    }
    fclose(file);
    printf("Replaced all occurrences of '%s' with '%s'.\n", old_word, new_word);
}

void sort_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char *lines[MAX_LINES];
    char line[MAX_LINE_LENGTH];
    int count = 0;

    // Read all lines into memory
    while (fgets(line, sizeof(line), file) && count < MAX_LINES) {
        lines[count] = strdup(line);  // Duplicate the line for sorting
        count++;
    }
    fclose(file);

    // Sort the lines
    qsort(lines, count, sizeof(char*), (int (*)(const void*, const void*))strcmp);

    // Write sorted lines back to file
    file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }
    for (int i = 0; i < count; i++) {
        fputs(lines[i], file);
        free(lines[i]);  // Free duplicated line
    }
    fclose(file);
    printf("Sorted the lines in alphabetical order.\n");
}

void reverse_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char *lines[MAX_LINES];
    char line[MAX_LINE_LENGTH];
    int count = 0;

    // Read all lines into memory
    while (fgets(line, sizeof(line), file) && count < MAX_LINES) {
        lines[count] = strdup(line);  // Duplicate the line for reversing
        count++;
    }
    fclose(file);

    // Write reversed lines back to file
    file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }
    for (int i = count - 1; i >= 0; i--) {
        fputs(lines[i], file);
        free(lines[i]);  // Free duplicated line
    }
    fclose(file);
    printf("Reversed the contents of the file.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage();
        return 1;
    }

    const char *filename = argv[1];
    const char *option = argv[2];

    if (strcmp(option, "--count") == 0) {
        count_lines(filename);
    } else if (strcmp(option, "--search") == 0 && argc == 4) {
        search_word(filename, argv[3]);
    } else if (strcmp(option, "--replace") == 0 && argc == 5) {
        replace_word(filename, argv[3], argv[4]);
    } else if (strcmp(option, "--sort") == 0) {
        sort_lines(filename);
    } else if (strcmp(option, "--reverse") == 0) {
        reverse_file(filename);
    } else {
        print_usage();
        return 1;
    }

    return 0;
}