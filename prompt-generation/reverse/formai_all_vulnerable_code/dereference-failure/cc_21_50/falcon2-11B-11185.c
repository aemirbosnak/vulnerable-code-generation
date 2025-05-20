//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

typedef struct {
    char* word;
    int count;
} Word;

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];

    DIR* dir = opendir(filename);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    Word* words = malloc(sizeof(Word) * 1000);
    if (words == NULL) {
        perror("malloc");
        return 1;
    }

    int count = 0;
    while (1) {
        struct dirent* entry = readdir(dir);
        if (entry == NULL) {
            break;
        }

        char* path = entry->d_name;
        int len = strlen(path);
        if (len < 4 || strcmp(path + len - 4, ".c")!= 0) {
            continue;
        }

        char* file_name = strdup(path);
        int file_size = 0;
        FILE* file = fopen(file_name, "rb");
        if (file == NULL) {
            perror("fopen");
            free(file_name);
            continue;
        }

        fseek(file, 0L, SEEK_END);
        file_size = ftell(file);
        fseek(file, 0L, SEEK_SET);

        char* buffer = malloc(file_size + 1);
        if (buffer == NULL) {
            perror("malloc");
            free(file_name);
            free(words);
            fclose(file);
            return 1;
        }

        fread(buffer, file_size, 1, file);
        fclose(file);

        int i = 0;
        while (i < file_size) {
            int j = 0;
            while (j < file_size) {
                if (isalpha(buffer[i + j])) {
                    if (buffer[i + j] == '\n') {
                        break;
                    }
                    Word word = {.word = strndup(buffer + i, j),.count = 0};
                    if (strstr(buffer + i, ".c")!= NULL) {
                        for (int k = i + j; k < file_size; k++) {
                            if (buffer[k] == '\n' || buffer[k] == '\0') {
                                break;
                            }
                            if (isalpha(buffer[k])) {
                                if (word.count < 1000) {
                                    word.count++;
                                }
                                break;
                            }
                        }
                    } else {
                        for (int k = i + j; k < file_size; k++) {
                            if (buffer[k] == '\n' || buffer[k] == '\0') {
                                break;
                            }
                            if (isalpha(buffer[k])) {
                                if (word.count < 1000) {
                                    word.count++;
                                }
                                break;
                            }
                        }
                    }
                    break;
                }
                j++;
            }
            i++;
        }

        free(buffer);

        int index = 0;
        while (index < count) {
            if (strcmp(words[index].word, words[index + 1].word) == 0) {
                words[index].count++;
                break;
            }
            index++;
        }

        count++;
    }

    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", words[i].count, words[i].word);
    }

    free(words);
    closedir(dir);
    return 0;
}