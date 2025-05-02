#pragma once

#include "common.h"
#include "value.h"

namespace lox {
    enum OpCode {
        OP_RETURN,
        OP_CONSTANT,
    };

    class Chunk : public std::vector<uint8_t> {
    public:
        ValueArray constants;
        std::vector<size_t> lines;

        void disassemble(std::string name) const;

        size_t addConstant(Value value);

        void write(uint8_t byte, size_t line);
    };
}
