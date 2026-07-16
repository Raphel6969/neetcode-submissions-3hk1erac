class Solution {
public:

    int sqSum(int n){
        int sum = 0;
        while(n){
            int digit = n%10;
            sum += digit*digit;
            n /= 10;
        }

        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int, int> m;
        int x = 0;
        while(true){
            x = sqSum(n);
            if(x == 1){
                return true;
            }
            if(m.count(x)){
                return false;
            }
            m[x]++;
            n = x;
        }
    }
};
