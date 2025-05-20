//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct c_ode {
    char code;
    char next_code;
    int line;
    struct c_ode *next;
};

struct c_ode *head, *tail;

void add_code(char code, char next_code, int line) {
    struct c_ode *new_code = malloc(sizeof(struct c_ode));
    new_code->code = code;
    new_code->next_code = next_code;
    new_code->line = line;
    new_code->next = NULL;
    if (head == NULL) {
        head = new_code;
        tail = new_code;
    } else {
        tail->next = new_code;
        tail = new_code;
    }
}

void read_code(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[1024];
    int line_number = 1;
    while (fgets(line, sizeof(line), fp)) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '\n') {
                line_number++;
            } else {
                add_code(line[i], line[i + 1], line_number);
            }
        }
    }
    fclose(fp);
}

void print_code() {
    struct c_ode *current_code = head;
    while (current_code != NULL) {
        printf("%c%c%d\n", current_code->code, current_code->next_code, current_code->line);
        current_code = current_code->next;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    read_code(argv[1]);
    print_code();
    return 0;
}