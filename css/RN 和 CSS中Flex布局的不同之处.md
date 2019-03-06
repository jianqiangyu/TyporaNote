# RN 和 CSS中布局的不同之处

## flex

在RN中`flex`的表现和`css`有些区别。flex在RN中只能为整数。

当`flex`为一个正整数时，组件尺寸会具有弹性，并根据具体的flex值来按比例分配。比如两个组件在同一父容器中，一个`flex`为2，另一个`flex`为1，则两者的尺寸比为`2：1`

当`flex`为`0`，组件尺寸有`width`和`height`决定，此时不再具有弹性。 `0`等于`css`中的`none`。

当`flex`为-1时，组件尺寸一般还是由`width`和`height`决定，但是当空间不够时，组件尺寸会收缩到`minWidth`和`minHeight`所设定的值。

`flexGrow`、`flexShrink`、`flexBasis`和在`css`上表现一致。



## position

`position`在`RN`中跟在`css`中很想，不过`RN`中所有元素的默认值为`relative`，`absolute`定位会用父元素来做参照物。

子元素想基于父元素做定位，需要将子元素的`position`属性设置为`absolute`。

子元素不想基于父元素做定位，那就不要用样式表，用组件树来完成。





