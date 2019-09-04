#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct Linked_list
{
    Node *head;
    int size;
} Linked_list;

void print_list(Linked_list *list)
{
    if (list == NULL)
        return;

    if (list->size == 0)
    {
        printf("List is empty\n");
        return;
    }

    printf("Elements of Linked_list:\n");

    Node *node = list->head;
    while (node != NULL)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

void insert_node(Linked_list *list, int val, int pos)
{
    if (list == NULL)
        return;

    if (pos < 0)
    {
        printf("Position must >= 0\n");
        return;
    }

    if (pos > list->size)
    {
        printf("Position bigger than the size of the list\n");
        return;
    }

    if (list->size == 0)
    {
        Node *node = malloc(sizeof(Node));
        node->val = val;
        node->next = NULL;

        list->head = node;
    }
    else
    {
        if (pos == 0)
        {
            Node *node = malloc(sizeof(Node));
            node->val = val;
            node->next = list->head;

            list->head->next = list->head;
            list->head = node;
            return;
        }
        else
        {
            Node *cur_node = list->head;
            while (pos > 1)
            {
                cur_node = cur_node->next;
                pos--;
            }

            Node *node = malloc(sizeof(Node));
            node->val = val;
            node->next = NULL;

            Node *tmp = cur_node->next;
            cur_node->next = node;
            node->next = tmp;
        }
    }
    list->size++;
}

void delete_node(Linked_list *list, int pos)
{
    if (pos < 0)
    {
        printf("Position must >= 0\n");
        return;
    }
    if (pos >= list->size)
    {
        printf("Position equal or bigger than the size of the list\n");
        return;
    }
    if (pos == 0)
    {
        Node *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }
    else
    {
        Node *cur_node = list->head;
        while (pos > 1)
        {
            cur_node = cur_node->next;
            pos--;
        }

        Node *toRemove = cur_node->next;
        cur_node->next = toRemove->next;
        free(toRemove);
    }

    list->size--;
}

void init_list(Linked_list *list)
{
    list->size = 0;
    list->head = NULL;
}

int main(void)
{
    Linked_list *l = malloc(sizeof(Linked_list));
    init_list(l);

    insert_node(l, 0, 0);
    insert_node(l, 2, 1);
    insert_node(l, 4, 2);
    insert_node(l, 8, 3);

    print_list(l);
    delete_node(l, 3);
    print_list(l);
    delete_node(l, 1);
    print_list(l);
    delete_node(l, 0);
    print_list(l);
    return 0;
}