===FILENAME:Codechef.java===

import java.io.*;
import java.util.*;

class Worker extends Thread
{
    private final int n;
    private final int checkpoint;

    long sum = 0;
    int processed = 0;

    volatile boolean checkpointReached = false;
    boolean interrupted = false;

    Worker(int n, int checkpoint)
    {
        this.n = n;
        this.checkpoint = checkpoint;
    }

    @Override
    public void run()
    {
        try
        {
            for (int i = 1; i <= n; i++)
            {
                sum += i;
                processed++;

                if (i == checkpoint)
                {
                    checkpointReached = true;

                    Thread.sleep(60000);
                }
                else if (i < checkpoint)
                {
                    Thread.yield();
                }
            }
        }
        catch (InterruptedException e)
        {
            interrupted = true;
        }
    }
}

class ThreadCoordinator
{
    private final Worker worker;

    ThreadCoordinator(Worker worker)
    {
        this.worker = worker;
    }

    public void execute() throws InterruptedException
    {
        worker.start();

        while (!worker.checkpointReached)
        {
            Thread.yield();
        }

        worker.interrupt();

        worker.join();
    }
}

class Codechef
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

        Worker worker = new Worker(n, k);

        ThreadCoordinator coordinator =
                new ThreadCoordinator(worker);

        coordinator.execute();

        System.out.println(worker.sum);
        System.out.println(worker.processed);

        if (worker.interrupted)
        {
            System.out.println("INTERRUPTED");
        }
    }
}
