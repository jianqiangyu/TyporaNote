# Podspec 

## 规范

规范描述了Pod库的一个版本。 它包括有关应从何处获取源，要使用的文件，要应用的构建设置以及其他常规元数据（如名称，版本和说明）的详细信息。

pod spec create命令可以生成存根规范文件。

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
spec.screenshots = [ 'http://dl.dropbox.com/u/378729/MBProgressHUD/1.png',
                     'http://dl.dropbox.com/u/378729/MBProgressHUD/2.png' ]
```

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
规范应指明支持库的平台和对应的部署目标。

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

受支持平台的最低部署目标。

与platform属性相反，deployment_target属性允许指定支持此pod的多个平台 - 为每个平台指定不同的部署目标。

```ruby
spec.ios.deployment_target = '6.0'
```

```ruby
spec.osx.deployment_target = '10.8'
```