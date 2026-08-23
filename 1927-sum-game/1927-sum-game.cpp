class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftQ = 0, rightQ = 0;
        int leftSum = 0, rightSum = 0;
        for(int i = 0 ; i < n/2; i++){
            if(num[i] == '?'){
                leftQ++;
            }else{
                leftSum += num[i]-'0';
            }
        }
        for(int i = n/2 ; i < n; i++){
            if(num[i] == '?'){
                rightQ++;
            }else{
                rightSum += num[i]-'0';
            }
        }
        int totalQ = leftQ + rightQ;
        int diffSum = leftSum - rightSum;
        int diffQ = leftQ - rightQ;
        if(totalQ % 2 != 0){
            return true;
        }
        if(diffSum + (diffQ * 9) / 2 != 0){
            return true;
        }
        return false;
    }
};