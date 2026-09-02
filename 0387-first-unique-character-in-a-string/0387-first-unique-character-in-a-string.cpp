class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        queue<int> q;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) == mp.end()){
                q.push(i);
            }
            mp[s[i]]++;
            while(q.size() > 0 && mp[s[q.front()]] > 1){
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};