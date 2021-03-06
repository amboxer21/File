# File Gem
A ruby Gem written in the C programming language using Ruby's C programming API. I am writing this gem just for fun and learning purposes.

[**METHODS**]
* size
* mtime
* ctime
* atime
* empty

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
compiling file.c
linking shared-object file.so
anthony@gentoo ~ $
```

> Step 3

**IMPORTANT!!** Running `sudo make install` will install this gem in your gem path. The name of this gem could cause naming conflicts. Using this gem locally is a much safer option!

```
anthony@gentoo ~ $ sudo make install
Password: 
/usr/bin/install -c -m 0755 file.so /usr/lib64/ruby/site_ruby/2.5.0/x86_64-linux
anthony@gentoo ~ $
```

[**USAGE**]

**Regular require**

```
anthony@gentoo ~ $ sudo irb
irb(main):001:0> require 'file'
=> true
irb(main):002:0> File.size('/var/log/messages')
=> 595805
irb(main):003:0> File.c_time('/var/log/messages')
=> "Mon Nov  2 17:31:49 2020\n"
irb(main):004:0> File.m_time('/var/log/messages')
=> "Mon Nov  2 17:31:49 2020\n"
irb(main):005:0> File.a_time('/var/log/messages')
=> "Sat Oct 17 16:21:35 2020\n"
irb(main):006:0> File.empty('/var/log/messages')
=> false
irb(main):007:0> exit
anthony@gentoo ~ $
```

**Local require**

> Assuming the shared object(.so file) is in the same directory that you're running your script from or using irb from. 
```
anthony@gentoo ~ $ sudo irb
irb(main):001:0> require('./file')
=> true
irb(main):002:0> File.size('/var/log/messages')
=> 595805
irb(main):003:0> File.c_time('/var/log/messages')
=> "Mon Nov  2 17:31:49 2020\n"
irb(main):004:0> File.m_time('/var/log/messages')
=> "Mon Nov  2 17:31:49 2020\n"
irb(main):005:0> File.a_time('/var/log/messages')
=> "Sat Oct 17 16:21:35 2020\n"
irb(main):006:0> File.empty('/var/log/messages')
=> false
irb(main):007:0> exit
anthony@gentoo ~ $
```

[**BENCHMARKS**]

**My file gem**

```
anthony@gentoo ~ $ time sudo ruby -e "require 'file'; puts File.size('/var/log/messages')"
612369

real	0m0.066s
user	0m0.058s
sys	0m0.008s
anthony@gentoo ~ $ time sudo ./filesize 
612696

real	0m0.006s
user	0m0.003s
sys	0m0.003s
anthony@gentoo ~ $ time ls -al /var/log/messages | awk '{print $5}'
612788

real	0m0.003s
user	0m0.002s
sys	0m0.003s
anthony@gentoo ~ $ 
``` 

**Ruby's built in library**

```
anthony@localhost ~ $ time sudo ruby -e "puts File.read('/var/log/messages').size;"
611951

real	0m0.069s
user	0m0.062s
sys	0m0.007s
anthony@localhost ~ $
```
