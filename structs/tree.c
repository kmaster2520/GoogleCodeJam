#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

tnode_t* createTNode(void* data) {
    tnode_t* newNode = malloc(sizeof(tnode_t));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


tnode_t* bstAppend2(bst_t* bst, void* data, tnode_t* curr) {
    if (curr == NULL) {
        bst->size += 1;
        return createTNode(data);
    }
    int c = bst->compar(data, curr->data);
    if (c < 0) {
        curr->left = bstAppend2(bst, data, curr->left);
    } else if (c > 0) {
        curr->right = bstAppend2(bst, data, curr->right);
    }
    return curr;
}
void bstAppend(bst_t* bst, void* data) {
    bst->root = bstAppend2(bst, data, bst->root);
}


void* bstRemove3(bst_t* bst, tnode_t* orig) { // find/remove largest element on left subtree
    tnode_t* paren = orig;
    tnode_t* child = orig->left;
    int didMove = 0;
    while (child->right != NULL) {
        paren = child;
        child = child->right;
        didMove = 1;
    }
    if (didMove == 0) {
        paren->left = child->left;
    } else {
        paren->right = child->left;
    }
    void* retData = child->data;
    free(child);
    return retData;
}
tnode_t* bstRemove2(bst_t* bst, void* data, tnode_t* curr) {
    if (curr == NULL) {
        return NULL;
    }
    int c = bst->compar(data, curr->data);
    if (c < 0) {
        curr->left = bstAppend2(bst, data, curr->left);
    } else if (c > 0) {
        curr->right = bstAppend2(bst, data, curr->right);
    } else {
        // found it
        int nc = 0;
        if (curr->left != NULL) {
            nc += 1;
        }
        if (curr->right != NULL) {
            nc += 2;
        }
        bst->size -= 1;
        //
        if (nc == 0) {
            return NULL;
        } else if (nc == 1) {
            tnode_t* retNode = curr->left;
            free(curr);
            return retNode;
        } else if (nc == 2) {
            tnode_t* retNode = curr->right;
            free(curr);
            return retNode;
        } else { // 2 children
            curr->data = bstRemove3(bst, curr);
            return curr;
        }
    }
    return curr;
}
void bstRemove(bst_t* bst, void* data) {
    bst->root = bstRemove2(bst, data, bst->root);
}

int bstContains2(bst_t* bst, void* data, tnode_t* curr) {
    if (curr == NULL) {
        return 0;
    }
    int c = bst->compar(data, curr->data);
    if (c < 0) {
        return bstContains2(bst, data, curr->left);
    } else if (c > 0) {
        return bstContains2(bst, data, curr->right);
    }
    return 1;
}
int bstContains(bst_t* bst, void* data) {
    return bstContains2(bst, data, bst->root);
}


void bstFree2(bst_t* bst, tnode_t* curr) {
    if (curr != NULL) {
        bstFree2(bst, curr->left);
        bstFree2(bst, curr->right);
        free(curr);
    }
}
void bstFree(bst_t* bst) {
    bstFree2(bst, bst->root);
    free(bst);
}


void bstClear2(bst_t* bst, tnode_t* curr) {
    if (curr != NULL) {
        bstClear2(bst, curr->left);
        bstClear2(bst, curr->right);
        free(curr);
    }
}
void bstClear(bst_t* bst) {
    bstClear2(bst, bst->root);
    bst->size = 0;
    bst->root = NULL;
}


void bstPreorder2(tnode_t* curr, tlist_t* list) {
    if (curr != NULL) {
        tlnode_t* newNode = malloc(sizeof(tlnode_t));
        newNode->data = curr->data;
        newNode->next = NULL;
        if (list->size == 0) {
            list->head = newNode;
        } else {
            list->head->next = newNode;
        }
        list->tail = newNode;
        list->size += 1;
        //
        bstPreorder2(curr->left, list);
        bstPreorder2(curr->right, list);
        
    }
}
tlist_t* bstPreorder(bst_t* bst) {
    tlist_t* list = malloc(sizeof(tlist_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    bstPreorder2(bst->root, list);
    return list;
}


void bstPostorder2(tnode_t* curr, tlist_t* list) {
    if (curr != NULL) {
        bstPostorder2(curr->left, list);
        bstPostorder2(curr->right, list);
        //
        tlnode_t* newNode = malloc(sizeof(tlnode_t));
        newNode->data = curr->data;
        newNode->next = NULL;
        if (list->size == 0) {
            list->head = newNode;
        } else {
            list->tail->next = newNode;
        }
        list->tail = newNode;
        list->size += 1;
        
    }
}
tlist_t* bstPostorder(bst_t* bst) {
    tlist_t* list = malloc(sizeof(tlist_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    bstPostorder2(bst->root, list);
    return list;
}

void bstInorder2(tnode_t* curr, tlist_t* list) {
    if (curr != NULL) {
        bstInorder2(curr->left, list);
        //
        tlnode_t* newNode = malloc(sizeof(tlnode_t));
        newNode->data = curr->data;
        newNode->next = NULL;
        if (list->size == 0) {
            list->head = newNode;
        } else {
            list->tail->next = newNode;
        }
        list->tail = newNode;
        list->size += 1;
        //
        bstInorder2(curr->right, list);
        
    }
}
tlist_t* bstInorder(bst_t* bst) {
    tlist_t* list = malloc(sizeof(tlist_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    bstInorder2(bst->root, list);
    return list;
}


void bstFreeList2(tlnode_t* curr) {
    if (curr != NULL) {
        bstFreeList2(curr->next);
        free(curr);
    }
} 
void bstFreeList(tlist_t* list) {
    bstFreeList2(list->head);
    free(list);
}

void printTlist(tlist_t* list) {
    tlnode_t* curr = list->head;
    printf("[");
    while (curr != NULL) {
        printf("%d", *((int*)curr->data));
        //printf("%p", curr->data);
        curr = curr->next;
        if (curr != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

void printBst2(tnode_t* curr, int l) {
    for (int i = 0; i < l; i++) {
        printf("-");
    }
    if (curr != NULL) {
        printf("%d\n", *((int*)curr->data));
        //printf("%p\n", curr->data);
        printBst2(curr->left, l+1);
        printBst2(curr->right, l+1);
    } else {
        printf("\n");
    }
}
void printBst(bst_t* bst) {
    printBst2(bst->root, 0);
}

int intcompar(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

int main() {
    bst_t bst;
    bst.root = NULL;
    bst.size = 0;
    bst.compar = intcompar;
    int a = 5;
    int b = 7;
    int c = 4;
    bstAppend(&bst, &a);
    bstAppend(&bst, &b);
    bstAppend(&bst, &c);
    bstRemove(&bst, &a);
    printBst(&bst);
    tlist_t* list = bstInorder(&bst);
    printf("add (5,7,4) remove(5) ");
    printTlist(list);
    printf("\n");

    printf("clear list: ");
    bstClear(&bst);
    list = bstInorder(&bst);
    printTlist(list);
    printf("\n");

    bstFreeList(list);
    printf("done\n\n");
}

/* todo:
printlist
printtree


*/