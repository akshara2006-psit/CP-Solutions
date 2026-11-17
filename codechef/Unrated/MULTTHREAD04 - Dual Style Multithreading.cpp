import java.util.*;

class MyRunnable implements Runnable
{
    private final int n;
    private final StringBuilder output;

    MyRunnable(int n)
    {
        this.n = n;
        this.output = new StringBuilder();
    }

    @Override
    public void run()
    {
        // TODO:
        // Generate:
        // RunnableTask - Count: i
        // for i = 1 to n
         for (int i = 1; i <= n; i++)
        {
            output.append("RunnableTask - Count: " + i + "\n");
        }
    }

    String getOutput()
    {
        return output.toString();
    }
}

class MyThread extends Thread
{
    private final int n;
    private final StringBuilder output;

    MyThread(int n)
    {
        this.n = n;
        this.output = new StringBuilder();
    }

    @Override
    public void run()
    {
        // TODO:
        // Generate:
        // ThreadTask - Count: i
        // for i = 1 to n
         for (int i = 1; i <= n; i++)
        {
            output.append("ThreadTask - Count: " + i + "\n");
        }
    }

    String getOutput()
    {
        return output.toString();
    }
}

class Codechef
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // TODO 1: Create an object of MyRunnable.
         MyRunnable runnableTask = new MyRunnable(n);
   

        // TODO 2: Create a Thread using runnableTask.
         Thread runnableThread = new Thread(runnableTask);

        // TODO 3: Create an object of MyThread.
      MyThread threadTask = new MyThread(n);

        // TODO 4: Start both threads.
 runnableThread.start();
        threadTask.start();

        // TODO 5: Wait for both threads to finish using join().
        runnableThread.join();
        threadTask.join();


        System.out.print(runnableTask.getOutput());
        System.out.print(threadTask.getOutput());

        System.out.println("Both threads completed.");

        sc.close();
    }
}