#include "chunk.h"
#include "debug.h"
using namespace lox;

void Chunk::disassemble(std::string name) const {
    std::cout << std::format("== {} ==\n", name);

    for (size_t i = 0; i < this->size();) {
        i = disassembleInstruction(*this, i);
    }
}

size_t Chunk::addConstant(const Value value) {
    this->constants.push_back(value);
    return this->constants.size() - 1;
}

void Chunk::write(const uint8_t byte, const size_t line) {
    this->push_back(byte);
    this->lines.push_back(line);
}
