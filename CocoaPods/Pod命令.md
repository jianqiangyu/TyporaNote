# pod命令

## 安装

此组中列出的命令支持安装和集成Podfile中指定的依赖项。

在用户项目中集成CocoaPods的基本工作流程。

```shell
$ touch Podfile
$ vim Podfile
$ pod install
$ open *.xcworkspace
$ vim podfile
$ pod install
$ pod outdated
$ pod update
```



### 公共选项

`--silent  ` ： 什么也不展示

`--verbose` ： 展示更多debug信息

`--no-ansi`  ： 展示没有ANSI代码的输出 （不清楚）

`--help` ： 针对特定命令展示帮助信息



### pod init

```shell
pod init XCODEPROJ // XCODEPROJ 可选
```

`pod init`用来创建`Podfile`，如果在当前文件夹下没有`Podfile`，会自动创建`Podfile`。



### pod install

```
pod install 
```

下载`podfile`中定义的依赖，并且在./Pods中创建一个pods库项目。

1. 每次运行`pod install`命令,并下载并安装新`pod`时,它会在`Podfile.lock`文件中为每个pod写入已安装的版本。`Podfile.lock`跟踪每个`pod`的已安装版本并锁定这些版本。
2. 运行`pod`安装时，它仅解析`Podfile.lock`中尚未列出的`pod`的依赖项。
       1. 对于`Podfile.lock`中列出的`pod`，它会下载`Podfile.lock`中列出的显式版本，而不尝试检查是否有更新的版本
       2. 对于尚未在`Podfile.lock`中列出的`pod`，它会搜索与`Podfile`中描述的版本匹配的版本（例如`pod'MyPod'，'〜> 1.2'`）

> 选项：
>
> `--repo-update`  ：  在`install`前强制执行`pod repo update` 
>
> `--deployment`  
>
> `--project-directory=/project/dir/` ： 项目根目录的路径。



### pod update

```
pod update [POD_NAMES ...]
```

`pod update`用来更新`pod`库

1.  当您运行`pod update podName`时，CocoaPods将尝试查找名为`podName` 的更新版本，而不考虑`Podfile.lock`中列出的版本。它会将pod更新为Podfile中版本限制下的最新版本.与`pod install` 相反，`pod install`不会尝试更新已安装的`pod`版本。
2.  如果您运行没有`podName`的`pod update`，CocoaPods会将`Podfile`中列出的每个`pod`更新为最新版本。

> 选项：
>
> `--no-repo-update`  ： 在更新版本时跳过运行`pod repo update`
>
> `--exclude-pods=podName`  ： 在`update`时，指定的不更新的pod库，多个pods之间需要指逗号分隔
>
> `--project-directory=/project/dir/`：项目根目录的路径
>
> `--sources=https://github.com/artsy/Specs,master`：多个源之间要用逗号隔开，



### pod outdated

```
pod outdated 
```

显示`Podfile.lock`中过时的pod库，但仅显示来自spec repos的那些，而不是来自本地/外部 源的。

1.   当您运行`pod outdated`时，CocoaPods将列出所有具有比`Podfile.lock`（当前为每个pod安装的版本）更新版本的pod。这意味着如果您在这些pod上运行`pod update PODNAME`，它们将会更新 , 只要新版本仍然匹配Podfile中设置的`pod'MyPod'，'〜> x.y'`等限制。

> 选项：
>
> `--no-repo-update`  ： 在更新版本时跳过运行`pod repo update`
>
> `--project-directory=/project/dir/`：项目根目录的路径



###pod deintegrate

```
pod deintegrate [XCODE_PROJECT]
```

从`Xcode`项目中删除所有CocoaPods的痕迹， 会删除./Pods文件夹，不会删除`Podfile`。如果未指定`xcodeproj`，则将在当前目录中搜索Xcode项目。

> 选项：
>
> --project-directory=/project/dir/`：项目根目录的路径



## 环境

###pod env

显示pod环境



## 浏览

###pod list

```
pod list 
```

展示所有可用的pod库

>  选项： 
>
> `--update`：在`list`前运行``pod repo update``
>
> `--stats`：展示额外信息（例如github的`watchers`和`forks`）



### pod search

```
pod search QUERY
```

搜索名称，摘要，描述或作者与QUERY匹配的pod库，忽略大小写。 如果指定了--simple选项，则只会搜索pod的名称。

> 选项：
>
> `--regex`：将QUERY解释为正则表达式。
>
> `--simple`：仅按名称搜索。
>
> `--stats`：显示其他统计数据（如GitHub的forks和watcher）。
>
> `--web`：在cocoapods.org搜索。
>
> `--ios`：将搜索限制为iOS上支持的Pod。
>
> `--osx`：将搜索限制为macOS上支持的Pod。
>
> `--watchos`：将搜索限制为watchOS支持的Pod。
>
> `--tvos`：将搜索限制为在tvOS上支持的Pod。
>
> `--no-pager`：不把搜索结果传到新一页



### pod try

> 选项：
>
> `--podspec_name=[name]`：在git仓库中podspec文件的名字
>
> `--no-repo-update`：安装前跳过`pod repo update`



## Specifications

### pod spec create

```
pod spec create [NAME|https://github.com/USER/REPO]
```

创建一个podspec在当前文件夹，名字叫做`NAME.podspec`。如果指定了GitHub url,则预先填充一些内容。