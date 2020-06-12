#ifndef SEQSTACK_H
#define SEQSTACK_H

typedef struct seqStack
{
    int *data;      //动态数组
    int length;     //当前数据长度
    int size;       //总长度
}stack;

stack *stack_init(int size);
stack *stack_deinit(stack *seqstack);
int stack_add_head(stack *seqstack, int data);
int stack_add_tail(stack *seqstack, int data);
int stack_insert(stack *seqstack, int index, int data);
int stack_del(stack *seqstack, int index);
int stack_change(stack *seqstack, int index, int data);
int stack_find_data(stack *seqstack, int data);
int stack_find_index(stack *seqstack, int index);
int stack_display(stack *seqstack);

#endif