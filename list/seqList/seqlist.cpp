#include <iostream>
#include <stdlib.h>
#include "seqlist.h"

using namespace std;

//初始化顺序表
list* list_init(int size)
{
    list *seqlist = (list *)malloc(sizeof(list));
    if(seqlist == NULL)
    {
        cout << "malloc err" << endl;
        return NULL;
    } 
    seqlist->data = (int *)malloc(sizeof(int) * size);
    if(seqlist->data == NULL)
    {
        cout << "malloc err" << endl;
        return NULL;
    }
    seqlist->length = 0;
    seqlist->size = size;
    return seqlist;
}

//释放顺序表申请的内存
list* list_deinit(list *seqlist)
{
    if(seqlist && seqlist->data)
    {
        free(seqlist->data);
        seqlist->data = NULL;
    }
    if(seqlist)
    {
        free(seqlist);
        seqlist = NULL;
    }   
    return seqlist;
}

//头部插入
int list_add_head(list *seqlist, int data)
{
    if(seqlist->length == seqlist->size)
    {
        cout << "list is full" << endl;
        return -1;
    }
    for (int i = seqlist->length; i > 0; i--)
    {
        seqlist->data[i] = seqlist->data[i-1];    
    }
    seqlist->data[0] = data;
    seqlist->length++;
    return 0;
}

//尾部插入
int list_add_tail(list *seqlist, int data)
{
    if(seqlist->length == seqlist->size)
    {
        cout << "list is full" << endl;
        return -1;
    }
    seqlist->data[seqlist->length] = data;
    seqlist->length++;
    return 0;
}

//随机插入
int list_insert(list *seqlist, int index, int data)
{
    if(seqlist->length == seqlist->size)
    {
        cout << "list is full" << endl;
        return -1;
    }
    if(index < 0 || index > seqlist->length)
    {
        cout << "index out of range" << endl;
        return -1;
    }
    for (int i = seqlist->length; i > index; i--)
    {
        seqlist->data[i] = seqlist->data[i-1];    
    }
    seqlist->data[index] = data;
    seqlist->length++;
    return 0;
}

//删除指定下标的元素
int list_del(list *seqlist, int index)
{
    if(0 == seqlist->length)
    {
        cout << "list is empty" << endl;
        return -1;
    }
    if(index < 0 || index > seqlist->length)
    {
        cout << "index out of range" << endl;
        return -1;
    }
    for (int i = index; i < seqlist->length; i++)
    {
        seqlist->data[i] = seqlist->data[i+1];    
    }
    seqlist->length--;
    return 0;
}

//改变指定下标的元素
int list_change(list *seqlist, int index, int data)
{
    if(0 == seqlist->length)
    {
        cout << "list is empty" << endl;
        return -1;
    }
    if(index < 0 || index > seqlist->length)
    {
        cout << "index out of range" << endl;
        return -1;
    }
    seqlist->data[index] = data;
    return 0;
}

//查找指定数据的元素
int list_find_data(list *seqlist, int data)
{
    if(0 == seqlist->length)
    {
        cout << "list is empty" << endl;
        return -1;
    }
    for (int i = 0; i < seqlist->length; i++)
    {
        if(seqlist->data[i] == data)
        {
            cout << "find success ! list[" << i << "] = " << data << endl;
            return 0;
        }
    }
    return -1;
}

//查找指定下标的元素
int list_find_index(list *seqlist, int index)
{
    if(0 == seqlist->length)
    {
        cout << "list is empty" << endl;
        return -1;
    }
    if(index < 0 || index > seqlist->length)
    {
        cout << "index out of range" << endl;
        return -1;
    }
    cout << "find success ! list[" << index << "] = " << seqlist->data[index] << endl;
    return 0;
}

//显示顺序表所有元素
int list_display(list *seqlist)
{
    if(0 == seqlist->length)
    {
        cout << "list is empty" << endl;
        return -1;
    }
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < seqlist->length; i++)
    {
        cout << "list[" << i << "] = " << seqlist->data[i] << endl;
    }
    return 0;
}
