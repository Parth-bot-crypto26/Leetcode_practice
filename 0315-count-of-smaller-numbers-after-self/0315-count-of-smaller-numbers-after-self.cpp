class Solution {
    void merge(vector<pair<int, int>>& arr, int left, int mid, int right, vector<int>& count){
        vector<pair<int, int>> temp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;
        int rightLess = 0;
        while(i <= mid && j <= right){
            if(arr[j].first < arr[i].first){
                rightLess++;
                temp[k++] = arr[j++];
            }else{
                count[arr[i].second] += rightLess;
                temp[k++] = arr[i++];
            }
        }
        while(i <= mid){
            count[arr[i].second] += rightLess;
            temp[k++] = arr[i++];
        }
        while(j <= right){
            temp[k++] = arr[j++];
        }
        for(int p = 0; p < temp.size(); p++){
            arr[left+p] = temp[p];
        }
    }
    void mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& count){
        if(left >= right) return;
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid+1, right, count);
        merge(arr, left, mid, right, count);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = {nums[i], i};
        }
        mergeSort(arr, 0, n-1, count);
        return count;
    }
};