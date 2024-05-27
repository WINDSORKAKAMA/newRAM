#include "newram.h"

void allocMem(int index) {
    if (index >= MIN_C && index <= MAX_C) {
        printf("Character and String Region\n");
    } else if (index >= MIN_F && index <= MAX_F) {
        printf("Fractions, Single and Double Floating Point Region\n");
    } else if (index >= MIN_INT && index <= MAX_INT) {
        printf("Integer Region\n");
    } else if (index >= MIN_W_STORAGE && index <= MAX_W_STORAGE) {
        printf("Working RAM Storage\n");
    } else if (index >= MIN_RST_STORAGE && index <= MAX_RST_STORAGE) {
        printf("Error! You don't have access to this area\n");
    } else {
        printf("You have a Memory Error!\n");
    }
}

bool reProc(int index1, int index2, int index3) {
    if (index3 >= USR_BLOCKS) {
        printf("Buffer Overflow!\n");
        return false;
    } else {
        if (index3 == (BYTE_SIZE - 1)) {
            index3 = 0;
            index2++;
        } else if (index2 == (BLOCK_SIZE - 1)) {
            index2 = 0;
            index1++;
        } else if (index1 == (BLOCK_NUMBER - 1)) {
            index3 = 0;
            index2++;
        } else {
            return false;
        }
        return true;
    }
}

void printAddress(int index1, int index2, int index3) {
    if (index3 < BYTE_SIZE) {
        printf("%s0%d\n", INITIAL_HEX, index1);
    } else if (index2 < BLOCK_SIZE) {
        printf("%s0%x\n", INITIAL_HEX, index2);
    } else if (index1 < BLOCK_NUMBER) {
        if (index3 <= SINGLE_DIGIT_LIMIT) {
            printf("%s00%x\n", INITIAL_HEX, index3);
        } else {
            printf("%s0%x\n", INITIAL_HEX, index3);
        }
    } else {
        printf("Error! Check memory\n");
    }
}

int checkAddress(int index1, int index2, int index3, int limit) {
    index1 = 0;
    index2 = 0;
    index3 = 0;
    while (index1 < BLOCK_NUMBER_2) {
        if (index1 < (BLOCK_NUMBER_2 - limit)) {
            while (index2 < BLOCK_SIZE) {
                while (index3 < BYTE_SIZE) {
                    printAddress(index1, index2, index3);
                    index3++;
                }
                index2++;
            }
        }
        index1++;
    }
    return 0;
}#include "newram.h"

void allocMem(int index) {
    if (index >= MIN_C && index <= MAX_C) {
        printf("Character and String Region\n");
    } else if (index >= MIN_F && index <= MAX_F) {
        printf("Fractions, Single and Double Floating Point Region\n");
    } else if (index >= MIN_INT && index <= MAX_INT) {
        printf("Integer Region\n");
    } else if (index >= MIN_W_STORAGE && index <= MAX_W_STORAGE) {
        printf("Working RAM Storage\n");
    } else if (index >= MIN_RST_STORAGE && index <= MAX_RST_STORAGE) {
        printf("Error! You don't have access to this area\n");
    } else {
        printf("You have a Memory Error!\n");
    }
}

bool reProc(int index1, int index2, int index3) {
    if (index3 >= USR_BLOCKS) {
        printf("Buffer Overflow!\n");
        return false;
    } else {
        if (index3 == (BYTE_SIZE - 1)) {
            index3 = 0;
            index2++;
        } else if (index2 == (BLOCK_SIZE - 1)) {
            index2 = 0;
            index1++;
        } else if (index1 == (BLOCK_NUMBER - 1)) {
            index3 = 0;
            index2++;
        } else {
            return false;
        }
        return true;
    }
}

void printAddress(int index1, int index2, int index3) {
    if (index3 < BYTE_SIZE) {
        printf("%s0%d\n", INITIAL_HEX, index1);
    } else if (index2 < BLOCK_SIZE) {
        printf("%s0%x\n", INITIAL_HEX, index2);
    } else if (index1 < BLOCK_NUMBER) {
        if (index3 <= SINGLE_DIGIT_LIMIT) {
            printf("%s00%x\n", INITIAL_HEX, index3);
        } else {
            printf("%s0%x\n", INITIAL_HEX, index3);
        }
    } else {
        printf("Error! Check memory\n");
    }
}

int checkAddress(int index1, int index2, int index3, int limit) {
    index1 = 0;
    index2 = 0;
    index3 = 0;
    while (index1 < BLOCK_NUMBER_2) {
        if (index1 < (BLOCK_NUMBER_2 - limit)) {
            while (index2 < BLOCK_SIZE) {
                while (index3 < BYTE_SIZE) {
                    printAddress(index1, index2, index3);
                    index3++;
                }
                index2++;
            }
        }
        index1++;
    }
    return 0;
}