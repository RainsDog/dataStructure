#ifndef LINKLIST_H
#define LINKLIST_H

//双向链表
typedef struct linknode
{
    int data;               //数据
    struct linknode *prev;  //指向上一个节点
    struct linknode *next;  //指向下一个节点
}node;

int list_init(node **pnode);
node *list_deinit(node *pnode);
int list_add_head(node *pnode, int data);
int list_add_tail(node *pnode, int data);
int list_display(node *pnode);
int list_del(node *pnode, int data);
int list_change(node *pnode, int olddata, int newdata);
int list_find_data(node *pnode, int data);

#endif