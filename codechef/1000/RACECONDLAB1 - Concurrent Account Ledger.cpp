===FILENAME:Codechef.java===

import java.util.*;

class Account
{
    private long balance;
    private long transactionCount;

    Account(long initialBalance)
    {
        balance = initialBalance;
        transactionCount = 0;
    }

    // 1. Make method synchronized
    public synchronized void processTransaction(long amount)
    {
        balance += amount;
        transactionCount++;
    }

    // 2. Make getter synchronized
    public synchronized long getBalance()
    {
        return balance;
    }

    // 3. Make getter synchronized
    public synchronized long getTransactionCount()
    {
        return transactionCount;
    }
}

// 4. Extend Thread class
class TransactionWorker extends Thread
{
    private final Account account;
    private final long amount;
    private final int repetitions;

    TransactionWorker(
            Account account,
            long amount,
            int repetitions)
    {
        this.account = account;
        this.amount = amount;
        this.repetitions = repetitions;
    }

    @Override
    public void run()
    {
        for (int i = 0; i < repetitions; i++)
        {
            account.processTransaction(amount);

            if (i % 100 == 0)
            {
                Thread.yield();
            }
        }
    }
}

class Codechef
{
    public static void main(String[] args)
            throws InterruptedException
    {
        Scanner sc = new Scanner(System.in);

        long initialBalance = sc.nextLong();
        int n = sc.nextInt();

        Account account =
                new Account(initialBalance);

        TransactionWorker[] workers =
                new TransactionWorker[n];

        for (int i = 0; i < n; i++)
        {
            long amount = sc.nextLong();
            int repetitions = sc.nextInt();

            workers[i] =
                    new TransactionWorker(
                            account,
                            amount,
                            repetitions
                    );
        }

        for (TransactionWorker worker : workers)
        {
            worker.start();
        }

        for (TransactionWorker worker : workers)
        {
            worker.join();
        }

        System.out.println(
                "Final Balance: " +
                account.getBalance()
        );

        System.out.println(
                "Transactions Processed: " +
                account.getTransactionCount()
        );

        sc.close();
    }
}
