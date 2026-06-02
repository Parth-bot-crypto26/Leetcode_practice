class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = 1e9;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStart = max(landFinish, waterStartTime[j]);
                int finishScenario1 = waterStart + waterDuration[j];
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStart = max(waterFinish, landStartTime[i]);
                int finishScenario2 = landStart + landDuration[i];
                minFinishTime = min({minFinishTime, finishScenario1, finishScenario2});
            }
        }
        return minFinishTime;
    }
};