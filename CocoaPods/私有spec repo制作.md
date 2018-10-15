# 私有库制作

CocoaPods不仅是一个很好的工具，不仅可以为项目添加开源代码，还可以跨项目共享私有组件。您可以使用私人Spec Repo来达到此目的。

为项目设置私有pod有几个步骤；创建一个私有仓库，让CocoaPods知道在哪里找到它并将podspec添加到仓库中。

## 创建私有Specs仓库

1. 创建私有的远程仓库，并且保证需要使用这个repo的人员都有权限访问到它，

2. 终端执行如下命令，添加私有Specs仓库

   ```shell
   pod repo add REPO_NAME SOURCE_URL
   ```

3. 检查是否添加成功

   ```
   cd ~/.cocoapods/repos/REPO_NAME
   pod repo lint .
   ```

4. 将podspec推到私有的specs仓库中

   ```shell
   pod repo push REPO_NAME SPEC_NAME.podspec
   ```

   如果你的podspec是有效的，那么在将被加到私有specs仓库中，结构类似

   ```
   ├── Specs
       └── [SPEC_NAME]
           └── [VERSION]
               └── [SPEC_NAME].podspec
   ```

5. 在podfile中使用

   ```ruby
   source 'URL_TO_REPOSITORY'
   ```



## pod repo 命令

```
pod repo add   // 添加specs仓库

pod repo lint  // 检查specs仓库内容是否有效

pod repo push // 往specs仓库添加podspec文件

pod repo list // specs仓库列表

pod repo remove // 移除specs仓库

pod repo update  // 更新specs仓库
```

