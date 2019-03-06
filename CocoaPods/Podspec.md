# Podspec 

## 规范

`podsepc`文件描述了Pod库的一个版本。 它包括有关应从何处获取资源，要使用的文件，要应用的构建设置以及其他常规元数据（如名称，版本和说明）的详细信息。

`pod spec create`命令可以生成`Podspec`文件。

规范DSL提供了极大的灵活性和动态性。 此外，DSL采用约定优于配置，因此它可以非常简单：

```ruby
Pod::Spec.new do |spec|
  spec.name         = 'Reachability'
  spec.version      = '3.1.0'
  spec.license      = { :type => 'BSD' }
  spec.homepage     = 'https://github.com/tonymillion/Reachability'
  spec.authors      = { 'Tony Million' => 'tonymillion@gmail.com' }
  spec.summary      = 'ARC and GCD Compatible Reachability Class for iOS and OS X.'
  spec.source       = { :git => 'https://github.com/tonymillion/Reachability.git', :tag => 'v3.1.0' }
  spec.source_files = 'Reachability.{h,m}'
  spec.framework    = 'SystemConfiguration'
end
```

或者它可以非常详细：

```ruby
Pod::Spec.new do |spec|
  spec.name          = 'Reachability'
  spec.version       = '3.1.0'
  spec.license       = { :type => 'BSD' }
  spec.homepage      = 'https://github.com/tonymillion/Reachability'
  spec.authors       = { 'Tony Million' => 'tonymillion@gmail.com' }
  spec.summary       = 'ARC and GCD Compatible Reachability Class for iOS and OS X.'
  spec.source        = { :git => 'https://github.com/tonymillion/Reachability.git', :tag => 'v3.1.0' }
  spec.module_name   = 'Rich'
  spec.swift_version = '4.0'

  spec.ios.deployment_target  = '9.0'
  spec.osx.deployment_target  = '10.10'

  spec.source_files       = 'Reachability/common/*.swift'
  spec.ios.source_files   = 'Reachability/ios/*.swift', 'Reachability/extensions/*.swift'
  spec.osx.source_files   = 'Reachability/osx/*.swift'

  spec.framework      = 'SystemConfiguration'
  spec.ios.framework  = 'UIKit'
  spec.osx.framework  = 'AppKit'

  spec.dependency 'SomeOtherPod'
end
```

## 根规范

“根”规范存储有关库的特定版本的信息。

该组中的属性只能写入“根”规范，而不能写入“子规范”。

该组中列出的属性是podspec唯一需要的属性。

提供其他组的属性以优化podspec并遵循约定优于配置方法。 根规范可以直接通过“子规范”来描述这些属性。

### 名字（R）

pod的名称

```ruby
spec.name = 'AFNetworking'
```

### 版本（R）

pod的版本

```
spec.version = '0.0.1'
```

###Swift版本

规范支持的Swift版本。

```ruby
spec.swift_version = '3.2'
```

###CocoaPods版本
规范支持的CocoaPods版本。

```ruby
spec.cocoapods_version = '>= 0.36'
```

### 作者（R）

三方库的维护者的名称和电子邮件地址，而不是Podspec的维护者。

```ruby
spec.author = 'Darth Vader'		
```

```ruby
spec.authors = 'Darth Vader', 'Wookiee'
```

```ruby
spec.authors = { 'Darth Vader' => 'darthvader@darkside.com',
                 'Wookiee'     => 'wookiee@aggrrttaaggrrt.com' }
```

###*社交媒体URL

```ruby
spec.social_media_url = 'https://twitter.com/cocoapods'
```

```ruby
spec.social_media_url = 'https://groups.google.com/forum/#!forum/cocoapods'
```

###许可协议（R）

Pod的许可协议。



### 来源（R）

pod库的位置

> 指定git地址，并指定tag。这种方式是最常见的

```
spec.source = { :git => 'https://github.com/AFNetworking/AFNetworking.git',
                :tag => spec.version.to_s }
```

> 使用带有前缀'v'和子模块的标签

```
spec.source = { :git => 'https://github.com/typhoon-framework/Typhoon.git',
                :tag => "v#{spec.version}", :submodules => true }
```

