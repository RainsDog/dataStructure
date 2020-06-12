#ifndef SEQLIST_H
#define SEQLIST_H

typedef struct seqlist
{
    int *data;      //动态数组
    int length;     //顺序表当前数据长度
    int size;       //顺序表总长度
}list;

list *list_init(int size);
list *list_deinit(list *seqlist);
int list_check(list *seqlist);

#endif