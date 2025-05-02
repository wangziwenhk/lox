#pragma once

#include "chunk.h"
#define STACK_MAX 256

namespace lox {
    typedef enum {
        INTERPRET_OK,
        INTERPRET_COMPILE_ERROR,
        INTERPRET_RUNTIME_ERROR
    } InterpretResult;

    class VM {
    public:
        std::vector<Chunk> chunks;

        uint8_t *ip = nullptr;

        Value stack[STACK_MAX]{};
        Value* stackTop;

        VM();

        InterpretResult interpret();
        InterpretResult run();
        void push(Value value);
        Value pop();
    };


}
