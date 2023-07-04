//
// Created by mk8bk on 10/06/23.
//

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "../library.h"
#include "../library.c"


void test_json_string_type(){
    json_string jsonstr = {
            "Bruh",
            strlen("Bruh")
    };
    puts(jsonstr.str);
    printf("%zu\n",jsonstr.length);
}

void test_json_number_type(){

}

void test_json_object_type(){

}

void test_json_array_type(){

}

void test_json_value_type(){

}

void test_json_types(){
    test_json_number_type();
    test_json_string_type();
    test_json_array_type();
    test_json_object_type();
    test_json_value_type();
}

int main(){
    test_json_types();
    return EXIT_SUCCESS;
}