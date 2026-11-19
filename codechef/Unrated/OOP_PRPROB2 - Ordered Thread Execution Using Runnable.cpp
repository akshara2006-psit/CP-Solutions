import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class NumberTask implements Runnable
{
    private final int left;
    private final int right;
    private final int divisor;

    NumberTask(int left, int right, int divisor)
    {
        this.left = left;
        this.right = right;
        this.divisor = divisor;
    }

    @Override
    public void run()
    {
        // TODO:
        // Print all numbers from left to right
        // that are divisible by divisor.
        //
        // Each number must be followed by a space.
        for (int i = left; i <= right; i++)
        {
            if (i % divisor == 0)
            {
                System.out.print(i + " ");
            }
        }
    }
}

class MessageTask implements Runnable
{
    private final int threadNumber;

    MessageTask(int threadNumber)
    {
        this.threadNumber = threadNumber;
    }

    @Override
    public void run()
    {
        // TODO:
        // Print:
        // "Thread 2 Done " when threadNumber is 2
        // "Thread 1 Done" when threadNumber is 1
         System.out.print("Thread " + threadNumber+ " Done ");
    }
}

public class Main
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader reader =
            new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer tokenizer =
            new StringTokenizer(reader.readLine());

        int left =
            Integer.parseInt(tokenizer.nextToken());

        int right =
            Integer.parseInt(tokenizer.nextToken());

        int divisor =
            Integer.parseInt(tokenizer.nextToken());

        Thread thread1 =
            new Thread(new MessageTask(1));

        Thread thread2 =
            new Thread(new MessageTask(2));

        Thread thread3 =
            new Thread(
                new NumberTask(left, right, divisor)
            );

        // TODO:
        // Execute the threads strictly in this order:
        //
  thread3.start();
thread3.join();

// Thread 2 executes second
thread2.start();
thread2.join();

// Thread 1 executes last
thread1.start();
    }
}