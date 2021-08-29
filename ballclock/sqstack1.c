#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"

sqstack * stack_create(int len)
{
	sqstack *s;

	if((s = (sqstack *)malloc(sizeof(sqstack)))==NULL)
	{
		printf("malloc sqstack failed!\n");
		return NULL;
	}

	if((s->data)
}
