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
int list_add_head(list *seqlist, int data);
int list_add_tail(list *seqlist, int data);
int list_insert(list *seqlist, int index, int data);
int list_del(list *seqlist, int index);
int list_change(list *seqlist, int index, int data);
int list_find_data(list *seqlist, int data);
int list_find_index(list *seqlist, int index);
int list_display(list *seqlist);

#endif