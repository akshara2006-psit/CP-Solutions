import java.io.*;
import java.util.*;
import java.util.concurrent.*;

class ArrayProcessor
{
    private final long[] arr;
    private final int threadCount;

    ArrayProcessor(long[] arr, int threadCount)
    {
        this.arr = arr;
        this.threadCount = threadCount;
    }

   
public long[] process() throws Exception
{
    // Step 1: Create a fixed thread pool
    ExecutorService executor =
            Executors.newFixedThreadPool(threadCount);

    // Step 2: Store Future objects
    List<Future<long[]>> futures = new ArrayList<>();

    // Step 3: Create and submit one Callable per array element
    for (long x : arr)
    {
        Callable<long[]> task = () ->
        {
            long square = x * x;
            return new long[]{x, square};
        };

        futures.add(executor.submit(task));
    }

    // Step 4: Collect results
    long sum = 0;
    long squareSum = 0;

    try
    {
        for (Future<long[]> future : futures)
        {
            long[] result = future.get();

            sum += result[0];
            squareSum += result[1];
        }
    }
    finally
    {
        // Step 5: Shut down the executor
        executor.shutdown();
    }

    // Step 6: Return both results
    return new long[]{sum, squareSum};
}

}

public class Main
{
    public static void main(String[] args)
            throws Exception
    {
        BufferedReader br =
                new BufferedReader(
                        new InputStreamReader(System.in)
                );

        StringTokenizer st =
                new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        long[] arr = new long[n];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++)
        {
            arr[i] =
                    Long.parseLong(st.nextToken());
        }

        ArrayProcessor processor =
                new ArrayProcessor(arr, k);

        long[] result = processor.process();

        System.out.println(result[0]);
        System.out.println(result[1]);
    }
}