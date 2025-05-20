//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct {
 char word[50];
 int is_valid;
} dictionary_entry;

int main(int argc, char **argv) {
 if (argc != 3) {
 printf("Usage: %s <word> <dictionary>\n", argv[0]);
 return 1;
 }

 int fd = open(argv[2], O_RDONLY);
 if (fd < 0) {
 perror("Error opening dictionary file");
 return 1;
 }

 int num_entries = 0;
 int word_length = strlen(argv[1]);
 dictionary_entry *dict = malloc(sizeof(dictionary_entry) * (word_length + 1));

 if (!dict) {
 perror("Error allocating memory for dictionary");
 close(fd);
 return 1;
 }

 char c;
 int pos = 0;
 while ((c = getc(fd)) != EOF) {
 if (c == '\n') {
 num_entries++;
 if (pos >= word_length) {
 pos = 0;
 dict[num_entries].is_valid = 0;
 }
 continue;
 }
 dict[pos].word[pos++] = c;
 }
 fclose(fd);

 for (int i = 0; i <= num_entries; i++) {
 if (strncmp(argv[1], dict[i].word, word_length) == 0) {
 dict[i].is_valid = 1;
 break;
 }
 }

 if (dict[num_entries].is_valid) {
 printf("%s is a valid word.\n", argv[1]);
 } else {
 printf("%s is not a valid word.\n", argv[1]);
 }

 free(dict);
 return 0;
}