
typedef struct node {
        int val;
        int ref, ref2;
        struct node *next;
}node;
node *head, *tail;
int size_of_frame;
int tot_pages;
int cnt_of_page_fault;
void init(void);
void fifo(int *, int);
void optimal(int *, int);
void lru(int *, int);
void lfu(int *, int);
void mfu(int *, int);
void second_chance(int *, int);
void enhanced_second_chance(int *, int, int);
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
