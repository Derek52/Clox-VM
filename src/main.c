#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 17);
    writeChunk(&chunk, constant, 17);
    

    constant = addConstant(&chunk, 2.2);
    writeChunk(&chunk, OP_CONSTANT, 18);
    writeChunk(&chunk, constant, 18);
    writeChunk(&chunk, OP_ADD, 17);
     writeChunk(&chunk, OP_NEGATE, 18);

     writeChunk(&chunk, OP_RETURN, 19);

    disassembleChunk(&chunk, "test chunk");

    interpret(&chunk);

    freeVM();
    freeChunk(&chunk);
	return 0;
}
