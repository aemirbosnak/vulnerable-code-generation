//FormAI DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple program to parse C syntax and detect syntax errors */

typedef enum {
    LBRACE, RBRACE, LBRACKET, RBRACKET, LPAREN, RPAREN, SEMICOLON, COMMA, ASSIGN, KEYWORD, IDENTIFIER, INT_LITERAL, FLOAT_LITERAL, CHAR_LITERAL, STRING_LITERAL, PLUS, MINUS, MUL, DIV, MOD, SHL, SHR, AND, OR, XOR, NOT, LAND, LOR, LNOT, EQ, NEQ, LT, GT, LE, GE
} TokenType;

typedef struct {
    TokenType type;
    char* lexeme;
    int line;
} Token;

Token lex(char* source, int* position, int* line) {
    Token token;
    token.line = *line;
    token.lexeme = malloc(sizeof(char) * 256);
    memset(token.lexeme, 0, sizeof(char) * 256);
    char ch = source[*position];
    while (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n') {
        if (ch == '\n') {
            (*line)++;
        }
        (*position)++;
        ch = source[*position];
    }
    if (ch == 0) {
        token.type = -1;
        return token;
    }
    if (ch == '{') {
        token.type = LBRACE;
    } else if (ch == '}') {
        token.type = RBRACE;
    } else if (ch == '[') {
        token.type = LBRACKET;
    } else if (ch == ']') {
        token.type = RBRACKET;
    } else if (ch == '(') {
        token.type = LPAREN;
    } else if (ch == ')') {
        token.type = RPAREN;
    } else if (ch == ';') {
        token.type = SEMICOLON;
    } else if (ch == ',') {
        token.type = COMMA;
    } else if (ch == '+') {
        token.type = PLUS;
    } else if (ch == '-') {
        token.type = MINUS;
    } else if (ch == '*') {
        token.type = MUL;
    } else if (ch == '/') {
        token.type = DIV;
    } else if (ch == '%') {
        token.type = MOD;
    } else if (ch == '<') {
        if (source[*position + 1] == '<') {
            token.type = SHL;
            (*position)++;
        } else if (source[*position + 1] == '=') {
            token.type = LE;
            (*position)++;
        } else {
            token.type = LT;
        }
    } else if (ch == '>') {
        if (source[*position + 1] == '>') {
            token.type = SHR;
            (*position)++;
        } else if (source[*position + 1] == '=') {
            token.type = GE;
            (*position)++;
        } else {
            token.type = GT;
        }
    } else if (ch == '=') {
        if (source[*position + 1] == '=') {
            token.type = EQ;
            (*position)++;
        } else {
            token.type = ASSIGN;
        }
    } else if (ch == '!') {
        if (source[*position + 1] == '=') {
            token.type = NEQ;
            (*position)++;
        } else {
            token.type = LNOT;
        }
    } else if (ch == '&') {
        if (source[*position + 1] == '&') {
            token.type = LAND;
            (*position)++;
        } else {
            token.type = AND;
        }
    } else if (ch == '|') {
        if (source[*position + 1] == '|') {
            token.type = LOR;
            (*position)++;
        } else {
            token.type = OR;
        }
    } else if (ch == '^') {
        token.type = XOR;
    } else if (ch == '\'') {
        token.type = CHAR_LITERAL;
        (*position)++;
        ch = source[*position];
        token.lexeme[0] = ch;
        (*position)++;
        ch = source[*position];
        if (ch != '\'') {
            printf("Error: Syntax error on line %d. Invalid char literal.\n", *line);
        }
    } else if (ch == '\"') {
        token.type = STRING_LITERAL;
        (*position)++;
        ch = source[*position];
        int i = 0;
        while (ch != '\"' && i < 255) {
            token.lexeme[i] = ch;
            i++;
            (*position)++;
            ch = source[*position];
        }
        token.lexeme[i] = '\0';
        if (ch != '\"') {
            printf("Error: Syntax error on line %d. Invalid string literal.\n", *line);
        }
    } else if (isdigit(ch)) {
        token.type = INT_LITERAL;
        int i = 0;
        while (isdigit(ch) && i < 255) {
            token.lexeme[i] = ch;
            i++;
            (*position)++;
            ch = source[*position];
        }
        if (ch == '.') {
            token.type = FLOAT_LITERAL;
            token.lexeme[i] = ch;
            i++;
            (*position)++;
            ch = source[*position];
            while (isdigit(ch) && i < 255) {
                token.lexeme[i] = ch;
                i++;
                (*position)++;
                ch = source[*position];
            }
        }
        token.lexeme[i] = '\0';
        (*position)--;
    } else if (isalpha(ch) || ch == '_') {
        int i = 0;
        while ((isalnum(ch) || ch == '_') && i < 255) {
            token.lexeme[i] = ch;
            i++;
            (*position)++;
            ch = source[*position];
        }
        token.lexeme[i] = '\0';
        if (strcmp(token.lexeme, "if") == 0 || strcmp(token.lexeme, "else") == 0 ||
            strcmp(token.lexeme, "while") == 0 || strcmp(token.lexeme, "for") == 0 ||
            strcmp(token.lexeme, "do") == 0 || strcmp(token.lexeme, "int") == 0 ||
            strcmp(token.lexeme, "float") == 0 || strcmp(token.lexeme, "char") == 0 ||
            strcmp(token.lexeme, "void") == 0 || strcmp(token.lexeme, "return") == 0) {
            token.type = KEYWORD;
        } else {
            token.type = IDENTIFIER;
        }
        (*position)--;
    } else {
        printf("Error: Syntax error on line %d. Invalid character '%c'.\n", *line, ch);
    }
    (*position)++;
    return token;
}

int main() {
    char source[] = "#include <stdio.h>\nint main() {\nint a = 5;\nint b = 10;\nint c = a + b;\nprintf(\"%d\", c);\nreturn 0;\n}";
    int position = 0;
    int line = 1;
    Token token;
    do {
        token = lex(source, &position, &line);
        if (token.type != -1) {
            printf("Token: %d, Lexeme: %s, Line: %d\n", token.type, token.lexeme, token.line);
        }
    } while (token.type != -1);
    return 0;
}