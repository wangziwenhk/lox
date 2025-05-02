#pragma once

#include "common.h"
#include "value.h"

namespace lox {
    class Chunk;

    static size_t simpleInstruction(const std::string &name, size_t offset);
    static size_t constantInstruction(const std::string &name, const Chunk &chunk, size_t offset);
    size_t disassembleInstruction(const Chunk &chunk, size_t offset);

    void printValue(Value value);
}