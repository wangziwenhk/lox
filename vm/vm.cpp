#include "vm.h"

#include "debug.h"

using namespace lox;

VM vm;


VM::VM(): stackTop(this->stack) {}

void VM::push(const Value value) {
    *this->stackTop = value;
    this->stackTop++;
}

Value VM::pop() {
    this->stackTop--;
    return *this->stackTop;
}

InterpretResult VM::interpret() {
    this->chunks = chunks;
    this->ip = &(*this->chunks.begin()->begin());
    return run();
}

InterpretResult VM::run() {
#define READ_BYTE() (*this->ip++)
#define READ_CONSTANT() (this->chunks.begin()->constants[READ_BYTE()])
    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
        std::cout << "          ";
        for (const Value* slot = vm.stack; slot < vm.stackTop; slot++) {
            std::cout << "[ ";
            printValue(*slot);
            std::cout << " ]";
        }
        std::cout << "\n";
        disassembleInstruction(*this->chunks.begin(),
                               static_cast<int>(this->ip - &(*this->chunks.begin()->begin())));
#endif
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                const Value constant = READ_CONSTANT();
                push(constant);
                break;
            }
            case OP_RETURN: {
                printValue(pop());
                printf("\n");
                return INTERPRET_OK;
            }
            default: break;
        }
    }
#undef READ_BYTE
#undef READ_CONSTANT
}
