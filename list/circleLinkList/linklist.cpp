#include <iostream>
#include <stdlib.h>
#include "linklist.h"

using namespace std;

//初始化链表
int list_init(node **pnodo)
{
    *pnodo = (node *)malloc(sizeof(node));
    if((*pnodo) == NULL)
    {
        cout << "malloc err" << endl;
        return -1;
    }
    (*pnodo)->data = 0;
    (*pnodo)->prev = *pnodo;
    (*pnodo)->next = *pnodo;
    return 0;
}
 
//释放申请的内存
node * list_deinit(node *pnode)
{
    if(pnode == NULL)
    {
        cout << "list head is NULL" << endl;
        return NULL;    
    }
    node *head = pnode;     //记录头节点
    pnode = pnode->next;    //指向头节点的下一个节点
    node *p = pnode;        //删除某个节点前，记录下一个要删除的节点指针
    while(pnode != head)    //要删除的节点指针为头节点时，说明已经回到了起点，退出
    {
        p = p->next;
        free(pnode);            //释放节点内存 
        pnode = p;
    }
    return NULL;
}

//头部插入
int list_add_head(node *pnode, int data)
{
    if(pnode == NULL)
    {
        cout << "list head is NULL" << endl;
        return -1;
    }
    node *p = (node *)malloc(sizeof(node));
    if(p == NULL)
    {
        cout << "malloc err" << endl;
        return -1;
    }
    p->data = data;
    p->prev = pnode;
    p->next = pnode->next;
    p->next->prev = p;
    pnode->next = p;
    return 0;
}

//尾部插入
int list_add_tail(node *pnode, int data)
{
    if(pnode == NULL)
    {
        cout << "list head is NULL" << endl;
        return -1;    
    }
    node *p = (node *)malloc(sizeof(node));
    if(p == NULL)
    {
        cout << "malloc err" << endl;
        return -1;
    }
    node *head = pnode;         //记录头节点
    while(pnode->next != head)  //找到最后一个节点pnode
        pnode = pnode->next;
    p->data = data;
    p->prev = pnode;
    p->next = pnode->next;
    pnode->next = p;
    pnode->next->prev = p;
    return 0;
}

//删除指定元素
//暂不考虑两个节点数据相同的情况
int list_del(node *pnode, int data)
{
    if(pnode == NULL)
    {
        cout << "list head is NULL" << endl;
        return -1;    
    }
    if(pnode->next == NULL)
    {
        cout << "list is empty" << endl;
        return -1;
    }
    while(pnode->next != NULL)
    { 
        if(pnode->next->data == data)
        {
            node *p = pnode->next->next;    //此时p记录被删除节点的后一个节点，pnode记录被删除节点的前一个节点
            free(pnode->next);
            pnode->next = p;
            p->prev = pnode;
            return 0;
        }
        pnode = pnode->next;
    }  
    return -1;
}

//改变指定元素
//暂不考虑两个节点数据相同的情况
int list_change(node *pnode, int olddata, int newdata)
{
    if(pnode == NULL)
    {
        cout << "list head is NULL" << endl;
        return -1;    
    }
    if(pnode->next == NULL)
    {
        cout << "list is empty" << endl;
        return -1;
    }
    node *head = pnode;         //记录头节点
    while(pnode->next != head)
    { 
        if(pnode->next->data == olddata)
        {
            pnode->next->data = newdata;
            return 0;
        }
        pnode = pnode->next;
    }
    return -1;
}

//查找指定数据的元素
//暂不考虑两个节点数据相同的情况
int list_find_data(node *pnode, int data)
{
    if(pnode == NULL)
    {
        cout << "list head is NULL" << endl;
        return -1;    
    }
    if(pnode->next == NULL)
    {
        cout << "list is empty" << endl;
        return -1;
    }
    int index = 0;
    node *head = pnode;         //记录头节点
    while(pnode->next != head)
    {
        if(pnode->next->data == data)
        {
            cout << "finded! list[" << index << "] = "<< data << endl;
            return 0;
        }
        pnode = pnode->next;
        index++;
    }
    return -1;
}

//显示所有元素
int list_display(node *pnode)
{
    if(pnode == NULL)
    {
        cout << "list head is NULL" << endl;
        return -1;    
    }
    if(pnode->next == NULL)
    {
        cout << "list is empty" << endl;
        return -1;    
    }
    cout << "list : ";
    node *head = pnode; //记录头节点
    pnode = pnode->next;
    while(pnode != head)
    {
        cout << pnode->data << " ";
        pnode = pnode->next;
    }
    cout << endl;
    return 0;
}
