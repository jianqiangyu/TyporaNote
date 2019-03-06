##12.6 

### 相交链表

编写一个程序，找到两个单链表相交的起始节点。

例如，下面的两个链表**：**

```
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
```

在节点 c1 开始相交。

**注意：**

- 如果两个链表没有交点，返回 `null`.
- 在返回结果后，两个链表仍须保持原有的结构。
- 可假定整个链表结构中没有循环。
- 程序尽量满足 O(*n*) 时间复杂度，且仅用 O(*1*) 内存。

两种思路:

第一种

* 先计算两条链表的长度
* 让长的那条先走几步，达到长度一样的效果
* 一直往下比较，有相同的返回交点，如果走完都没有相同的，则返回null

```c
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if (headA == NULL || headB == NULL) {  return NULL; }
    
    int lengthA  = 0;
    struct ListNode *temp = headA;
    while (temp != NULL) {
        lengthA++;
        temp = temp->next;
    }
    
    int lengthB  = 0;
    temp = headB;
    while (temp != NULL) {
        lengthB++;
        temp = temp->next;
    }

    if(lengthA > lengthB) {
        for(int i =  0; i < lengthA - lengthB; i++) {
            headA = headA->next;
        }
    }else {
         for(int i =  0; i < lengthB - lengthA; i++) {
            headB = headB->next;
        }
    }
    
     while(headA != NULL) {
        if(headA == headB) {
            return headA;
        }else{
            headA = headA->next;
            headB = headB->next;
        }
    }
    return NULL;
}
```



第二种

* ListA + ListB = OnlyA + Intersection + OnlyB + Intersection 
* ListB + ListA = OnlyB + Intersection + OnlyA + Intersection
* 长度相同的在第一轮就能找到交点
* 长度不相同的在第二轮能找到交点（OnlyA + Intersection + OnlyB =  OnlyB + Intersection + OnlyA）

```java
public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
      if (headA == null || headB == null) return null;
        ListNode p = headA, q = headB;
        while (p != q){
            p = p == null ? headB : p.next;
            q = q == null ? headA : q.next;
        }
       return p;
    }
}
```

环形链表

排序复习

##12.7

###二叉树的层次遍历

给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

返回其层次遍历结果：

```
[
  [3],
  [9,20],
  [15,7]
]
```

两种思路:

```java
public class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}
```

一、 队列

```java


class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result= new ArrayList<>();
        if(root == null) {
            return result;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int size = 0;
        while(queue.isEmpty() == false) {
            List<Integer> level= new ArrayList<>();
            size = queue.size();
            for(int i = 0; i < size; i++) {
                TreeNode node = queue.remove();
                level.add(node.val);
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            result.add(level);
        }
        return result;
    }
}
```

二、 递归

```java
class Solution {
     public void levelOrderHelper(TreeNode root, int level, List<List<Integer>> result) {
         if(root==null) {
             return;
         }
         if(result.size() < level+1) {
             result.add(new ArrayList());
         }
         result.get(level).add(root.val);
         if(root.left != null) {
             levelOrderHelper(root.left, level+1, result);
         }
         if(root.right != null) {
             levelOrderHelper(root.right, level+1, result);
         }
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result= new ArrayList<>();
        if(root != null) {
            levelOrderHelper(root, 0, result);
        }
        return result;
    }
}
```

### 113. 路径总和 II

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

**说明:** 叶子节点是指没有子节点的节点。

**示例:**
给定如下二叉树，以及目标和 `sum = 22`，

```
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
```

返回:

```
[
   [5,4,11,2],
   [5,8,4,5]
]
```

思路：

栈配合递归

```java
class Solution {
    
    public void pathSumHelper(TreeNode node, int sum, Stack<Integer> stack,  List<List<Integer>> result) {
        
        if(node == null) {
            return ;
        }
        
        stack.push(node.val);
        
        if(node.left == null && node.right == null) {
            if(node.val == sum) {
                result.add(new ArrayList(stack));
            }
        }
        
        if(node.left != null) {
        	 pathSumHelper(node.left, sum-node.val, stack, result);
        }
        
         if(node.right != null) {
        	 pathSumHelper(node.right, sum-node.val, stack, result);
        }
        
        stack.pop();
    }
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        
        if (root != null) {
			Stack<Integer> stack = new Stack<>();
            pathSumHelper(root, sum, stack, result);
        }
        
        return result;
    }
}
```

## 12.8

###排序链表

#### 插入排序

```java
public class Solution {
    public static void insertSort(Comparable[] a) {
        int N = a.length;
        for (int i = 0;i < N; i++) 
        
        
    }
}
```

