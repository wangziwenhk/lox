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
    public java.lang.Double getValue() {
        return this.value;
    }
}