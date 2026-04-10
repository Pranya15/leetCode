class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid; // peak found
            }
            else if (arr[mid] < arr[mid + 1]) {
                st = mid + 1; // go right (increasing slope)
            } 
            else {
                end = mid - 1; // go left (decreasing slope)
            }
        }
        return -1;
    }
};