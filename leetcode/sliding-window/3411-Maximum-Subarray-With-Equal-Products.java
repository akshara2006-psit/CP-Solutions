
class Solution {

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public int maxLength(int[] nums) {

        int n = nums.length;
        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                // Length 1 or 2 is always valid
                if (j - i + 1 <= 2) {
                    ans = Math.max(ans, j - i + 1);
                    continue;
                }

                boolean valid = true;

                // Check every pair in the subarray
                for (int p = i; p <= j; p++) {

                    for (int q = p + 1; q <= j; q++) {

                        if (gcd(nums[p], nums[q]) != 1) {
                            valid = false;
                            break;
                        }
                    }

                    if (!valid)
                        break;
                }

                if (valid) {
                    ans = Math.max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
}
