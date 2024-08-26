class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        // Temporary arrays
        vector<int> a(n1);
        vector<int> b(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) {
            a[i] = nums[l + i];
        }
        for (int i = 0; i < n2; i++) {
            b[i] = nums[mid + 1 + i];
        }

        int i = 0; // Initial index of first subarray
        int j = 0; // Initial index of second subarray
        int k = l; // Initial index of merged subarray

        // Merge the temp arrays back into nums[l..r]
        while (i < n1 && j < n2) {
            if (a[i] <= b[j]) {
                nums[k] = a[i];
                i++;
            } else {
                nums[k] = b[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of a[], if any
        while (i < n1) {
            nums[k] = a[i];
            i++;
            k++;
        }

        // Copy the remaining elements of b[], if any
        while (j < n2) {
            nums[k] = b[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(nums, l, mid);
            mergeSort(nums, mid + 1, r);

            // Merge the sorted halves
            merge(nums, l, mid, r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
