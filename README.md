# fileopts Gem
A ruby Gem written in the C programming language using Ruby's C programming API. A fast way to find out the size of a file.

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

```
anthony@gentoo ~ $ time sudo ruby -e "require 'fileopts'; puts FileOpts.size('/var/log/messages')"
598604
    
real	0m0.039s
user	0m0.035s
sys	0m0.004s
anthony@gentoo ~ $ time sudo ./filesize 
599258

real	0m0.005s
user	0m0.003s
sys	0m0.002s
anthony@gentoo ~ $ time ls -al /var/log/messages | awk '{print $5}'
599350

real	0m0.002s
user	0m0.003s
sys	0m0.000s
anthony@gentoo ~ $ 
```

vs 

**Ruby's built in library**

```
anthony@gentoo ~ $ time sudo ruby -e "puts File.new('/var/log/messages');"
#<File:0x000055a2a7fb3778>

real	0m0.041s
user	0m0.035s
sys	0m0.006s
anthony@gentoo ~ $
```
