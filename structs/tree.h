
typedef struct tnode {
    void* data;
    struct tnode* left;
    struct tnode* right;
} tnode_t;

typedef struct bst {
    int size;
    tnode_t* root;
    int (*compar)(const void *, const void*);
} bst_t;

typedef struct tlnode {
    void* data;
    struct tlnode* next;
} tlnode_t;

typedef struct tlist {
    int size;
    tlnode_t* head;
    tlnode_t* tail;
} tlist_t;

//tnode_t* createTNode(void*);
void bstAppend(bst_t*, void*);
void bstRemove(bst_t*, void*);
//void* bstRemoveLargest(bst_t*);
//void* bstRemoveSmallest(bst_t*);
int bstContains(bst_t*, void*);
void bstFree(bst_t*);
void bstClear(bst_t*);
tlist_t* bstPreorder(bst_t*);
tlist_t* bstPostorder(bst_t*);
tlist_t* bstInorder(bst_t*);
void bstFreeList(tlist_t*);
void printTlist(tlist_t*);

