#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

using namespace std;
int listsize = 0;                               //总节点数

//初始化静态链表
node * list_init(int size)
{
    int i = 0;
    node *pnode = (node *)malloc(sizeof(node) * size);
    if(pnode == NULL)
    {
        cout << "malloc err" << endl;
        return NULL;
    }
    listsize = size;                            //记录总节点数，方便判满判空时使用
    memset(pnode, 0, sizeof(node) * size);      //所有元素初始化为0
    for (i = 0; i < size; i++)
    {
        pnode[i].cursor = i+1;                  //初始化备用链表的游标
    }
    pnode[i-1].cursor = 0;                      //数据链表头节点，游标置为0
    pnode[i-2].cursor = 0;                      //备用链表最后一个节点，游标置为0
    return pnode;
}

//释放申请的内存
node * list_deinit(node *pnode)
{
    if(pnode == NULL)
    {
        cout << "list pointer is NULL" << endl;
        return NULL;    
    }
    free(pnode);
    return NULL;
}

//在数据链表的头部插入
int list_add_head(node *pnode, int data)
{
    //链表不存在
    if(pnode == NULL)
    {
        cout << "list pointer is NULL" << endl;
        return -1;    
    }
     //数据链表已满(备用链表已空)
    if(pnode[0].cursor == 0)    //备用链表头节点指向自己
    {
        cout << "data list is full" << endl;
        return -1;    
    }
    //从备用链表中取出一个节点
    int index = pnode[0].cursor;            //这是从备用链表取出的节点，用来存放数据
    pnode[0].cursor = pnode[index].cursor;  //让备用链表的头节点，指向取出节点的下一个节点
    pnode[index].data = data;               //保存数据
    //将取出的节点放入数据链表
    pnode[index].cursor = pnode[listsize - 1].cursor;   //取出的节点游标指向数据链表的首元节点
    pnode[listsize - 1].cursor = index;     //数据链表的头节点指向取出的节点
    return 0;
}

//在数据链表的尾部插入
int list_add_tail(node *pnode, int data)
{
    //链表不存在
    if(pnode == NULL)
    {
        cout << "list pointer is NULL" << endl;
        return -1;    
    }
    //数据链表已满(备用链表已空)
    if(pnode[0].cursor == 0)    //备用链表头节点指向自己
    {
        cout << "data list is full" << endl;
        return -1;    
    }
    //从备用链表中取出一个节点
    int index = pnode[0].cursor;            //这是从备用链表取出的节点，用来存放数据
    pnode[0].cursor = pnode[index].cursor;  //让备用链表的头节点，指向取出节点的下一个节点
    pnode[index].data = data;               //保存数据
    //找到数据链表的尾部节点
    int idata = listsize - 1;               //先定位到数据链表的头节点
    while(pnode[idata].cursor != 0)
    {
        idata = pnode[idata].cursor;
    }
    //将取出的节点放入数据链表
    pnode[index].cursor = pnode[idata].cursor;  //取出的节点游标指向0(类似于普通链表的末尾指向NULL)
    pnode[idata].cursor = index;                //原数据链表尾节点指向取出的节点
    return 0;
}

//删除指定元素
//暂不考虑两个节点数据相同的情况
int list_del(node *pnode, int data)
{
    int idata = listsize - 1;       //数据链表的头节点位置
    int idatalast;
    //链表不存在
    if(pnode == NULL)
    {
        cout << "list pointer is NULL" << endl;
        return -1;    
    }
    //数据链表为空
    if(pnode[idata].cursor == 0)    //备用链表头节点指向自己
    {
        cout << "data list is empty" << endl;
        return -1;    
    }
    //寻找数据元素
    while(pnode[idata].cursor != 0)
    {
        idatalast = idata;
        idata = pnode[idata].cursor;
        if(pnode[idata].data == data)   //找到了，此时idata为要删除节点的下标，idatalast为要删除节点的上一个节点下标
        {
            //将该节点从数据节点从删除
            pnode[idatalast].cursor = pnode[idata].cursor;
            pnode[idata].data = 0;
            //将该节点加入备用链表
            pnode[idata].cursor = pnode[0].cursor;
            pnode[0].cursor = idata;
            return 0;
        }
    }
    return -1;
}

//改变指定元素
//暂不考虑两个节点数据相同的情况
int list_change(node *pnode, int olddata, int newdata)
{
    int idata = listsize - 1;       //数据链表的头节点位置
    int idatalast;
    //链表不存在
    if(pnode == NULL)
    {
        cout << "list pointer is NULL" << endl;
        return -1;    
    }
    //数据链表为空
    if(pnode[idata].cursor == 0)    //备用链表头节点指向自己
    {
        cout << "data list is empty" << endl;
        return -1;    
    }
    //寻找数据元素
    while(pnode[idata].cursor != 0)
    {
        idatalast = idata;
        idata = pnode[idata].cursor;
        if(pnode[idata].data == olddata)   //找到了
        {
            pnode[idata].data = newdata;
            return 0;
        }
    }
    return -1;
}

//查找指定数据的元素
//暂不考虑两个节点数据相同的情况
int list_find_data(node *pnode, int data)
{
    int idata = listsize - 1;       //数据链表的头节点位置
    int idatalast;
    //链表不存在
    if(pnode == NULL)
    {
        cout << "list pointer is NULL" << endl;
        return -1;    
    }
    //数据链表为空
    if(pnode[idata].cursor == 0)    //备用链表头节点指向自己
    {
        cout << "data list is empty" << endl;
        return -1;    
    }
    //寻找数据元素
    while(pnode[idata].cursor != 0)
    {
        idatalast = idata;
        idata = pnode[idata].cursor;
        if(pnode[idata].data == data)   //找到了
        {
            cout << "finded! list[" << idata << "] = "<< data << endl;
            return 0;
        }
    }
    return -1;
}

//显示静态链表所有元素
int list_display(node *pnode)
{
    int i = 0;
    if(pnode == NULL)
    {
        cout << "list pointer is NULL" << endl;
        return -1;    
    }
    //显示备用链表
    //如果备用链表为空，则首次while判断时，头节点游标指向本身，不满足循环条件，直接退出
    cout << "--------- Spare list ---------" << endl;
    while(pnode[i].cursor != 0)
    {
        cout << "list[" << i << "] : data = " << pnode[i].data;
        cout << ", cursor = " << pnode[i].cursor << endl;
        i = pnode[i].cursor;
    }
    //显示备用链表的最后一个节点，该节点游标指向头节点，不满足循环条件，因此单独打印
    cout << "list[" << i << "] : data = " << pnode[i].data;
    cout << ", cursor = " << pnode[i].cursor << endl;

    //显示数据链表
    //数据链表的头节点为整个链表末尾的那个节点，该节点不用于存储数据
    //如果数据链表为空，则数据链表头节点游标指向0，即指向了备用链表头节点
    cout << "--------- data list ---------" << endl;
    i = listsize - 1;
    while(pnode[i].cursor != 0)
    {
        cout << "list[" << i << "] : data = " << pnode[i].data;
        cout << ", cursor = " << pnode[i].cursor << endl;
        i = pnode[i].cursor;
    }
    //显示数据链表的最后一个节点，该节点游标指向备用链表头节点，不满足循环条件，因此单独打印
    cout << "list[" << i << "] : data = " << pnode[i].data;
    cout << ", cursor = " << pnode[i].cursor << endl;
    return 0;
}
