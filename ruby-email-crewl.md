##Ruby！ E-mail小爬虫

Ruby**据说**是一个比Python还要简洁还要快速的编程语言 ：）

好吧，这里并不是要挑起编程语言之间的战争，每个语言都有自己适应的场景，作为程序员应该知道在什么样的应用场景之下，用哪种的语言来实现业务逻辑，才是最重要的。

这次，我们使用Ruby来获取网页上的e-mail地址。

不知道各位有没有在成堆的垃圾邮件中，寻找某宝密码重置的邮件，简直是一场杯具。。。。我们总是小心翼翼的保护着我们的邮箱，但还是被别有用心的人知道；e-mail爬虫就是这些人的工具之一，它可以在某个网页上过滤出一个个的e-mail，然后发送垃圾邮件。

[“加密”你的email地址，防止爬虫收集](http://m.poorren.com/ser-email-address/)

当然，我们抱着学习的心态，来了解它的基本结构，揭开它神秘的面纱。

代码下载：
```
git clone https://github.com/shiyanlou/email_spider.git
```

##一、准备工作

实验楼已经提供了Ruby运行环境，但是，还是需要我们安装一些插件：

#####将gem下载源换为国内源
**请确保只有 ruby.taobao.org**
```
$ gem sources --remove http://rubygems.org/
$ gem sources -a https://ruby.taobao.org/
$ gem sources -l

*** CURRENT SOURCES ***

https://ruby.taobao.org
```

#####安装Ruby爬虫库 anemone
```
$ sudo apt-get update
$ sudo apt-get install ruby1.9.1-dev
$ sudo apt-get install libsqlite3-dev
$ sudo gem install anemone
```
[查看对应的数据库支持](http://datamapper.org/getting-started.html)

#####Ruby数据库支持
```
sudo gem install data_mapper
sudo gem install dm-sqlite-adapter
```

##二、数据库设计
我们使用sqlite3来放置我们扒下来的数据：

**Site**：存储爬行过的网站
**Page**：存储爬行过的存在email地址的**页面的URL**
**Address**：email地址

我们只讲解其中一个表的model，其他更深入的请看：

[data_mapper property详解](http://datamapper.org/docs/properties.html)

源文件**data.rb**：

![ruby-email-1.png](http://anything-about-doc.qiniudn.com/ruby-email-crawl/ruby-email-1.png)

Page模型需要include模块**DataMapper::Resource**，引入相应的方法，其中就包括了property，belongs_to，has n，validates_presence_of，这些我们马上需要用到的方法。

**property**：定义了对象的属性（表的字段类型），Serial是自增ID，并且是主键。

**belongs_to**： 定义了一对多的关系，一个网站可能包含了多个网页URL

**has n**：定义多对多的关系，一个网页上可能包含多个email地址，一个email可能同时存在多个网页上。

**validates_presence_of**：检查 url是否存在。

[data_mapper validates详解](http://datamapper.org/docs/validations.html)
 
##三、爬虫代码

首先，我们需要引入uri 和 anemone包，其次还需要刚才定义的数据库的model
```
require 'uri'
require 'anemone'
require_relative 'data'
```

**data**是对data.rb文件的引用。

#####crawl.rb

![ruby-email-2.png](http://anything-about-doc.qiniudn.com/ruby-email-crawl/ruby-email-2.png)

**ARGV**：获取命令行参数
```
ruby crawl.py http://www.test.test
```
**ARGV**是Ruby的数组，所以我们用循环来处理它，因为我可以输入不只一个URL，如果，我们使用多线程的话，这样就可以同一时间处理多个URL，事半功倍。

然后马上使用URI()来处理传入的URL，结果返回给uri，下一步就把这个结果存入数据库中，**uri.host**网站的域名，和当前时间(这里使用的是内置模块Time)
[URI模块，官方文档，英文](http://www.ruby-doc.org/stdlib-1.9.3/libdoc/uri/rdoc/URI.html)

接下来的事情就很写意了，我们不需要自己去做很多的比如什么广度和深度算法的设计，我们只需要给它一个入口的URL，它会自动的去爬行，根本停不下来啊！

使用模块**Anemone**的方法**crawl**创建一个新的爬虫，参数就传一个我们想爬行的URL就OK了！

**Storage.PStore**用来缓存新扒下来的网页代码，**on_every_page**处理每个页面，正则去匹配email，该页面的所有email会被包装在一个数组里面，然后循环这个数组并将结果存放数据库。

[Anemone爬虫模块](http://www.rubydoc.info/github/chriskite/anemone/Anemone)

if判断将会去查询address表，如果这个数据存在就更新，不存在则创建。

[Datamapper更删查改详解](http://datamapper.org/docs/create_and_destroy.html)

最后，将得到的E-mail地址输出到屏幕，又接着下一次循环，你要是不行等了，直接Ctrl+c吧 ：）