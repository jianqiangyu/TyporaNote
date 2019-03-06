1. mach-o type  我们自己创建的framework一般是静态库
2. Dead Code Stripping设置为NO， 为yes用来无用代码剥离（未引用的代码），为了避免剥离出错
3. Link With Standard Libraries关闭，我想可能是为了避免重复链接
4. Build Active Architecture Only 