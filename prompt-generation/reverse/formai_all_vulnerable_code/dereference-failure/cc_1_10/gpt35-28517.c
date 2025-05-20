//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_JSON_LENGTH 1000

typedef struct {
    char key[100];
    char value[100];
} JsonKeyValue;

typedef struct {
    JsonKeyValue values[MAX_STACK_SIZE];
    int length;
} JsonStack;

JsonStack* push(JsonStack* stack, JsonKeyValue value) {
    if (stack->length == MAX_STACK_SIZE) {
        printf("Error: Stack overflow!");
        return stack;
    }

    stack->values[stack->length++] = value;
    return stack;
}

JsonStack* pop(JsonStack* stack) {
    if (stack->length == 0) {
        printf("Error: Stack underflow!");
        return stack;
    }

    stack->length--;
    return stack;
}

int isWhiteSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int isInRange(char c, char start, char end) {
    return c >= start && c <= end;
}

int isNumeric(char c) {
    return isInRange(c, '0', '9') || c == '-' || c == '+';
}

int isToken(char c) {
    return c == '{' || c == '}' || c == '[' || c == ']' || c == ',' || c == ':';
}

JsonStack* parseJson(char* json) {
    JsonStack* stack = (JsonStack*) malloc(sizeof(JsonStack));
    stack->length = 0;

    int length = strlen(json);

    char buffer[MAX_JSON_LENGTH];
    int bufferLength = 0;

    JsonKeyValue currentKeyValue;

    enum {
        Start,
        ExpectKeyOrEnd,
        ExpectColon,
        ExpectValue,
        ExpectCommaOrEnd
    } state = Start;

    for (int i = 0; i < length; i++) {
        char c = json[i];

        switch (state) {
            case Start:
                if (isWhiteSpace(c)) {
                    continue;
                }

                if (c != '{') {
                    printf("Error: Expected start of JSON object.\n");
                    return NULL;
                }

                state = ExpectKeyOrEnd;
                break;
            case ExpectKeyOrEnd:
                if (isWhiteSpace(c)) {
                    continue;
                }

                if (c == '}') {
                    if (bufferLength > 0) {
                        printf("Error: Expected key before closing brace.\n");
                        return NULL;
                    }

                    if (stack->length == 0) {
                        return stack;
                    }

                    pop(stack);
                    state = ExpectCommaOrEnd;
                    continue;
                }

                if (c == '"') {
                    bufferLength = 0;
                    state = ExpectColon;
                    continue;
                }

                printf("Error: Expected key or end of object.\n");
                return NULL;
            case ExpectColon:
                if (c == '"') {
                    currentKeyValue.key[bufferLength] = '\0';
                    bufferLength = 0;
                    state = ExpectValue;
                    continue;
                }

                currentKeyValue.key[bufferLength++] = c;
                continue;
            case ExpectValue:
                if (isWhiteSpace(c)) {
                    continue;
                }

                if (c == ':') {
                    state = ExpectCommaOrEnd;
                    continue;
                }

                printf("Error: Expected colon after key.\n");
                return NULL;
            case ExpectCommaOrEnd:
                if (isWhiteSpace(c)) {
                    continue;
                }

                if (c == ',') {
                    if (stack->length == 0) {
                        printf("Error: Unexpected comma outside of object or array.\n");
                        return NULL;
                    }

                    push(stack, currentKeyValue);
                    bufferLength = 0;
                    state = ExpectKeyOrEnd;
                    continue;
                }

                if (c == '}') {
                    if (stack->length == 0) {
                        printf("Error: Unexpected closing brace.\n");
                        return NULL;
                    }

                    if (bufferLength > 0) {
                        printf("Error: Expected value before closing brace.\n");
                        return NULL;
                    }

                    pop(stack);
                    state = ExpectCommaOrEnd;
                    continue;
                }

                if (isNumeric(c) || c == '"') {
                    bufferLength = 0;
                    state = ExpectValue;
                    i--;
                    continue;
                }

                printf("Error: Expected value after colon.\n");
                return NULL;
            default:
                printf("Error: Invalid state.\n");
                return NULL;
        }

        if (isToken(c)) {
            if (bufferLength > 0) {
                printf("Error: Invalid token location.\n");
                return NULL;
            }

            if (c == '{') {
                currentKeyValue.value[0] = '\0';
                push(stack, currentKeyValue);
                continue;
            }

            if (c == '}') {
                continue;
            }

            if (c == '[') {
                printf("Error: Array not supported.\n");
                return NULL;
            }

            if (c == ']') {
                printf("Error: Array not supported.\n");
                return NULL;
            }

            if (c == ',') {
                continue;
            }

            if (c == ':') {
                continue;
            }

            printf("Error: Invalid token.\n");
            return NULL;
        }

        buffer[bufferLength++] = c;

        if (bufferLength == MAX_JSON_LENGTH) {
            printf("Error: Buffer overflow.\n");
            return NULL;
        }
    }

    return stack;
}

int main() {
    char* json = "{\n\"a\": 1,\n  \"b\": {\n    \"c\": true,\n    \"d\": \"foo\"\n  },\n\"e\": []\n}";
    JsonStack* stack = parseJson(json);

    if (stack != NULL) {
        printf("JSON successfully parsed.\n");
    }
}