# filesize Gem
A ruby Gem written in the C programming language using Ruby's C programming API. A fast way to find out the size of a file.


[**BUILD**]

> Step 1
```
anthony@localhost ~/Documents/Ruby/Fail2BanExtended/extensions $ ruby extconf.rb 
creating Makefile
anthony@localhost ~/Documents/Ruby/Fail2BanExtended/extensions $
```

> Step 2
```
anthony@localhost ~/Documents/Ruby/Fail2BanExtended/extensions $ make
compiling log_file_size.c
linking shared-object logfilesize.so
anthony@localhost ~/Documents/Ruby/Fail2BanExtended/extensions $
```

> Step 3
```
anthony@localhost ~/Documents/Ruby/Fail2BanExtended/extensions $ sudo make install
Password: 
/usr/bin/install -c -m 0755 logfilesize.so /usr/lib64/ruby/site_ruby/2.5.0/x86_64-linux
anthony@localhost ~/Documents/Ruby/Fail2BanExtended/extensions $
```

[**USAGE**]

```
anthony@localhost ~/Documents/Ruby/Fail2BanExtended/extensions $ sudo /usr/bin/irb
irb(main):001:0> require 'logfilesize'
=> true
irb(main):002:0> include LogFileSize
=> Object
irb(main):003:0> log_file_size('/var/log/messages')
=> 567895
irb(main):004:0>
```

[**BENCHMARKS**]

```
anthony@localhost ~ $ time sudo ruby -e "require 'logfilesize'; include LogFileSize; puts log_file_size('/var/log/messages')"
556660
    
real	0m0.064s
user	0m0.056s
sys	0m0.008s
anthony@localhost ~ $ time sudo ./filesize 
557018

real	0m0.006s
user	0m0.002s
sys	0m0.004s
anthony@localhost ~ $ time ls -al /var/log/messages | awk '{print $5}'
557110
    
real	0m0.003s
user	0m0.000s
sys	0m0.004s
anthony@localhost ~ $ 
```
