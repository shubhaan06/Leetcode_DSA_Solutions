class Solution {
public:
string fractionAddition(std::string expression) {
        std::istringstream iss(preprocessExpression(expression));
        int numerator = 0, denominator = 1;
        char op;
        while (iss >> op) {
            int num, denom;
            char slash;
            iss >> num >> slash >> denom;

            if (op == '-') num = -num;

            // Calculate LCM of denominators
            int lcm = std::lcm(denominator, denom);

            // Adjust numerators
            numerator = numerator * (lcm / denominator) + num * (lcm / denom);
            denominator = lcm;

            // Simplify the fraction
            int gcd = std::gcd(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;
        }

        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

private:
    std::string preprocessExpression(const std::string& expression) {
        std::string exp = expression;
        if (exp[0] != '+' && exp[0] != '-') {
            exp = "+" + exp;
        }
        std::string result;
        for (size_t i = 0; i < exp.size(); ++i) {
            if (exp[i] == '+' || exp[i] == '-') {
                result += ' ';
                result += exp[i];
            } else {
                result += exp[i];
            }
        }
        return result;
    }
};