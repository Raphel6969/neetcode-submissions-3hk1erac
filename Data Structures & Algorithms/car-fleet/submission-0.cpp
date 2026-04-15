class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float, float>> arr;

        for(int i = 0; i < speed.size(); i++){
            arr.push_back({position[i], speed[i]});
        }

        sort(arr.begin(), arr.end());

        stack<float> time;

        for(auto p: arr){
            time.push(((float)target - p.first)/p.second);
        }

        int fleets = 0;
        float last = 0;
        while(!time.empty()){
            float curr = time.top();
            if(curr > last){
                fleets++;
                last = curr;
            }
            time.pop();
        }
        

        return fleets;


    }
};
