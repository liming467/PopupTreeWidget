# 右键菜单控制节点显隐的QTreeWidget功能实现——PopupTreeWidget

# 实现功能：
右键点击弹出带有显示和隐藏两个action的菜单。其中，显示、隐藏action用字体颜色表示，显示时为黑色，隐藏时为lightGray。如果是父节点显示或隐藏，其下的子节点也会跟着显示或隐藏，这个功能主要靠递归函数实现，有些暴力，还有待改善算法实现。Plus，多选也是支持滴。

# Realized functions：
When right button is clicked, a menu will be popup with two actions-show and hide. The function of two actions is realized by node text color. Black color is show, lightGray for hide. If parent node is showed or hidden, its children is correspondingly showed or hidden. This function is mainly implemented by recursive function. The back algorithm is brute-force and is waiting for improving. Plus, multi-selection is also suppoeted. 

![image](https://github.com/liming467/PopupTreeWidget/blob/main/node.png)
 
