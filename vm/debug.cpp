#include "debug.h"
#include "chunk.h"

using namespace lox;

void lox::printValue(const Value value) {
    std::cout << value;
}

size_t lox::simpleInstruction(const std::string &name, size_t offset) {
    std::cout << name << std::endl;
    return offset + 1;
}

size_t lox::constantInstruction(const std::string &name, const Chunk &chunk, const size_t offset) {
    const uint8_t constant = chunk[offset + 1];
    std::cout << std::format("{:<16} {:4} '", name, constant);
    printValue(chunk.constants[constant]);
    std::cout << "'\n";
    return offset + 2;
}

size_t lox::disassembleInstruction(const Chunk &chunk, size_t offset) {
    std::cout << std::format("{:04d} ", offset);
    if (offset > 0 &&
        chunk.lines[offset] == chunk.lines[offset - 1]) {
        std::cout << "   | ";
    } else {
        std::cout << std::format("{:4} ", chunk.lines[offset]);
    }
    switch (const uint8_t instruction = chunk[offset]) {
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            std::cout << std::format("Unknown opcode {}\n", instruction);
            return offset + 1;
    }
}
