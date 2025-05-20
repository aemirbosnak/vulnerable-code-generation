//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAXTAGLEN 64
#define MAXATTRIB 32
#define MAXATTRNAMELEN 32
#define MAXATTRVALLEN 128

typedef struct {
    char name[MAXTAGLEN];
    char attrib[MAXATTRIB][2][MAXATTRVALLEN];
    int attr_count;
    char value[MAXATTRVALLEN];
} XMLTag;

char * get_word(char * line, char ** new_line) {
    char * word, * stop;
    while (*line && isspace(*line)) line++;
    if (!*line) return NULL;
    word = line;
    stop = line;
    while (*stop && !isspace(*stop)) stop++;
    if (*stop) {
        *stop = '\0';
        *new_line = stop + 1;
    } else {
        *new_line = stop;
    }
    return word;
}

char * get_quoted_val(char * line, char ** new_line) {
    char * val;
    if (*line == '\"') {
        val = line + 1;
        *new_line = strchr(val, '\"');
        if (*new_line) {
            **new_line = '\0';
            *new_line += 1;
        }
    } else {
        val = line;
        *new_line = strchr(val, ' ');
        if (*new_line) {
            **new_line = '\0';
            *new_line += 1;
        }
    }
    return val;
}

int parse_attr(char * line, XMLTag * tag) {
    int count = 0;
    char * new_line;
    while (*line && count < MAXATTRIB) {
        char * name = get_word(line, &new_line);
        if (!name) break;
        line = new_line;
        if (*line != '=') {
            printf("Error: malformed attribute name=value pair\n");
            return -1;
        }
        line++;
        char * val = get_quoted_val(line, &new_line);
        if (!val) break;
        strcpy(tag->attrib[count][0], name);
        strcpy(tag->attrib[count][1], val);
        count++;
        line = new_line;
    }
    return count;
}

int get_tag(char * line, XMLTag * tag) {
    if (*line != '<') {
        printf("Error: malformed tag\n");
        return -1;
    }
    line++;
    char * name = get_word(line, &line);
    if (!name) {
        printf("Error: invalid tag name\n");
        return -1;
    }
    strcpy(tag->name, name);
    tag->attr_count = parse_attr(line, tag);
    if (tag->attr_count == -1) {
        printf("Error: malformed attribute in tag %s\n", tag->name);
        return -1;
    }
    return 0;
}

int parse_tag(FILE * fp, XMLTag * tag) {
    char line[MAXTAGLEN + 2];
    if (!fgets(line, MAXTAGLEN + 2, fp)) {
        printf("Error: failed to read tag\n");
        return -1;
    }
    if (get_tag(line, tag)) {
        printf("Error: failed to extract tag information\n");
        return -1;
    }
    return 0;
}

int parse_text(FILE * fp, char * text) {
    int len = 0;
    char c;
    while (1) {
        c = fgetc(fp);
        if (c == '<' || c == EOF) {
            break;
        }
        if (isspace(c)) {
            if (len > 0 && !isspace(text[len-1])) {
                text[len++] = ' ';
            }
        } else {
            text[len++] = c;
        }
    }
    text[len] = '\0';
    if (len == 0) {
        printf("Error: failed to read text\n");
        return -1;
    }
    return 0;
}

int parse_xml(FILE * fp) {
    char line[MAXTAGLEN + 2];
    char text[MAXATTRVALLEN];
    XMLTag tag;
    int tag_count = 0;
    int text_flag = 0;
    while (fgets(line, MAXTAGLEN + 2, fp)) {
        if (strlen(line) > MAXTAGLEN) {
            printf("Error: line too long\n");
            return -1;
        }
        if (*line == '<') {
            if (text_flag) {
                printf("Error: unexpected text before tag\n");
                return -1;
            }
            if (get_tag(line, &tag)) {
                printf("Error: failed to extract tag information\n");
                return -1;
            }
            tag_count++;
            printf("Tag name: %s\n", tag.name);
            printf("Tag attributes:\n");
            for (int i = 0; i < tag.attr_count; i++) {
                printf("%s=\"%s\"\n", tag.attrib[i][0], tag.attrib[i][1]);
            }
        } else {
            if (!text_flag) {
                printf("Error: unexpected text before tag\n");
                return -1;
            }
            if (parse_text(fp, text)) {
                printf("Error: failed to read text\n");
                return -1;
            }
            text_flag = 0;
            printf("Text: %s\n", text);
        }
        if (*line == '>') {
            text_flag = 0;
        } else {
            text_flag = 1;
        }
    }
    printf("Number of tags: %d\n", tag_count);
    return 0;
}

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }
    FILE * fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: failed to open file: %s\n", strerror(errno));
        return -1;
    }
    if (parse_xml(fp)) {
        printf("Error: failed to parse XML file\n");
        fclose(fp);
        return -1;
    }
    fclose(fp);
    return 0;
}