package dev.wangziwenhk.rox;

public class Float extends Value {
    private double value;

    public Float() {
        this.value = 0;
    }

    public Float(float value) {
        this.value = value;
    }

    @Override
    public Object getValue() {
        return this.value;
    }
}