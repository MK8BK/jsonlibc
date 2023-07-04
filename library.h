#ifndef CLIBJSON_LIBRARY_H
#define CLIBJSON_LIBRARY_H

#include <stdlib.h>
#include <stdbool.h>


/**
 * Json Number type: encoded by a union of int, double and possibly other representations.
 */
typedef union {
    int integer_number;
    double double_number;
} json_number_content;

typedef enum {
    integer_number,
    double_number,
} json_number_type;

typedef struct{
    json_number_type type;
    json_number_content value;
} json_number;


/**
 * String json type: encoded by a char*.
 */
typedef struct {
    char* str;
    size_t length;
} json_string;

/**
 * Generic Json Array: contiguous sequence of pointers to json values.
 */
typedef struct {
    size_t size;
    struct json_value *values;
} json_array;

/**
 * Generic Json Object Entry: encoded by a key (json_string) and pointer to value.
 */
typedef struct {
    json_string *string;
    struct json_value *value;
} json_object_entry;

/**
 * Generic json object: contiguous sequence of pointers to json_object_entry.
 */
typedef struct {
    size_t size;
    json_object_entry *entries;
} json_object;

/**
 * Generic json value content: a union of all possible json structures.
 */
typedef union {
    void* b;
    bool boolean;
    json_number *number;
    json_string *string;
    json_array *array;
    json_object *object;
} json_value_content;

/**
 * json_value_type: an enumeration of the various encodings of json values.
 */
typedef enum {
    Null,
    Boolean,
    Number,
    String,
    Array,
    Object
} json_value_type;

/**
 * generic json value: has a type and contents.
 */
typedef struct {
    json_value_type type;
    json_value_content *value;
} json_value;



#endif //CLIBJSON_LIBRARY_H