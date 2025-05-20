//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} attr_t;

typedef struct {
    char *name;
    attr_t *attrs;
    size_t num_attrs;
    struct tag *parent;
} tag_t;

typedef struct {
    tag_t *root;
    tag_t *current;
} document_t;

static char *html_escape(const char *str) {
    char *buf = malloc(strlen(str) * 3 + 1);
    char *p = buf;
    while (*str) {
        switch (*str) {
            case '<': *p++ = '&'; *p++ = 'l'; *p++ = 't'; *p++ = ';'; break;
            case '>': *p++ = '&'; *p++ = 'g'; *p++ = 't'; *p++ = ';'; break;
            case '"': *p++ = '&'; *p++ = 'q'; *p++ = 'u'; *p++ = 'o'; *p++ = 't'; *p++ = ';'; break;
            case '&': *p++ = '&'; *p++ = 'a'; *p++ = 'm'; *p++ = 'p'; *p++ = ';'; break;
            default: *p++ = *str;
        }
        str++;
    }
    *p = '\0';
    return buf;
}

static char *attr_to_string(const attr_t *attr) {
    char *buf = malloc(strlen(attr->name) + strlen(attr->value) + 3);
    sprintf(buf, "%s=\"%s\"", attr->name, html_escape(attr->value));
    return buf;
}

static char *tag_to_string(const tag_t *tag) {
    size_t i;
    char *buf = malloc(strlen(tag->name) + 2 + (tag->num_attrs * 20));
    sprintf(buf, "<%s", tag->name);
    for (i = 0; i < tag->num_attrs; i++) {
        strcat(buf, " ");
        strcat(buf, attr_to_string(&tag->attrs[i]));
    }
    strcat(buf, ">");
    return buf;
}

static char *document_to_string(const document_t *doc) {
    return tag_to_string(doc->root);
}

static void tag_free(tag_t *tag) {
    size_t i;
    free(tag->name);
    for (i = 0; i < tag->num_attrs; i++) {
        free(tag->attrs[i].name);
        free(tag->attrs[i].value);
    }
    free(tag->attrs);
    free(tag);
}

static void document_free(document_t *doc) {
    tag_free(doc->root);
    free(doc);
}

static tag_t *document_create_tag(document_t *doc, const char *name) {
    tag_t *tag = malloc(sizeof(tag_t));
    tag->name = strdup(name);
    tag->attrs = NULL;
    tag->num_attrs = 0;
    tag->parent = doc->current;
    if (doc->current) {
        doc->current->num_attrs++;
        doc->current->attrs = realloc(doc->current->attrs, sizeof(attr_t) * doc->current->num_attrs);
        doc->current->attrs[doc->current->num_attrs - 1] = (attr_t) {0, 0};
        doc->current->attrs[doc->current->num_attrs - 1].name = strdup(name);
    } else {
        doc->root = tag;
    }
    doc->current = tag;
    return tag;
}

static void document_add_attr(document_t *doc, const char *name, const char *value) {
    attr_t *attr = &doc->current->attrs[doc->current->num_attrs - 1];
    attr->value = strdup(value);
}

int main(void) {
    document_t *doc = malloc(sizeof(document_t));
    document_create_tag(doc, "html");
    document_create_tag(doc, "head");
    document_create_tag(doc, "title");
    document_add_attr(doc, "id", "my_title");
    document_add_attr(doc, "value", "My Title");
    document_create_tag(doc, "body");
    document_create_tag(doc, "h1");
    document_add_attr(doc, "align", "center");
    document_add_attr(doc, "font-size", "20px");
    document_add_attr(doc, "value", "Hello, world!");
    const char *html = document_to_string(doc);
    printf("%s\n", html);
    document_free(doc);
    free((void *)html);
    return 0;
}