#include <iostream>
#include <stdlib.h>
#include "seqStack.h"

using namespace std;

//初始化顺序栈
stack* stack_init(int size)
{
    stack *seqstack = (stack *)malloc(sizeof(stack));
    if(seqstack == NULL)
    {
        cout << "malloc err" << endl;
        return NULL;
    } 
    seqstack->data = (int *)malloc(sizeof(int) * size);
    if(seqstack->data == NULL)
    {
        cout << "malloc err" << endl;
        return NULL;
    }
    seqstack->length = 0;
    seqstack->size = size;
    return seqstack;
}

//释放顺序栈申请的内存
stack* stack_deinit(stack *seqstack)
{
    if(seqstack && seqstack->data)
    {
        free(seqstack->data);
        seqstack->data = NULL;
    }
    if(seqstack)
    {
        free(seqstack);
        seqstack = NULL;
    }   
    return seqstack;
}

//头部插入
int stack_add_head(stack *seqstack, int data)
{
    if(seqstack->length == seqstack->size)
    {
        cout << "stack is full" << endl;
        return -1;
    }
    for (int i = seqstack->length; i > 0; i--)
    {
        seqstack->data[i] = seqstack->data[i-1];    
    }
    seqstack->data[0] = data;
    seqstack->length++;
    return 0;
}

//尾部插入
int stack_add_tail(stack *seqstack, int data)
{
    if(seqstack->length == seqstack->size)
    {
        cout << "stack is full" << endl;
        return -1;
    }
    seqstack->data[seqstack->length] = data;
    seqstack->length++;
    return 0;
}

//随机插入
int stack_insert(stack *seqstack, int index, int data)
{
    if(seqstack->length == seqstack->size)
    {
        cout << "stack is full" << endl;
        return -1;
    }
    if(index < 0 || index > seqstack->length)
    {
        cout << "index out of range" << endl;
        return -1;
    }
    for (int i = seqstack->length; i > index; i--)
    {
        seqstack->data[i] = seqstack->data[i-1];    
    }
    seqstack->data[index] = data;
    seqstack->length++;
    return 0;
}

//删除指定下标的元素
int stack_del(stack *seqstack, int index)
{
    if(0 == seqstack->length)
    {
        cout << "stack is empty" << endl;
        return -1;
    }
    if(index < 0 || index > seqstack->length)
    {
        cout << "index out of range" << endl;
        return -1;
    }
    for (int i = index; i < seqstack->length; i++)
    {
        seqstack->data[i] = seqstack->data[i+1];    
    }
    seqstack->length--;
    return 0;
}

//改变指定下标的元素
int stack_change(stack *seqstack, int index, int data)
{
    if(0 == seqstack->length)
    {
        cout << "stack is empty" << endl;
        return -1;
    }
    if(index < 0 || index > seqstack->length)
    {
        cout << "index out of range" << endl;
        return -1;
    }
    seqstack->data[index] = data;
    return 0;
}

//查找指定数据的元素
int stack_find_data(stack *seqstack, int data)
{
    if(0 == seqstack->length)
    {
        cout << "stack is empty" << endl;
        return -1;
    }
    for (int i = 0; i < seqstack->length; i++)
    {
        if(seqstack->data[i] == data)
        {
            cout << "find success ! stack[" << i << "] = " << data << endl;
            return 0;
        }
    }
    return -1;
}

//查找指定下标的元素
int stack_find_index(stack *seqstack, int index)
{
    if(0 == seqstack->length)
    {
        cout << "stack is empty" << endl;
        return -1;
    }
    if(index < 0 || index > seqstack->length)
    {
        cout << "index out of range" << endl;
        return -1;
    }
    cout << "find success ! stack[" << index << "] = " << seqstack->data[index] << endl;
    return 0;
}

//显示顺序栈所有元素
int stack_display(stack *seqstack)
{
    if(0 == seqstack->length)
    {
        cout << "stack is empty" << endl;
        return -1;
    }
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < seqstack->length; i++)
    {
        cout << "stack[" << i << "] = " << seqstack->data[i] << endl;
    }
    return 0;
}
