#ifndef LINKLIST_H
#define LINKLIST_H

//静态链表
//静态链表有两个特殊的节点不存放数据
//第一个节点，游标指向备用链表，相当于备用链表的头节点
//最后一个节点，游标指向数据链表，相当于数据链表的头节点
typedef struct linknode
{
    int data;               //数据
    int cursor;             //游标，指向下一个节点
}node;

node * list_init(int size);
node *list_deinit(node *pnode);
int list_add_head(node *pnode, int data);
int list_add_tail(node *pnode, int data);
int list_del(node *pnode, int data);
int list_change(node *pnode, int olddata, int newdata);
int list_find_data(node *pnode, int data);
int list_display(node *pnode);

#endif