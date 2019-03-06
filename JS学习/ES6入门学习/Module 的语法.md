# Module 的语法

## 概述

js一直没有模块体系，无法将一个大程序拆分成互相依赖的小文件，再用简单的方式凭借起来。在面对大型、复杂项目时形成了巨大的障碍。

ES6在语言标准的层面上，实现了模块功能，而且实现的很简单。

## 严格模式

ES6的模块自动采用严格模式，不管你有没有在模块头部加上`"use strict"`;

## export 命令

模块功能主要由两个命令组成： `export`和`import`。`export`命令用于规定模块的对外接口，`import`命令用于输入其他模块提供的功能。

###输出变量

一个模块就是一个独立的文件。该文件中的所有变量，外部无法获取。如果希望外部能读取模块内的某个变量，就必须使用`export`关键字输出该变量。

方式一： 

```js
// porfile.js 
export var firstName = 'Michael';
export var lastName = 'Jackson';
export var year = 1958;
```

方式二：

```js
// profile.js
var firstName = 'Michael';
var lastName = 'Jackson';
var year = 1958;

export {firstName, lastName, year};
```

上面的代码是`profile.js`文件，用来保存用户信息。ES6将其视为一个模块，里面用`export`命令对外部输出了三个变量。

应该优先用第二种方式，这样可以在脚本尾部，一眼看清输出了哪些变量。

###输出函数或类

`export`除了能输出变量，还能输出函数或类。

```js
export function multiply(x, y) {
    return x * y;
}
```

上面代码对外输出了一个函数`multiply`。

###`as`关键字重命名

通常情况下，`export`输出的变量就是本来的名字，但是可以使用`as`关键字重命名。

```js
fucntion v1 () {
}

fucntion v2 () {
    
}

export {
	v1 as streamV1,
    v2 as streamV2,
    v2 as streamlatestVersion // 可以用不同的名字输出两次
}
```

###写法规范

需要注意的是，export命令规定的是对外的接口，必须与模块内部的变量建立一一对应关系。

```js
export 1; // 报错
var m = 1
export m; // 报错
```

上面的两个都是输出了`1`，`1`是值，不是接口。

```js
export var m = 1; // 写法1

var n = 1;
export {n};  // 写法2

var i = 1；
export {i as j}; // 写法3
```

上面的3种写法都是正确的，其他脚本可以通过这个接口，取到值1，他们实质是，在接口名和模块内部变量之间，建立了一一对应的关系。

同样的，在输出`function`和`class`的输出，也必须遵守这种写法。

```js
// 报错
function f() {

}
export f;

// 正确
export function f() {
    
}

// 正确
function f() {
    
}
export {f};
```

###动态绑定

`export`语句输出的接口，与其对应的值是动态绑定的关系，通过该接口，可以去到模块内部实时的值。

```js
export var foo = 'bar';
setTimeout(() => foo = 'baz', 500);
```

上面代码输出变量`foo`，值为`bar`，500毫秒后变成`baz`

### 书写位置

`export`可以出现在模块的任何位置，只要处于模块顶层就可以了。如果处于块级作用域内，会报错，后边的`import`命令也是如此的。

```js
var m = 1;
function foo() {
	export {m}; // 报错
}
foo()
```

## import命令

使用`export`命令定义了模块的对外接口以后，其他的`js`文件就可以通过`import`命令加载这个模块。

```js
// main.js
import {firstName, lastName, year} from './profile.js';

function setName(element) {
  element.textContent = firstName + ' ' + lastName;
}
```

上面的代码用于加载`podfile.js`模块，并从中输入变量。`import`命令接受一对大括号，里面指定要从其他模块导入的变量名。大括号里的变量名，必须与对应模块用`export`导出的变量名一致。

###`as`关键字重命名

如果想要为输入的变量名重新取一个名字，`import`命令要使用`as`关键字，将输入的变量重命名。

```js
import  {lastName as surname} from './podfile.js';
```

###输入的变量是只读的

使用`import`输入的变量是只读，本质是输入接口，也就是说不允许在加载模块的脚本里，改写接口。

