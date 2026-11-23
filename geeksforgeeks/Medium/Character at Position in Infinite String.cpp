
class Solution {
    public char posInfinite(String s, int pos) {

        ArrayList<Long> lengths = new ArrayList<>();

        lengths.add((long) s.length());

        int step = 1;

        // Step 1: Calculate lengths
        while (lengths.get(lengths.size() - 1) < pos) {

            long prev = lengths.get(lengths.size() - 1);

            long curr = 2 * prev + step;

            lengths.add(curr);

            step++;
        }

        // Step 2: Move backwards
        long p = pos;

        for (int i = lengths.size() - 1; i >= 1; i--) {

            long prevLen = lengths.get(i - 1);

            int dollars = i;

            // Position lies in the middle part
            if (p > prevLen && p <= prevLen + dollars) {
                return '$';
            }

            // Position lies in the reversed part
            else if (p > prevLen + dollars) {

                p = 2 * prevLen + dollars - p + 1;
            }

            // Otherwise, position is already in the first part
        }

        // Step 3: Get character from original string
        return s.charAt((int) p - 1);
    }
}
