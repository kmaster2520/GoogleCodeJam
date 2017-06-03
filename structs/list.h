
typedef struct lnode {
    void* data;
    struct lnode* next;
    struct lnode* prev;
} lnode_t;

// circular double linked list
typedef struct llist {
    int size;
    lnode_t* head;
} llist_t*;

void* listAdd(llist_t*, int);
void* listRemove(llist_t*, int);
void* listPopFirst(llist_t*);
void* listPopLast(llist_t*);
void* listPushFirst(llist_t*, void*);
void* listPushLast(llist_t*, void*);