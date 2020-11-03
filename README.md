# fileopts Gem
A ruby Gem written in the C programming language using Ruby's C programming API. This is a version of the File class that uses singleton methods instead of instance methods.

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
compiling fileopts.c
linking shared-object fileopts.so
anthony@gentoo ~ $
```

> Step 3
```
anthony@gentoo ~ $ sudo make install
Password: 
/usr/bin/install -c -m 0755 fileopts.so /usr/lib64/ruby/site_ruby/2.5.0/x86_64-linux
anthony@gentoo ~ $
```

[**USAGE**]

```
anthony@gentoo ~ $ sudo irb
irb(main):001:0> require 'fileopts'
=> true
irb(main):002:0> FileOpts.size('/var/log/messages')
=> 595805
irb(main):003:0> FileOpts.c_time('/var/log/messages')
=> "Mon Nov  2 17:31:49 2020\n"
irb(main):004:0> FileOpts.m_time('/var/log/messages')
=> "Mon Nov  2 17:31:49 2020\n"
irb(main):005:0> FileOpts.a_time('/var/log/messages')
=> "Sat Oct 17 16:21:35 2020\n"
irb(main):006:0> FileOpts.empty('/var/log/messages')
=> false
irb(main):007:0> exit
anthony@gentoo ~ $
```

[**BENCHMARKS**]

**My fileopts gem**

```
anthony@gentoo ~ $ time sudo ruby -e "require 'fileopts'; puts FileOpts.size('/var/log/messages')"
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
