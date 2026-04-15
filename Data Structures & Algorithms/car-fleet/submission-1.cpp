class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float, float>> arr;

        for(int i = 0; i < speed.size(); i++){
            arr.push_back({position[i], speed[i]});
        }

        // sort(arr.begin(), arr.end());

        sort(arr.begin(), arr.end(), [](pair<float,float> a, pair<float,float> b) { return a.first > b.first; });

        vector<float> time;

        for(auto p: arr){
            time.push_back(((float)target - p.first)/p.second);
            if(time.size() >= 2 && time[time.size() - 2] >= time.back()){
                time.pop_back();
            }
        }

        // int fleets = 0;
        // float last = 0;
        // while(!time.empty()){
        //     float curr = time.top();
        //     if(curr > last){
        //         fleets++;
        //         last = curr;
        //     }
        //     time.pop();
        // }


        

        return time.size();

    }
};
