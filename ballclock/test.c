#include <stdio.h>
#include "linkqueue.h"
#include "sqstack.h"

int check(linkqueue * lq);

int main(int argc, const char *argv[])
{
	linkqueue *lq;
	sqstack *s_hour, *s_five, *s_min;
	int value;
	int i, min = 0;

	if ((lq = queue_create()) == NULL) {
		return -1;
	}

	for (i = 1; i <= 27; i++) {
		enqueue(lq, i);
	}

	if ((s_hour = stack_create(11)) == NULL) {
		return -1;
	}

	if ((s_five = stack_create(11)) == NULL) {
		return -1;
	}

	if ((s_min = stack_create(4)) == NULL) {
		return -1;
	}

	while (1) {
		min++;
		if (!queue_empty(lq)) {
			value = dequeue(lq);
			if (!stack_full(s_min)) {
				stack_push(s_min, value);
			} else {
				while (!stack_empty(s_min)) {
					enqueue(lq, stack_pop(s_min));
				}
				if (!stack_full(s_five)) {
					stack_push(s_five, value);
				} else {
					while (!stack_empty(s_five)) {
						enqueue(lq, stack_pop(s_five));
					}
					if (!stack_full(s_hour)) {
						stack_push(s_hour, value);
					} else {
						while (!stack_empty(s_hour)) {
							enqueue(lq, stack_pop(s_hour));
						}
						enqueue(lq, value);
						//0:0
						if (check(lq) == 1) {
							break;
						}
					}
				}

			}
		}
	}
	printf("total:%d\n", min);

	printf("dequeue:");
	while (!queue_empty(lq)) 
		printf("%d ", dequeue(lq));
	
	puts("");

	return 0;
}

int check(linkqueue * lq) {
	linklist p;

	if (lq == NULL) {
		printf("lq is NULL\n");
		return -1;
	}

	p = lq->front->next;

	while (p && p->next) {
		if (p->data < p->next->data) {
			p = p->next;
		} else {
			return 0;
		}
	}
	return 1;
}
