#include "library.h"

#include <stdio.h>
#include <stddef.h>
#include <string.h>

json_value *create_json_string(char * string_contents, size_t length) {
    json_string* s = malloc(sizeof(json_string));
    (*s).length = length;
    strcpy((*s).str, string_contents);
    json_value* jsv = malloc(sizeof (json_value));
    json_value_content* jsvc = malloc(sizeof (json_value_content));
    jsvc->string = s;
    (*jsv).value = jsvc;
    jsv->type = String;
    return jsv;
}

void free_json_string(json_string* jsonString) {
    free(jsonString->str);
    free(jsonString);
}



