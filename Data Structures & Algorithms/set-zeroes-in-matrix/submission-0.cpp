class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>>coords;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    coords.push_back({i, j});
                }
            }
        }
        for (auto& [i,j] : coords){
            for(int p = 0; p < matrix.size(); p++ ){
                matrix[p][j] = 0;
            }
            for(int p = 0; p < matrix[0].size(); p++ ){
                matrix[i][p] = 0;
            }
        }
    }
};
