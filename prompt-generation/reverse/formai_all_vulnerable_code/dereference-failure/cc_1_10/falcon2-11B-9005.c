//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 100
#define MIN_LEN 20

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *contents = malloc(size + 1);
    fread(contents, size, 1, file);
    fclose(file);
    contents[size] = '\0';
    return contents;
}

void write_file(const char *filename, char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fwrite(data, strlen(data), 1, file);
    fclose(file);
}

bool is_similar(const char *word1, const char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if (len1 == 0 || len2 == 0) {
        return false;
    }
    if (len1 < MIN_LEN || len2 < MIN_LEN) {
        return false;
    }
    int i, j;
    for (i = 0; i < len1; i++) {
        if (tolower(word1[i])!= tolower(word2[i])) {
            return false;
        }
    }
    for (j = 0; j < len2; j++) {
        if (tolower(word2[j])!= tolower(word1[j])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    char *input_data = read_file(input_file);
    if (input_data == NULL) {
        return 1;
    }

    char *summary_text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed malesuada magna eget nisi rhoncus, ut vestibulum erat bibendum. In ac rutrum tellus, at placerat massa. Aenean et rutrum turpis. Nulla facilisi. Sed eget nunc et sapien volutpat mattis. Curabitur vulputate in velit ac pulvinar. Sed sed condimentum enim, vel lacinia quam. Curabitur dictum, diam eu ultricies euismod, elit lorem tempus leo, vel consectetur purus tortor sed nisi. Nulla facilisi. Suspendisse fermentum, nunc sed lacinia ultrices, quam lorem iaculis sapien, nec tincidunt dolor arcu a velit. In hac habitasse platea dictumst.";

    int i, j;
    for (i = 0; i < strlen(input_data); i++) {
        for (j = i + 1; j < strlen(input_data); j++) {
            if (is_similar(input_data + i, input_data + j)) {
                char *word = malloc((strlen(input_data + i) + 1) * sizeof(char));
                strcpy(word, input_data + i);
                int len = strlen(word);
                for (int k = 0; k < len; k++) {
                    word[k] = tolower(word[k]);
                }
                if (summary_text!= NULL && strlen(summary_text) > 0) {
                    bool found = false;
                    for (int k = 0; k < strlen(summary_text); k++) {
                        if (is_similar(word, summary_text + k)) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        summary_text = strcat(summary_text, " ");
                        strcat(summary_text, word);
                    }
                }
                free(word);
            }
        }
    }

    write_file(output_file, summary_text);
    free(input_data);
    return 0;
}