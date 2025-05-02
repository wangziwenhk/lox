#include "chunk.h"
#include "common.h"

int main(int argc, const char *argv[]) {
    lox::Chunk chunk;
    const auto constant = chunk.addConstant(1.2);
    chunk.write(lox::OP_CONSTANT, 123);
    chunk.write(constant, 123);
    chunk.write(lox::OP_RETURN, 123);
    chunk.disassemble("name");
    return 0;
}
