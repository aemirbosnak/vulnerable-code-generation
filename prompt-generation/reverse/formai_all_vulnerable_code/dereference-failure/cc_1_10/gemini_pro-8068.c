//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int length;
} Text;

typedef struct {
    Text *texts;
    int count;
} TextList;

TextList *createTextList() {
    TextList *list = malloc(sizeof(TextList));
    list->texts = NULL;
    list->count = 0;
    return list;
}

void addText(TextList *list, char *text) {
    list->texts = realloc(list->texts, (list->count + 1) * sizeof(Text));
    list->texts[list->count].text = strdup(text);
    list->texts[list->count].length = strlen(text);
    list->count++;
}

char *summarizeText(TextList *list) {
    int totalLength = 0;
    for (int i = 0; i < list->count; i++) {
        totalLength += list->texts[i].length;
    }

    char *summary = malloc(totalLength + 1);
    int summaryLength = 0;
    for (int i = 0; i < list->count; i++) {
        memcpy(summary + summaryLength, list->texts[i].text, list->texts[i].length);
        summaryLength += list->texts[i].length;
    }
    summary[summaryLength] = '\0';

    return summary;
}

void freeTextList(TextList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->texts[i].text);
    }
    free(list->texts);
    free(list);
}

int main() {
    TextList *list = createTextList();
    addText(list, "This is the first text.");
    addText(list, "This is the second text.");
    addText(list, "This is the third text.");

    char *summary = summarizeText(list);
    printf("Summary: %s\n", summary);

    freeTextList(list);
    free(summary);

    return 0;
}