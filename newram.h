#ifndef INCLUDE
#define INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>

#define BYTE_SIZE 8
#define BLOCK_SIZE 8
#define BLOCK_NUMBER 136
#define BLOCK_NUMBER_2 4
#define RAM_SIZE 8704

char RAM[BLOCK_NUMBER][BLOCK_SIZE][BYTE_SIZE];
char bucket[BLOCK_NUMBER_2][BLOCK_SIZE][BYTE_SIZE];

// minimum and maximum index that data of a specific data type can occupy
#define MIN_C 0
#define MAX_C 2559
#define MIN_F 2560
#define MAX_F 4607
#define MIN_INT 4608
#define MAX_INT 6655
#define MIN_B 6656
#define MAX_B 7679
#define MIN_W_STORAGE 7680
#define MAX_W_STORAGE 8191
#define MIN_RST_STORAGE 8192
#define MAX_RST_STORAGE 8703

// the amount of blocks allocated to each type
#define LONG_BNUM 8
#define INT_BNUM 8
#define UINT_BNUM 8
#define ULONG_BNUM 8
#define WCHAR_BNUM 25
#define CHAR_BNUM 15
#define FLOAT_BNUM 16
#define DOUBLE_BNUM 16
#define BOOL_BNUM 4
#define BARR_BNUM 12

// value before address as well as the amount of block available to the user
#define INITIAL_HEX "0x"
#define USR_BLOCKS 128
#define MAX_BIT_SIZE 7

//functions used in newram.c
void allocMem(int);
bool reProc(int, int, int);
void printAddress(int, int, int);
int checkAddress(int, int, int, int);

//functions used in control.c
bool alloc(int, char**);
int dumpData(void);

// largest 1 digit number in hexadecimal base
#define SINGLE_DIGIT_LIMIT 15

#endif // INCLUDE
