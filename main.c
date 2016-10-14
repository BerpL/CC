#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node* crearlista(struct node *head,int n){
    struct node *prev;
    struct node *cur;
    int i;
    head = malloc(sizeof(struct node));
    head -> val = 1;
    prev = head;
    for(i=2;i<=n;i++){
        cur = malloc(sizeof(struct node));
        cur ->val = i ;
        prev ->next = cur;
        prev = cur;
    }
    prev ->next = NULL;
    return head;
}

void imprimirlista(struct node *head){
    struct node *t;
    t = head;
    while (t != NULL){
        printf("%d", t ->val);
        t = t-> next;
    }
}
struct node* borrarnodo(struct node *head, int n){
    struct node *prev, *cur, *temp;
    prev = head;
    cur = head ->next;

    if(head ->val ==n){
        temp = head;
        head = head ->next;
        free(temp);
        return head;
    }

        while(cur!= NULL){
            if(cur->val == n){
                prev -> next = cur ->next;
                free(cur);
                break;
            }
            prev = cur;
            cur = cur ->next;
        }

    return head;
}
struct node* insertar_inicio(struct node *head, int n){
    struct node *prev, *cur, *temp;
    temp = malloc(sizeof(struct node));
    temp ->val = n;
    temp ->next = head;
    head = temp;
    return head;
}
struct node* insertar_final(struct node *head, int n){
    struct node *prev, *cur, *temp;
    temp = malloc(sizeof(struct node));
    temp ->val =n;
    cur = head;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = temp;
    return head;
}

main()
{
    struct node *head;
    head = crearlista(head,5);
    head = insertar_inicio(head,2);
    head = insertar_final(head,1);
    head = borrarnodo(head,6);
    imprimirlista(head);
}

