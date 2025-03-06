package dev.wangziwenhk.lox;

class Int extends Value {
    private int value;

    public Int() {
        this.value = 0;
    }

    public Int(int value) {
        this.value = value;
    }

    @Override
    public Integer getValue() {
        return this.value;
    }
}