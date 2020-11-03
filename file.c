#include "ruby.h"
#include <stdio.h> 
#include <time.h>
#include <sys/stat.h>

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

static VALUE empty(VALUE self, VALUE filename) {

    FILE* fp = fopen(StringValueCStr(filename), "r"); 

    if(fp == NULL) {
        rb_raise(rb_eRuntimeError, "Error: unable to parse file \"%s\"\n", StringValueCStr(filename));
        return Qnil;
    }

    fseek(fp, 0L, SEEK_END); 

    VALUE res = INT2NUM(ftell(fp));

    fclose(fp); 

    if(res == 0)
        return Qtrue;
    return Qfalse;
}

static VALUE m_time(VALUE self, VALUE filename) {

    struct stat fstat;

    stat(StringValueCStr(filename), &fstat);
    return rb_str_new2(ctime(&fstat.st_mtime));
}

static VALUE c_time(VALUE self, VALUE filename) {

    struct stat fstat;

    stat(StringValueCStr(filename), &fstat);
    return rb_str_new2(ctime(&fstat.st_ctime));
}

static VALUE a_time(VALUE self, VALUE filename) {

    struct stat fstat;

    stat(StringValueCStr(filename), &fstat);
    return rb_str_new2(ctime(&fstat.st_atime));
}

void Init_file(void) {
  VALUE rb_class = rb_define_class("File", rb_cObject);
  rb_define_singleton_method(rb_class, "size", size, 1);
  rb_define_singleton_method(rb_class, "empty", empty, 1);
  rb_define_singleton_method(rb_class, "a_time", a_time, 1);
  rb_define_singleton_method(rb_class, "c_time", c_time, 1);
  rb_define_singleton_method(rb_class, "m_time", m_time, 1);
}
