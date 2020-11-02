# filesize Gem
A ruby Gem written in the C programming language using Ruby's C programming API. A fast way to find out the size of a file.


[**BUILD**]

> Step 1
```
anthony@gentoo ~ $ ruby extconf.rb 
creating Makefile
anthony@gentoo ~ $
```

> Step 2
```
anthony@gentoo ~ $ make
compiling file_size.c
linking shared-object filesize.so
anthony@gentoo ~ $
```

> Step 3
```
anthony@gentoo ~ $ sudo make install
Password: 
/usr/bin/install -c -m 0755 filesize.so /usr/lib64/ruby/site_ruby/2.5.0/x86_64-linux
anthony@gentoo ~ $
```

[**USAGE**]

```
anthony@gentoo ~ $ sudo irb
irb(main):001:0> require 'filesize'
=> true
irb(main):002:0> FileSize.size('/var/log/messages')
=> 578797
irb(main):003:0> exit
anthony@gentoo ~ $
```

[**BENCHMARKS**]

```
anthony@gentoo ~ $ time sudo ruby -e "require 'filesize'; puts FileSize.size('/var/log/messages')"
556660
    
real	0m0.064s
user	0m0.056s
sys	0m0.008s
anthony@gentoo ~ $ time sudo ./filesize 
557018

real	0m0.006s
user	0m0.002s
sys	0m0.004s
anthony@gentoo ~ $ time ls -al /var/log/messages | awk '{print $5}'
557110
    
real	0m0.003s
user	0m0.000s
sys	0m0.004s
anthony@gentoo ~ $ 
```