> 使用svn地址，并指定tag

```
spec.source = { :svn => 'http://svn.code.sf.net/p/polyclipping/code', :tag => '4.8.8' }
```

> 使用(分布式版本控制工具 Mercurial)，并且指定version

```
spec.source = { :hg => 'https://bitbucket.org/dcutting/hyperbek', :revision => "#{s.version}" }
```

> 使用HTTP下载代码的压缩文件。 它支持zip，tgz，bz2，txz和tar。

```
spec.source = { :http => 'http://dev.wechatapp.com/download/sdk/WeChat_SDK_iOS_en.zip' }
```

> 使用HTTP使用哈希下载文件以验证下载。 它支持sha1和sha256。

```
spec.source = { :http => 'http://dev.wechatapp.com/download/sdk/WeChat_SDK_iOS_en.zip',
                :sha1 => '7e21857fe11a511f472cfd7cfa2d979bd7ab7d96' }
```

**Supported Keys:**

`:git` => `:tag`, `:branch`, `:commit`, `:submodules`

`:svn` => `:folder`, `:tag`, `:revision`

`:hg` => `:revision`

`:http` => `:flatten`, `:type`, `:sha256`, `:sha1`

### 主页（R）

Pod的主页的URL。

```ruby
spec.homepage = 'http://www.example.com'
```

###摘要（R）
Pod的简短（最多140个字符）描述。

```ruby
spec.summary ='计算生命的意义。'
```

### 描述

Pod的描述比摘要更详细。

```ruby
spec.description = <<-DESC
                     Computes the meaning of life.
                     Features:
                     1. Is self aware
                     ...
                     42. Likes candies.
                   DESC
```

###截图
显示Pod的图像的URL列表。 适用于面向UI的库。 CocoaPods建议使用gif格式。

```ruby
spec.screenshot  = 'http://dl.dropbox.com/u/378729/MBProgressHUD/1.png'
```

```ruby
spec.screenshots = [ 'http://dl.dropbox.com/u/378729/MBProgressHUD/1.png',                  'http://dl.dropbox.com/u/378729/MBProgressHUD/2.png' ]
```



###documentation_url
Pod文档的地址。 将其留空将默认为CocoaDocs为您的库生成的URL。



### prepare_command

下载Pod后将执行的bash脚本。 此命令可用于创建，删除和修改下载的任何文件，并将在收集规范的其他文件属性的任何路径之前运行。

在清除Pod之前和创建Pods项目之前执行此命令。 工作目录是Pod的根目录。

如果使用`:path`选项安装pod，则不会执行此命令。



###静态框架

表示，如果use_frameworks！ 被指定，则pod应包含静态库框架。

例子：

```ruby
spec.static_framework = true
```

###弃用

库是否已被弃用。

```ruby
spec.deprecated = true
```

###弃用建议
这个Pod已被弃用,而建议使用的新Pod

```
spec.deprecated_in_favor_of = 'NewMoreAwesomePod'
```

##平台
规范应指明支持库的平台以及平台的最低版本。

如果未在子规范中定义，则该组的属性将继承父级的值。

###platform

支持此Pod的平台。 保留此空白表示Pod在所有平台上都受支持。 支持多个平台时，您应该使用下面的deployment_target。

```ruby
spec.platform = :osx, '10.8'
```

```ruby
spec.platform = :ios
```

```ruby
spec.platform = :osx
```

###deployment_target

受支持平台的最低版本。

与platform属性相反，deployment_target属性允许指定支持此pod的多个平台 - 为每个平台指定不同的版本。

```ruby
spec.ios.deployment_target = '6.0'
```

```ruby
spec.osx.deployment_target = '10.8'
```



## 构建设置

在该组中列出了用于构建库的构建环境的配置相关的属性。

如果未在子规范中定义，则该组的属性将继承父级的值。

### dependency

指明对其他Pod或“子规范”需要的依赖。

依赖关系可以指定依赖版本。 建议使用乐观版本指示符〜>，因为它可以很好地控制版本，而不会过于严格。 例如，〜> 1.0.1等于> = 1.0.1与<1.1相结合。 同样，〜> 1.0将匹配1.0,1.0.1,1.1，但不会升级到2.0。

