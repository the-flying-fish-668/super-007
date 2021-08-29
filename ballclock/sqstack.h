typedef int data_t;

typedef struct {
	data_t *data;
	int maxlen;
	int top;
}sqstack;

sqstack * stack_create(int len);
int stack_push(sqstack * s, data_t value);
int stack_empty(sqstack *s);
int stack_full(sqstack *s);
data_t stack_pop(sqstack *s);
data_t stack_top(sqstack *s);
int stack_clear(sqstack *s);
int stack_free(sqstack *s);
