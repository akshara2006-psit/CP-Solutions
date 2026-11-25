

class Solution {

    static final long MOD = 1_000_000_007L;

    // Calculates the earliest normal travel time to reach x
    private long travelTime(long x, long a, long b) {

        long p = a - b;
        long q = 0;

        if (x > a) {
            q = (x - a + p - 1) / p;
        }

        return x + 2L * b * q;
    }

    // Calculates prefix sum of q(x) from 1 to n
    private long prefixQ(long n, long a, long p) {

        long m = n - a;

        if (m <= 0) {
            return 0;
        }

        long k = m / p;
        long rem = m % p;

        return p * k * (k + 1) / 2
                + rem * (k + 1);
    }

    // Sum of (travelTime(x) + 1) from L to R
    private long rangeSum(long L, long R,
                          long a, long b) {

        if (L > R) {
            return 0;
        }

        long p = a - b;
        long count = R - L + 1;

        // Sum of x
        long sumX = (L + R) * count / 2;

        // Sum of q(x)
        long sumQ = prefixQ(R, a, p)
                  - prefixQ(L - 1, a, p);

        // Sum of T(x) + 1
        return sumX + 2L * b * sumQ + count;
    }

    public int minTime(int a, int b, int d, int l, int r) {

        long normalTime = travelTime(d, a, b);

        // Convert jump range into target-position range
        long L = (long) d - r;
        long R = (long) d - l;

        // Find largest x for which jump is strictly better
        long low = L;
        long high = R;
        long boundary = L - 1;

        while (low <= high) {

            long mid = low + (high - low) / 2;

            long jumpTime = travelTime(mid, a, b) + 1;

            if (jumpTime < normalTime) {
                boundary = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Sum jump-based minimum times
        long jumpSum = rangeSum(
                L, boundary, a, b
        );

        // Remaining positions use normal travel time
        long remaining = R - boundary;

        long normalSum = (remaining * normalTime) % MOD;

        return (int) ((jumpSum % MOD + normalSum) % MOD);
    }
}