过严限制依赖库的版本的Pod限制了它们与其他Pod的兼容性。

```
spec.dependency 'AFNetworking', '~> 1.0'
```

```
spec.dependency 'RestKit/CoreData', '~> 0.20.0'
```

```
spec.ios.dependency 'MBProgressHUD', '~> 0.5'
```

### requires_arc  （multi-platform）

requires_arc允许您指定哪个source_files使用ARC。 这可以是支持ARC的文件，也可以是true表示所有source_files都使用ARC。

不使用ARC的文件将具有-fno-objc-arc编译器标志。

此属性的默认值为true。

默认：

```
spec.requires_arc = true
```

举例：

```
spec.requires_arc = false
```

```
spec.requires_arc = 'Classes/Arc'
```

```
spec.requires_arc = ['Classes/*ARC.m', 'Classes/ARC.mm']
```

### frameworks （multi-platform）

使用该库，项目target需要链接的系统框架列表。

```
spec.ios.framework = 'CFNetwork'
```

```
spec.frameworks = 'QuartzCore', 'CoreData'
```

### weak_frameworks (multi-platfrom)

使用该库，项目target需要弱链接的框架列表。

```
spec.weak_framework = 'Twitter'
```

```
spec.weak_frameworks = 'Twitter', 'SafariServices'
```

### libraries (multi-platform)

使用该库，项目target需要链接的系统库列表。

```
spec.ios.library = 'xml2'
```

```
spec.libraries = 'xml2', 'z'
```

### prefix_header_contents（multi-platform）

要在该pod库的`pch`文件中中注入的内容。

建议不要使用此属性。

```
spec.prefix_header_contents = '#import <UIKit/UIKit.h>'
```

```
spec.prefix_header_contents = '#import <UIKit/UIKit.h>', '#import <Foundation/Foundation.h>'
```

### prefix_header_file（multi-platform）

### Examples:

```
spec.prefix_header_file = 'iphone/include/prefix.pch'
```

```
spec.prefix_header_file = false
```

### compiler_flags (multi-platform)

应传递给编译器的标志列表。

```
spec.compiler_flags = '-DOS_OBJECT_USE_OBJC=0', '-Wno-format'
```

### pod_target_xcconfig(multi-platform)

要添加到最终私有pod目标xcconfig文件的任何标志。

```
spec.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
```



## 文件模式

`Podspec`文件应该位于存储库的根目录，并且应该相对于存储库的根目录指定文件路径。

文件模式可能包含一下通配符模式：

`*`:匹配任何文件

`c*`:匹配以c开头的所有文件

`*c`:匹配以c结尾的所有文件

`*c*`:将匹配所有包含c的文件（包括开头或结尾）

`**`: 以递归方式查找目录

### source_files （multi-platform）

pod仓库的资源文件。

```
spec.source_files = 'Classes/**/*.{h,m}'
```

```
spec.source_files = 'Classes/**/*.{h,m}', 'More_Classes/**/*.{h,m}'
```

### public_header_files（multi-platform）

应该用作公共头文件的文件模式列表。

这些是将公开给用户的头文件，以及将从中生成文档。 构建库时，这些头将出现在构建目录中。 如果未指定公共标头，那么source_files中的所有标头都将被视为公共标头。

```
spec.public_header_files = 'Headers/Public/*.h'
```

### private_header_files（multi-platform）

应该用于标记私有头文件的文件模式列表。

这些模式与公共头文件（如果未指定公共标头，则为所有标头）进行匹配，以排除那些不应暴露给用户项目且不应用于生成文档的头文件。 构建库时，这些头将出现在构建目录中。

未列为public或private的头文件将被视为私有，但此外根本不会出现在build目录中。

```
spec.private_header_files = 'Headers/Private/*.h'
```

### resource_bundles（multi-platform）

此属性允许定义应为Pod构建的资源包的名称和文件。 它们被指定为键值对，其中键表示包的名称，值是它们应包含的文件模式。

为了将Pod构建为静态库，我们强烈建议库开发人员采用资源包，因为使用resources属性时可能会有名称冲突。

捆绑包的名称至少应包含Pod库的名称，以最大限度地减少名称冲突的可能性。

