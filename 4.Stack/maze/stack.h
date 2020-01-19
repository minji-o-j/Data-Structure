// ======================================================================

#define MAX_STACK_SIZE  12
#define ERROR           -2

// ======================================================================

typedef struct stack {
	int data[MAX_STACK_SIZE];
	int top;
} STACK;

// ======================================================================

void init_stack(STACK * s);
void print_stack(STACK * s);
int empty_stack(STACK * s);
int push_stack(STACK * s, int item);
int pop_stack(STACK * s);

// ======================================================================



