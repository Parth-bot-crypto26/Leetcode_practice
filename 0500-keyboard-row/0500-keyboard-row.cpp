#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
        unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
        unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

        vector<string> result;
        for (const string& word : words) {
            if (word.empty()) {
                continue;
            }
            bool isOneRowWord = true;
            unordered_set<char>* targetRow = nullptr;
            if (row1.count(word[0])) {
                targetRow = &row1;
            } else if (row2.count(word[0])) {
                targetRow = &row2;
            } else if (row3.count(word[0])) {
                targetRow = &row3;
            }

            for (char c : word) {
                if (targetRow && targetRow->find(c) == targetRow->end()) {
                    isOneRowWord = false;
                    break;
                }
            }
            if (isOneRowWord) {
                result.push_back(word);
            }
        }

        return result;
    }
};
