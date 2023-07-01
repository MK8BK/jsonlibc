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
    number,
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


json_value* create_json_string(char*, size_t);
void free_json_string(json_string *);

json_object_entry * create_json_object_entry(json_string*, json_value*);
void free_json_object_entry();

json_value* create_json_object(json_value*, size_t);
json_value* create_json_array(json_value*, size_t);

/**
 * Parse a char[] starting at the offset and return a json_string.
 * Increment the offset after completion.
 * Expects a valid json number.
 * >>>
 * >>> 'This is not a valid json string'.
 * >>> 'This is not a valid json string".
 * >>> This is not a valid json string.
 * @return a json_number structure.
 */
json_number* parse_json_number(char*, size_t, int*);

/**
 * Parse a char[] starting at the offset and return a json_string.
 * Increment the offset after completion.
 * Expects a valid json string, surronded by double quotes
 * >>> "This is a valid json string".
 * >>> 'This is not a valid json string'.
 * >>> 'This is not a valid json string".
 * >>> This is not a valid json string.
 * @return a json_string structure.
 */
json_string* parse_json_string(char*, size_t, int*);

/**
 * Parse a char[] starting at the offset and return a json_object_entry.
 * Increment the offset after completion.
 * Expects a valid json entry.
 * >>> "key":{}.
 * >>> "key":[1,2,3]
 * >>> "key":[{"1":2},{"3":45, "wut":[5,6]}]
 * @return a json_object_entry structure.
 */
json_object_entry* parse_json_object_entry(char*, size_t, int*);

/**
 * Parse a char[] starting at the offset and return a json_object.
 * Increment the offset after completion.
 * Expects a valid json object.
 * >>> {}
 * >>> {"key":<value>, "other key":<other value>}
 * @return a json_object structure.
 */
json_object* parse_json_object(char*, size_t, int*);

/**
 * Parse a char[] starting at the offset and return a json_array.
 * Increment the offset after completion.
 * Expects a valid json array.
 * >>> []
 * >>> [1,2,3]
 * @return a json_array structure.
 */
json_array* parse_json_array(char*, size_t, int*);

/**
 * Parse string and return array of json_value(s) contained.
 * Set values count afterwards.
 * @return pointer to first json_value structure.
 */
json_value* parse_json(char*, size_t, int*);


#endif //CLIBJSON_LIBRARY_H