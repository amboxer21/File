#include "ruby.h"
#include <stdio.h> 

VALUE LogFileSize = Qnil;

void Init_logfilesize();

VALUE method_log_file_size(VALUE self, VALUE filename);

void Init_logfilesize(void) {
	  LogFileSize = rb_define_module("LogFileSize");
	  rb_define_method(LogFileSize, "log_file_size", method_log_file_size, 1);
}

VALUE method_log_file_size(VALUE self, VALUE filename) {

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