```js
import {a} from './xxx.js'

a = {}; // Syntax Error : 'a' is read-only;
```

但是如果a是一个对象，改写a的属性是允许的，并且改写成功后，其他模块也可以读到改写后的值。

```javascript
import {a} from './xxx.js'

a.foo = 'hello'; // 合法操作
```

### 要引入模块文件位置

`import`后边的`from`指定模块文件的位置，可以使相对路径，也可以是绝对路径，`.js`后缀可以省略。如果只是模块名，不带有路径，那么必须有配置文件，告诉js引擎改模块的位置。

```js
import {myMethod} form 'util';
```

### `import`命令提升

`import`命令会自动提升到整个模块的头部，首先执行

```js
foo();
import {foo} from 'my_module';  
```

上述代码不会有问题

### 不能使用表达式和变量

`import`是静态执行的，所以不能使用表达式和变量，这些只有在运行时才能得到结果的语法结构

```js
// 报错
import { 'f' + 'oo' } from 'my_module';

// 报错
let module = 'my_module';
import { foo } from module;

// 报错
if (x === 1) {
  import { foo } from 'module1';
} else {
  import { foo } from 'module2';
}
```

### 执行所加载模块

`import`语句会执行所加载的模块

```js
import 'lodash'; // 仅执行lodash模块，但不输入任何值
```

### 不会重复加载

如果多次执行同一句`import`语句，那么只会执行一次，而不会执行多次。

```js
import 'lodash'; // 仅执行lodash模块，但不输入任何值
import 'lodash'; // 仅执行lodash模块，但不输入任何值
```

```js
import { foo } from 'my_module'; 
import { bar } from 'my_module';

// 等同于
import { foo, bar } from 'my_module';
```

上面代码中，虽然`foo`和`bar`在两个语句中加载，但是它们对应的是同一个`my_module`实例。也就是说，`import`语句是 Singleton 模式。

## 模块的整体加载

除了指定加载某个输出值，还可以使用整体加载，即用星号(*)指定一个对象，所有输出都加载在这个对象上

####输出方法

```js
// circle.js
export function area(radius){
    return Math.PI * radius * radius;
}

export function circumference(radius){
    return Math.PI * 2 * radius;
}
```

####逐一加载

```js
// main.js
import {area, circumference} from "./circle"

console.log("面积"+ area(4));
console.log("面积"+ circumference(14));
```

####整体加载

```js
// main.js
import * as Circle from "./circle"

console.log("面积"+ Circle.area(4));
console.log("面积"+ Circle.circumference(14));
```

#### 不允许运行时改变

模块整体加载所在的对象(上文是`circle`)，应该是可以静态分析的，所以不允许运行时改变。

```js
// main.js
import * as Circle from "./circle"
Circle.foo = "hello"
Circle.area = function() {}
```

## `export default`命令

在使用`import`命令的时候，用户需要知道所要输入的变量名或者函数名，否则无法加载。

为了给用户提供方便，让他们不用阅读文档就能加载模块，就要`export default`命令，为模块指定默认输出。

```js
// export-default.js
export default function () {
    console.log('foo');
}
```

上面代码是一个模块文件`export-default.js`，默认输出是一个函数。

其他模块加载该模块时，`import`可以为该匿名函数指定任意名字。

```js
// import-default.js
import customName from './export-default'; // 不使用大括号
customName();//foo
```

可以用任意名称指向`export-default.js`模块的默认输出，这时候就不需要知道原输出输出的函数名

> `import` 命令加载其他模块的默认输出的时候，不适用大括号

`export  default`命令用在非匿名函数前，也是可以的。但是模块外部加载时，默认输出的非匿名函数视同匿名函数加载。

```js
export default function foo() {
    console.log('foo');
}
// 或者写成
function foo() {
    console.log('foo');
}
export default foo;
```

`export default`命令用于指定模块的默认输出，显然，一个模块只能有一个默认输出，因为`export default`命令只能使用一次，所以`import`命令后面才不用加大括号，因为只可能唯一对应export default。

