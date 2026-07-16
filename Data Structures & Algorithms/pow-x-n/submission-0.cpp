class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int nn = n;
        if(n < 0) n *= -1;
        while(n){
            if (n % 2 == 0){
                n = n / 2;
            x *= x;
            }else{
                n = n - 1;
                ans *= x;
            }
        }

        return (nn < 0 ? 1/ans : ans);
    }
};
