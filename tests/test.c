//
// Created by mk8bk on 10/06/23.
//

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "../library.h"
#include "../library.c"



void test_create_json_string(){
    char* s = "This is a string   ";
    json_string* js = create_json_string(s,strlen(s));
    assert((*js).length == strlen(s));
    assert(strcmp(s,(*js).str)==0);
}




int main(){
    test_create_json_string();

    return EXIT_SUCCESS;
}