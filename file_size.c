#include "ruby.h"
#include <stdio.h> 

static VALUE size(VALUE self, VALUE filename) {

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

void Init_filesize(void) {
  VALUE rb_class = rb_define_class("FileSize", rb_cObject);
  rb_define_singleton_method(rb_class, "size", size, 1);
}
