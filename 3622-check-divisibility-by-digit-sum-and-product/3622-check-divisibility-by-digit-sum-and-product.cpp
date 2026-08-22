class Solution {
public:
    int digitSum(int n){
        int temp = n;
        int sum = 0;
        while(temp > 0){
            int digit = temp%10;
            sum += digit;
            temp /= 10;
        }
        return sum;
    }
    int digitProd(int n){
        int temp = n;
        int prod = 1;
        while(temp > 0){
            int digit = temp%10;
            prod *= digit;
            temp /= 10;
        }
        return prod;
    }
    bool checkDivisibility(int n) {
        int total = digitSum(n) + digitProd(n);
        return total != 0 && n % total == 0;
    }
};