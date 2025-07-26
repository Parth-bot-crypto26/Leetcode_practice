class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int count = 0;
        int length = flowerbed.size();

        for (int i = 0; i < length; ++i) {
            if (flowerbed[i] == 0) {
                bool left_empty = (i == 0) || (flowerbed[i - 1] == 0);
                bool right_empty = (i == length - 1) || (flowerbed[i + 1] == 0);

                if (left_empty && right_empty) {
                    flowerbed[i] = 1; // Plant a flower
                    count++;
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }

        return count >= n;
    }
};