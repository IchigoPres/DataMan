#include <stdio.h>
#include <stdlib.h>

#define DATA8 0
#define UDATA8 1
#define DATA16 2
#define UDATA16 3
#define DATA32 4
#define UDATA32 5
#define DATA64 6
#define UDATA64 7
#define STRDATA 8

typedef struct {
	char val8;
	unsigned char uval8;
	short val16;
	unsigned short uval16;
	int val32;
	unsigned int uval32;
	long val64;
	unsigned long uval64;
	unsigned char* str;
	int type;
} dataTypes_t;

typedef struct {
	dataTypes_t* array;
	unsigned long length;
} arrayDataTypes_t;

arrayDataTypes_t createArray() {
	arrayDataTypes_t result;
	result.array = (dataTypes_t*)malloc(sizeof(dataTypes_t));
	result.length = 0;
	return result;
}