要为每个平台提供不同的资源，必须使用命名空间的bundle。

```
spec.ios.resource_bundle = { 'MapBox' => 'MapView/Map/Resources/*.png' }
```

```
spec.resource_bundles = {
    'MapBox' => ['MapView/Map/Resources/*.png'],
    'OtherResources' => ['MapView/Map/OtherResources/*.png']
  }
```

### resources （multi-platform）

应复制到目标包中的资源列表。

为了将Pod构建为静态库，我们强烈建议库开发人员采用资源包，因为使用resources属性时可能会有名称冲突。 此外，使用此属性指定的资源将直接复制到客户端目标，因此Xcode不会优化它们。

```
spec.resource = 'Resources/HockeySDK.bundle'
```

```
spec.resources = ['Images/*.png', 'Sounds/*']
```

### vendored_frameworks（multi-platform）

随pod库一起提供的框架的路径。

### Examples:

```
spec.ios.vendored_frameworks = 'Frameworks/MyFramework.framework'
```

```
spec.vendored_frameworks = 'MyFramework.framework', 'TheirFramework.framework'
```

### vendored_libraries（multi-platform）

随pod库一起提供的库的路径。

### Examples:

```
spec.ios.vendored_library = 'Libraries/libProj4.a'
```

```
spec.vendored_libraries = 'libProj4.a', 'libJavaScriptCore.a'
```



### exclude_files(multi-platform)

应从其他文件模式中排除的文件模式列表。

```
spec.ios.exclude_files = 'Classes/osx'
```

```
spec.exclude_files = 'Classes/**/unused.{h,m}'
```

### preserve_paths（multi-platform）

下载后不应删除的任何文件。

默认情况下，CocoaPods会删除所有其他文件模式都不匹配的文件。

```
spec.preserve_path = 'IMPORTANT.txt'
```

```
spec.preserve_paths = 'Frameworks/*.framework'
```

## Subspecs

库可以指定另一个库，另一个库的`Subspecs`，或者自身的`Subspecs`的依赖关系。

### subspec

表示库的子模块的规范。

一方面，pod库自动依赖所有的子模块，除非制定了默认的子模块。

另一方面，子规范继承父规范的值，因为可以在祖先中指定属性的常用值。

虽然听起来有点复杂，但是在实践中子模块一般会按照您的预期行事：

```
pod 'ShareKit'
```

在安装这个库的时候，会把它的子模块同时安装。

```Pod
pod'ShareKit / Twitter'，'2.0'
pod'ShareKit / Pinboard'，'2.0'
```

仅安装子模块的时候，子规范需要源文件,资源文件，依赖项，以及根据根规范定义的其他属性。CocoaPods可以处理由重复属性引起的任何问题。

举例：

不同子模块指定不能的源文件。

```
subspec 'Twitter' do |sp|
  sp.source_files = 'Classes/Twitter'
end

subspec 'Pinboard' do |sp|
  sp.source_files = 'Classes/Pinboard'
end
```

子模块依赖了其他的子模块。

```\
Pod::Spec.new do |s|
  s.name = 'RestKit'

  s.subspec 'Core' do |cs|
    cs.dependency 'RestKit/ObjectMapping'
    cs.dependency 'RestKit/Network'
    cs.dependency 'RestKit/CoreData'
  end

  s.subspec 'ObjectMapping' do |os|
  end
end
```

嵌套的子模块

```
Pod::Spec.new do |s|
  s.name = 'Root'
  s.subspec 'Level_1' do |sp|
    sp.subspec 'Level_2' do |ssp|
    end
  end
end
```

### default_subspecs

应该用作默认依赖项的一组子模块名称。如果未指定，则规范要求起所有子模块都是依赖项。

默认情况下，Pod应该提供完整的库，用户自己可控制需要的子模块。因为，很少需要这个属性。

```
spec.default_subspec = 'Core'
```

```
spec.default_subspecs = 'Core', 'UI'
```

## Multi-Platform support

规范可以存储仅特定于一个平台的值。

```
spec.resources = 'Resources/**/*.png'
spec.ios.resources = 'Resources_ios/**/*.png'
```