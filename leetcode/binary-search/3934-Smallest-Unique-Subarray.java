

class Solution {
       public int smallestUniqueSubarray(int[] nums) {

        int n = nums.length;

        // Step 1: Build suffix array
        int[] sa = buildSuffixArray(nums);

        // Step 2: Build rank array
        int[] rank = new int[n];

        for (int i = 0; i < n; i++) {
            rank[sa[i]] = i;
        }

        // Step 3: Build LCP array using Kasai's algorithm
        // lcp[i] = LCP of sa[i] and sa[i - 1]
        int[] lcp = new int[n];

        int common = 0;

        for (int i = 0; i < n; i++) {

            int r = rank[i];

            if (r == 0) {
                common = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + common < n &&
                   j + common < n &&
                   nums[i + common] == nums[j + common]) {
                common++;
            }

            lcp[r] = common;

            if (common > 0) {
                common--;
            }
        }

        // Step 4: Find the shortest unique subarray
        int answer = n;

        for (int i = 0; i < n; i++) {

            // Maximum common prefix with either neighbor
            int maxLCP = lcp[i];

            if (i + 1 < n) {
                maxLCP = Math.max(maxLCP, lcp[i + 1]);
            }

            // Shortest prefix not shared by another suffix
            int length = maxLCP + 1;

            // It must fit inside this suffix
            if (length <= n - sa[i]) {
                answer = Math.min(answer, length);
            }
        }

        return answer;
    }

    private int[] buildSuffixArray(int[] nums) {

        int n = nums.length;
        int N = n + 1;

        // Add a unique smallest sentinel (0)
        int[] s = new int[N];

        int maxValue = 0;

        for (int i = 0; i < n; i++) {
            s[i] = nums[i];
            maxValue = Math.max(maxValue, nums[i]);
        }

        s[n] = 0;

        // Initial counting sort
        int alphabet = Math.max(N, maxValue + 1);

        int[] p = new int[N];
        int[] c = new int[N];
        int[] cnt = new int[alphabet];

        for (int x : s) {
            cnt[x]++;
        }

        for (int i = 1; i < alphabet; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = N - 1; i >= 0; i--) {
            p[--cnt[s[i]]] = i;
        }

        // Assign equivalence classes
        int classes = 1;
        c[p[0]] = 0;

        for (int i = 1; i < N; i++) {

            if (s[p[i]] != s[p[i - 1]]) {
                classes++;
            }

            c[p[i]] = classes - 1;
        }

        int[] pn = new int[N];
        int[] cn = new int[N];

        // Doubling algorithm
        for (int len = 1; len < N; len *= 2) {

            // Shift suffix positions backwards
            for (int i = 0; i < N; i++) {
                pn[i] = p[i] - len;

                if (pn[i] < 0) {
                    pn[i] += N;
                }
            }

            // Counting sort by equivalence class
            Arrays.fill(cnt, 0, classes, 0);

            for (int i = 0; i < N; i++) {
                cnt[c[pn[i]]]++;
            }

            for (int i = 1; i < classes; i++) {
                cnt[i] += cnt[i - 1];
            }

            for (int i = N - 1; i >= 0; i--) {
                int x = pn[i];
                p[--cnt[c[x]]] = x;
            }

            // Recalculate equivalence classes
            cn[p[0]] = 0;
            int newClasses = 1;

            for (int i = 1; i < N; i++) {

                int cur = p[i];
                int prev = p[i - 1];

                int mid = (cur + len) % N;
                int midPrev = (prev + len) % N;

                if (c[cur] != c[prev] ||
                    c[mid] != c[midPrev]) {
                    newClasses++;
                }

                cn[cur] = newClasses - 1;
            }

            int[] temp = c;
            c = cn;
            cn = temp;

            classes = newClasses;

            if (classes == N) {
                break;
            }
        }

        // Remove the sentinel suffix
        int[] sa = new int[n];

        for (int i = 0; i < n; i++) {
            sa[i] = p[i + 1];
        }

        return sa;
    }
}
