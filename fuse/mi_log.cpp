
#include "interface.h"
#include <stdio.h>

void mi_log(const char* msg) 
{
	FILE* f = fopen("~/log.log","a");
	fprintf(f, msg);
	fclose(f);
}