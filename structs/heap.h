
struct heap {
    char type;
    int maxsize;
    int size;
    void** items; //array of void pointers
    int (*compar)(const void *, const void*);
} heap_t;

void* pop(heap_t*);
void* add(heap_t*, void* data);