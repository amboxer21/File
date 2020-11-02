#include "ruby.h"
#include <stdio.h> 

VALUE FileSize = Qnil;

void Init_filesize();

VALUE method_file_size(VALUE self, VALUE filename);

void Init_filesize(void) {
	  FileSize = rb_define_module("FileSize");
	  rb_define_method(FileSize, "file_size", method_file_size, 1);
}

VALUE method_file_size(VALUE self, VALUE filename) {

    FILE* fp = fopen(StringValueCStr(filename), "r"); 

    if(fp == NULL) {
        rb_raise(rb_eRuntimeError, "Error: unable to parse file \"%s\"\n", StringValueCStr(filename));
        return Qnil;
    }

    fseek(fp, 0L, SEEK_END); 

    VALUE res = INT2NUM(ftell(fp));

    fclose(fp); 

    return res; 
}
