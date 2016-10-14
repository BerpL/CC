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
struct node* crearlista2(struct node *head2,int n){
    struct node *prev;
    struct node *cur;
    int i;
    head2 = malloc(sizeof(struct node));
    head2 -> val = 1;
    prev = head2;
    for(i=2;i<=n;i++){
        cur = malloc(sizeof(struct node));
        cur ->val = i ;
        prev ->next = cur;
        prev = cur;
    }
    prev ->next = NULL;
    return head2;
}
struct node* concatenar(struct node *head, struct node *head2){
    struct node *p;
    p = head;
    while((p->next)!=NULL){
        p = p -> next;
    }
    p->next = head2;
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
//struct node* insertar_final(struct node *head, int n){
//    struct node *prev, *cur, *temp;
//    temp = malloc(sizeof(struct node));
//    temp ->val =n;
//    cur = head;
//    while(cur->next){
//        cur = cur->next;
//    }
//    cur->next = temp;
//    return head;
//}
struct node* insertar(struct node *head, int num, int pos){
    struct node *temp, *prev, *cur, *p;
    int i;
    p = head;
    prev = head;
    cur = head ->next;

    if (pos==0){
        temp = malloc(sizeof(struct node));
        temp ->val = num;
        temp->next = head;
        return temp;
    }

    for(i=1;cur->next!=NULL;i++){
        if(i==pos){
            temp = malloc(sizeof(struct node));
            temp ->val = num;

            prev->next = temp;
            temp->next = cur;
        }
        prev =cur;
        cur = cur->next;
    }
    temp = malloc(sizeof(struct node));
    temp ->val = num;

    prev->next = temp;
    temp->next = cur;


    return head;
}

main()
{
    struct node *head;
    struct node *head2;
    head = crearlista(head,5);
    head2 = crearlista2(head2,4);
    head = insertar(head,9,4);
//    head = insertar_inicio(head,2);
//    head = borrarnodo(head,6);
//    head = concatenar(head,head2);
    imprimirlista(head);
}
