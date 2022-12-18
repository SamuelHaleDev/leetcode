    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }

        // nums = [1, 2, 3]
        // n = 3
        // k = ?
        // 1 = ?
        // k = 1 (TRUE k >= 0)
        // nums[1] = 2 < nums[2] = 3 (BREAK)
        // (FALSE k !< 0)
        // 1 = 2 1 > k (TRUE 2 is > 1)
        // (BREAK nums[1] > nums[K]
        // swap nums[1], nums[2] nums = [1,3,2]
        // reverse(0 + 1 + 1, 2) => reverse(2, 2) *Nothing changes*
        // return nums = [1, 3, 2]