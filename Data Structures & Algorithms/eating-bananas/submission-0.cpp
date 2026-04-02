class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int mid){
        int ans  = 0;
        for(int i = 0; i < piles.size(); i++){
            ans += ceil((double)piles[i] / mid);
            if(ans > h){
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int mid = s + (e-s)/2;
        int ans = -1;

        while(s <= e){
            if(isPossible(piles, h,mid)){
                ans = mid;
                e = mid -1;
            }else{
                s = mid + 1;
            }

            mid = s + (e-s)/2;
        }

        return ans;
    }
};