本质上，`export default`就是输出一个叫做`default`的变量或方法，然后系统允许你为它取任意名字。

```js
function add(x, y) {
    return x * y;
}
export {add as default};
// 等同于 export deafult add;

import {default as foo} from 'modules';
// 等同于 import foo from 'modules';
```

正是因为`export default`命令其实只是输出一个叫`default`的变量，所以它后面不能跟变量声明语句；

```js
export var a = 1; // 正确

var a = 1
export default a; // 正确

// 错误
export default var a = 1;
```

上面代码中，`export default a `的含义是将变量`a`的值赋给`default`。所以最后一种写法会报错。

同样的，因为`export default`命令的本质是将后面的值，赋给`default`变量，所以可以直接写一个值写在`export default`之后。

```js
export default 42; // 正常 指定对外的接口为default
export 42; // 报错 没有指定对外的接口
```

如果想在一条`import`语句中，同时输入默认方法和其他接口，可以这样：

```js
import _, {each, forEach} from 'lodash';
```

对应上面代码的`export default`语句如下。

```js
export default function() {
    
}

export function each(obj, iterator, context) {
    
}

export {each as forEach};
```

`export deafult`也可以用来输出类。

```js
export default class {
    //
}

import MyClass from 'MyClass';
let o = new MyCalss();
```

## `export`和`import`的复合写法

如果一个模块之中，先输入后输出同一个模块，`import`语句可以与`export`写在一起

```js
export {foo, bar} from 'my_module'
```

可以理解为：

```js
import {foo, bar} from 'my_module';
export {foo, bar};
```

写成一行后，`foo`和`bar`实际上并没有导入当前模块，只是相对于对外转发了这两个接口，导致当前模块不能直接使用`foo`和`bar`

模块接口的的整体改名和整体输出，也可以采用这种写法。

```js
// 接口改名
export {foo as myFoo} from 'my_module';

// 整体输出
export * from 'my_module';
```

具名接口改为默认接口的写法如下：

```js
export  {es6 as default} from './someMoudle';

//等同于
import {es6} from './someModules';
export default es6;
```

同样的将默认接口改名为具名接口。

```js
export {default as es6} from '.someMoudle';
```

下面三种语句，没有对应的复合写法

```js
import * as someIndentifier from 'someModule';
import someIndentifier from 'someModule';
import someIndentifier, {nameIndentifier} from 'someModule';
```

## 模块的继承

模块之间是可以继承的

假设有一个`circleplus`模块，继承了`circle`模块

```js
// circleplus.js
export * from 'circle';
export var e = 2.71828182846;
export default function(x) {
  return Math.exp(x);
}
```

上面的`export *`,表示转发`circle`模块的所有属性和方法。`export *`命令会忽略掉`circle`模块的`default`方法。

这时，也可以将`circle`的属性或方法，改名后再输出。

```js
export {area as circleArea} form 'circle';
```

上面代码表示，只输出`circle`模块的`area`方法，切将其改名为`circleArea`。

加载上面的模块的写法如下：

```js
import * as math from 'circleplus';
import exp from 'circleplus';
console.log(exp(math.e));
```

## 跨模块常量

const声明的常量只在当前代码块有效。如果想设置跨模块的常量，或者一个值被多个模块共享，可以采用下面的写法：

```js
export const A = 1;
export const B = 3;
export const C = 4;

import * as constants from './constants';
console.log(constants.A);
console.log(constants.B);

import {A, B} from './constants';
console.log(A);
console.log(B);
```

如果要使用的常量比较多，可以建一个专门的`constants`目录，将各种常量写在不同的文件中，保存在改目录下。

```js
// constants/db.js
export const db = {
    url : "https://www.baidu.com",
    admin_name : "wangyu",
    admin_password : "123"
}

// constants/user.js
export const users = ['root', 'admin', 'staff', 'ceo', 'chief', 'moderator'];
```

然后在这些文件输出的常量，合并在`index.js`里

```js
export {db} from './db';
export {users} from './users';
```

使用的时候直接加载`index.js`就可以了。

```js
import {db, users} from './constants/index';
```



