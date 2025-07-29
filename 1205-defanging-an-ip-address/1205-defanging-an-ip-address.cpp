class Solution {
public:
    string defangIPaddr(string address) {
        string defangedAddress = "";
        for(char c : address){
            if(c == '.'){
                defangedAddress += "[.]";
            }
            else{
                defangedAddress += c;
            }
        }
        return defangedAddress;
    }
};