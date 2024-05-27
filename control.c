#include "newram.h"

// Function to store commands in the reserved memory region
void storeCommand(const char* command) {
    int commandLength = strlen(command);
    if (commandLength > (MAX_RST_STORAGE - MIN_RST_STORAGE + 1)) {
        printf("Command too long to store in reserved memory\n");
        return;
    }

    for (int i = 0; i < commandLength; i++) {
        RAM[MIN_RST_STORAGE + i / (BLOCK_SIZE * BYTE_SIZE)]
           [(i / BYTE_SIZE) % BLOCK_SIZE]
           [i % BYTE_SIZE] = command[i];
    }

    printf("Command stored: %s\n", command);
}

// Function to parse and execute commands from the reserved memory region
void parseAndExecuteCommands() {
    char commandBuffer[MAX_RST_STORAGE - MIN_RST_STORAGE + 1] = {0};
    int index = 0;

    for (int i = MIN_RST_STORAGE; i <= MAX_RST_STORAGE; i++) {
        commandBuffer[index++] = RAM[i / (BLOCK_SIZE * BYTE_SIZE)]
                                  [(i / BYTE_SIZE) % BLOCK_SIZE]
                                  [i % BYTE_SIZE];
    }

    // Parsing the command and executing corresponding functions
    if (strstr(commandBuffer, "i_32")) {
        printf("Command 'i_32' found, performing int allocation\n");
        // Add corresponding function for int allocation here
    }
    if (strstr(commandBuffer, "pop[all]")) {
        printf("Command 'pop[all]' found, performing memory deallocation\n");
        // Add corresponding function for memory deallocation here
    }
    // Add more command checks as needed
}

// Allocate function
bool alloc(int numArgs, char **args) {
    if (numArgs < 2) {
        printf("Insufficient arguments\n");
        return false;
    }

    if (strcmp(args[1], "i_32") == 0) {
        storeCommand("i_32");
    } else if (strcmp(args[1], "pop[all]") == 0) {
        storeCommand("pop[all]");
    } else {
        printf("Unknown command: %s\n", args[1]);
        return false;
    }

    parseAndExecuteCommands();
    return true;
}

// Function to dump data from RAM
int dumpData() {
    // Print the contents of the RAM
    printf("RAM contents:\n");
    for (int i = 0; i < BLOCK_NUMBER; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            for (int k = 0; k < BYTE_SIZE; k++) {
                printf("%c", RAM[i][j][k]);
            }
        }
    }
    printf("\n");

    return 0;
}

// Main function
int main() {
    char *args1[] = {"program", "i_32"};
    alloc(2, args1);

    char *args2[] = {"program", "pop[all]"};
    alloc(2, args2);

    dumpData();
    return 0;
}