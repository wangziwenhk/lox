package dev.wangziwenhk.rox.token;

public class OperatorToken extends Token {
    private String operator;
    private Token leftToken;
    private Token rightToken;

    OperatorToken(Token left, Token right, String operator) {
        super();
        this.operator = operator;
        this.leftToken = left;
        this.rightToken = right;
    }

    public Token getLeftToken() {
        return leftToken;
    }

    public String getOperator() {
        return operator;
    }

    public Token getRightToken() {
        return rightToken;
    }

    public void setLeftToken(Token leftToken) {
        this.leftToken = leftToken;
    }

    public void setOperator(String operator) {
        this.operator = operator;
    }

    public void setRightToken(Token rightToken) {
        this.rightToken = rightToken;
    }
}
