#RN学习笔记

1. 如何设置默认props? 

```js
static defaultProps = {
    leftTitle: "作品",
    rightTitle: "查看全部"
}
```

2. 如何设置props格式检查? 

   ```js
   import PropTypes from 'prop-types'
   static propTypes = {
       
       leftTitle: PropTypes.string.isRequired ,// isRequired 代表必传
       
       rightTitle: PropTypes.string,
       
       showRight: PropTypes.bool,
   
       showRightArrow: PropTypes.bool
   }
   
   ```

3. 如何根据条件来决定是否展示元素

   ```js
   {this.props.showRightArrow && <Image source={require('./icon_forum_arrow.png')} />}
   ```

4. 如何拿到屏幕尺寸
   利用`RN`中的`Dimensions`API

5. 





