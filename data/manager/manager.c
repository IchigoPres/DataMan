#include <stdio.h>
#include <stdlib.h>

#define Char 0
#define UnsignedChar 1
#define Short 2
#define UnsignedShort 3
#define Int 4
#define UnsignedInt 5
#define Long 6
#define UnsignedLong 7

char* dataType[] = {
	"char",
	"unsigned char",
	"short",
	"unsigned short",
	"int",
	"unsigned int",
	"long",
	"unsigned long"
};
typedef struct {
	char* list8;
	unsigned char* ulist8;
	short* list16;
	unsigned short* ulist16;
	int* list32;
	unsigned int* ulist32;
	long* list64;
	unsigned long* ulist64;
	int type;
	unsigned long length;
} dataTypesList_t;

dataTypesList_t createDataList(int type) {
	dataTypesList_t result;
	result.type = type;
	switch(type) {
		case Char:
			result.list8 = (char*) malloc(sizeof(char));
			result.length = 0;
			break;
		case UnsignedChar:
			result.ulist8 = (unsigned char*) malloc(sizeof(unsigned char));
			result.length = 0;
			break;
		case Short:
			result.list16 = (short*) malloc(sizeof(short));
			result.length = 0;
			break;
		case UnsignedShort:
			result.ulist16 = (unsigned short*) malloc(sizeof(unsigned short));
			result.length = 0;
			break;
		case Int:
			result.list32 = (int*) malloc(sizeof(int));
			result.length = 0;
			break;
		case UnsignedInt:
			result.ulist32 = (unsigned int*) malloc(sizeof(unsigned int));
			result.length = 0;
			break;
		case Long:
			result.list64 = (long*) malloc(sizeof(long));
			result.length = 0;
			break;
		case UnsignedLong:
			result.ulist64 = (unsigned long*) malloc(sizeof(unsigned long));
			result.length = 0;
			break;
		default:
			printf("data type not exist!\n");
			break;
	}
	return result;
}
void pushDataList(dataTypesList_t* data, void* val) {
	unsigned long length = data->length+1;
	switch(data->type) {
		case Char:
			data->list8 = (char*)realloc(data->list8, sizeof(char)*length);
			data->list8[data->length] = *((char*)val);
			data->length = length;
			break;
		case UnsignedChar:
			data->ulist8 = (unsigned char*)realloc(data->ulist8, sizeof(unsigned char)*length);
			data->ulist8[data->length] = *((unsigned char*)val);
			data->length = length;
			break;
		case Short:
			data->list16 = (short*)realloc(data->list16, sizeof(short)*length);
			data->list16[data->length] = *((short*)val);
			data->length = length;
			break;
		case UnsignedShort:
			data->ulist16 = (unsigned short*)realloc(data->ulist16, sizeof(unsigned short*)*length);
			data->ulist16[(*data).length] = *((unsigned short*)val);
			data->length = length;
			break;
		case Int:
			data->list32 = (int*)realloc(data->list32, sizeof(int)*length);
			data->list32[data->length] = *((int*)val);
			data->length = length;
			break;
		case UnsignedInt:
			data->ulist32 = (unsigned int*)realloc(data->ulist32, sizeof(unsigned int)*length);
			data->ulist32[data->length] = *((unsigned int*)val);
			data->length = length;
			break;
		case Long:
			data->list64 = (long*)realloc(data->list64, sizeof(long)*length);
			data->list64[data->length] = *((long*)val);
			data->length = length;
			break;
		case UnsignedLong:
			data->ulist64 = (unsigned long*)realloc(data->ulist64, sizeof(unsigned long)*length);
			data->ulist64[data->length] = *((unsigned long*)val);
			data->length = length;
			break;
		default:
			printf("data type not exist!!!\n");
			break;
	}
}
void printDataList(dataTypesList_t list) {
	switch(list.type) {
		case Char:
			printf("%s", list.list8);
			break;
		case UnsignedChar:
			printf("%s", list.ulist8);
			break;
		case Short:
			printf("[ ");
			for(unsigned long i = 0; i < list.length; i++) {
				if(i == list.length-1) {
					printf("%hd ", list.list16[i]);
				} else {
					printf("%hd, ", list.list16[i]);
				}
			}
			printf("]\n");
			break;
		case UnsignedShort:
			printf("[ ");
			for(unsigned long i = 0; i < list.length; i++) {
				if(i == list.length-1) {
					printf("%hu ", list.ulist16[i]);
				} else {
					printf("%hu, ", list.ulist16[i]);
				}
			}
			printf("]\n");
			break;
		case Int:
			printf("[ ");
			for(unsigned long i = 0; i < list.length; i++) {
				if(i == list.length-1) {
					printf("%d ", list.list32[i]);
				} else {
					printf("%d, ", list.list32[i]);
				}
			}
			printf("]\n");
			break;
		case UnsignedInt:
			printf("[ ");
			for(unsigned long i = 0; i < list.length; i++) {
				if(i == list.length-1) {
					printf("%u ", list.ulist32[i]);
				} else {
					printf("%u, ", list.ulist32[i]);
				}
			}
			printf("]\n");
			break;
		case Long:
			printf("[ ");
			for(unsigned long i = 0; i < list.length; i++) {
				if(i == list.length-1) {
					printf("%ld ", list.list64[i]);
				} else {
					printf("%ld, ", list.list64[i]);
				}
			}
			printf("]\n");
			break;
		case UnsignedLong:
			printf("[ ");
			for(unsigned long i = 0; i < list.length; i++) {
				if(i == list.length-1) {
					printf("%lu ", list.ulist64[i]);
				} else {
					printf("%lu, ", list.ulist64[i]);
				}
			}
			printf("]\n");
			break;
		default:
			printf("data type not exists faile to print.\n");
			break;
	}
}
void storeDataList(dataTypesList_t* list, void* ls, unsigned long length) {
	unsigned long index = 0;
	while(index < length) {
		pushDataList(list, (void*)&ls[index]);
		index += 1;
	}
}
void* at(dataTypesList_t list, unsigned long index) {
	void* result;
	if(index < list.length) {
		switch(list.type) {
			case Char:
				result = (void*)&list.list8[index];
				break;
			case UnsignedChar:
				result = (void*)&list.ulist8[index];
				break;
			case Short:
				result = (void*)&list.list16[index];
				break;
			case UnsignedShort:
				result = (void*)&list.ulist16[index];
				break;
			case Int:
				result = (void*)&list.list32[index];
				break;
			case UnsignedInt:
				result = (void*)&list.ulist32[index];
				break;
			case Long:
				result = (void*)&list.list64[index];
				break;
			case UnsignedLong:
				result = (void*)&list.ulist64[index];
				break;
		}
		return result;
	} else {
		printf("error: %p out of bounds.\n", &list);
		return NULL;
	}
}

