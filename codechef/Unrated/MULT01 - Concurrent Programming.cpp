import java.util.*;

class SegmentWorker extends Thread {
    private int[] arr;
    private int start;
    private int end;
    private int sum;

    public SegmentWorker(int[] arr, int start, int end) {
        this.arr = arr;
        this.start = start;
        this.end = end;
        this.sum = 0;
    }

    @Override
    public void run() {
        for (int i = start; i < end; i++) {
            sum += arr[i];
        }
    }

    public int getSum() {
        return sum;
    }
}

class Codechef {

    public static void processArrayAndPrintResults(int[] arr) throws InterruptedException {
        // TODO: Create worker threads for three segments: [0,3), [3,6), [6,9)

        // TODO: Start all worker threads
        
        // TODO: Wait for all threads to complete using join()
        
        // TODO: Get segment sums from workers and calculate total sum
        
        // TODO: Print the output in the required format
        // Create worker threads
SegmentWorker worker0 = new SegmentWorker(arr, 0, 3);
SegmentWorker worker1 = new SegmentWorker(arr, 3, 6);
SegmentWorker worker2 = new SegmentWorker(arr, 6, 9);

// Start all worker threads
worker0.start();
worker1.start();
worker2.start();

// Wait for all threads to complete
worker0.join();
worker1.join();
worker2.join();

// Get segment sums
int sum0 = worker0.getSum();
int sum1 = worker1.getSum();
int sum2 = worker2.getSum();

// Calculate total sum
int totalSum = sum0 + sum1 + sum2;

// Print results
System.out.println("Segment 0 Sum: " + sum0);
System.out.println("Segment 1 Sum: " + sum1);
System.out.println("Segment 2 Sum: " + sum2);
System.out.println("Total Sum: " + totalSum);
        
    }

public static void main(String[] args) throws InterruptedException {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[9];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }

        // Execution delegated to the helper function
        processArrayAndPrintResults(arr);

        sc.close();
    }
}