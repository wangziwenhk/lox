package dev.wangziwenhk.lox;

class AstPrinter implements Expr.Visitor<String> {
    String print(Expr expr) {
        return expr.accept(this);
    }

    @Override
    public String visitBinaryExpr(Expr.Binary expr) {
        return parenthesize(expr.operator.lexeme,
                expr.left, expr.right);
    }

    @Override
    public String visitGroupingExpr(Expr.Grouping expr) {
        return parenthesize("group", expr.expression);
    }

    @Override
    public String visitLiteralExpr(Expr.Literal expr) {
        if (expr.value == null) return "nil";
        return expr.value.toString();
    }

    @Override
    public String visitUnaryExpr(Expr.Unary expr) {
        return parenthesize(expr.operator.lexeme, expr.right);
    }

    /**
     * Wraps the given name and expressions into a parenthesized string representation.
     * Each expression is visited and its string representation is appended to the result.
     *
     * @param name  the name or operator to be placed at the beginning of the parenthesized expression
     * @param exprs a variable number of expressions to be included in the parenthesized structure
     * @return a string representing the parenthesized expression, including the name and evaluated expressions
     */
    private String parenthesize(String name, Expr... exprs) {
        StringBuilder builder = new StringBuilder();

        builder.append("(").append(name);
        for (Expr expr : exprs) {
            builder.append(" ");
            builder.append(expr.accept(this));
        }
        builder.append(")");

        return builder.toString();
    }

    public static void main(String[] args) {
        Expr expression = new Expr.Logical(new Expr.Literal(1), new Token(TokenType.AND, "", null, 0), new Expr.Literal(1));

        System.out.println(new AstPrinter().print(expression));
    }

    @Override
    public String visitVariableExpr(Expr.Variable expr) {
        return expr.name.toString();
    }

    @Override
    public String visitAssignExpr(Expr.Assign expr) {
        return parenthesize("=", expr);
    }

    @Override
    public String visitLogicalExpr(Expr.Logical expr) {
        return parenthesize(expr.operator.toString(), expr.left, expr.right);
    }

    @Override
    public String visitCallExpr(Expr.Call expr) {
        return "";
    }

    @Override
    public String visitGetExpr(Expr.Get expr) {
        return "";
    }

    @Override
    public String visitSetExpr(Expr.Set expr) {
        return "";
    }

    @Override
    public String visitThisExpr(Expr.This expr) {
        return "";
    }

    @Override
    public String visitSuperExpr(Expr.Super expr) {
        return "";
    }
}