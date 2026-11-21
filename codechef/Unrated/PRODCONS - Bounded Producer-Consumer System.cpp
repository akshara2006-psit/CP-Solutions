import java.util.*;

class SharedResource
{
    private final Queue<Integer> buffer;
    private final int capacity;

    private int nextIndex = 0;
    private int activeProducers;

    private int producedCount = 0;
    private int consumedCount = 0;

    private long producedSum = 0;
    private long consumedSum = 0;

    SharedResource(int capacity, int producerCount)
    {
        this.capacity = capacity;
        this.activeProducers = producerCount;
        this.buffer = new LinkedList<>();
    }

    public synchronized Integer getNextItem(int[] items)
    {
        // TODO:
        // Return the next unprocessed item.
         if (nextIndex >= items.length) {
            return null;
        }

        return items[nextIndex++];
    }

    public synchronized void produce(int item)
        throws InterruptedException
    {
        // TODO:
        // 1. Wait while the buffer is full.
        // 2. Add the item to the buffer.
        // 3. Update producedCount and producedSum.
        // 4. Wake waiting threads using notifyAll().
        while (buffer.size() == capacity) {
            wait();
        }

        buffer.add(item);

        producedCount++;
        producedSum += item;

        notifyAll();
    }

    public synchronized Integer consume()
        throws InterruptedException
    {
        // TODO:
        // 1. Wait while the buffer is empty
        //    and producers are still active.
        // 2. If all producers are finished and
        //    the buffer is empty, return null.
        // 3. Remove an item from the buffer.
        // 4. Update consumedCount and consumedSum.
        // 5. Wake waiting threads using notifyAll().
  while (buffer.isEmpty() && activeProducers > 0) {
            wait();
        }

        if (buffer.isEmpty() && activeProducers == 0) {
            return null;
        }

        int item = buffer.remove();

        consumedCount++;
        consumedSum += item;

        notifyAll();

        return item;
    }

    public synchronized void producerFinished()
    {
        // TODO:
        // Decrease activeProducers and notify
        // all waiting threads.
        
        activeProducers--;

        notifyAll();
    }

    public synchronized int getProducedCount()
    {
       return producedCount;
        
    }

    public synchronized int getConsumedCount()
    {
        // TODO

        return consumedCount;
    }

    public synchronized long getProducedSum()
    {
        // TODO

        return producedSum;
    }

    public synchronized long getConsumedSum()
    {
        // TODO

        return consumedSum;
    }

    public synchronized boolean isEmpty()
    {
        return buffer.isEmpty();
    }
}

class Consumer extends Thread {

    private final SharedResource resource;

    Consumer(SharedResource resource) {
        this.resource = resource;
    }

    @Override
    public void run() {

        try {

            while (true) {

                Integer item = resource.consume();

                if (item == null) {
                    break;
                }

                // Process the consumed item
            }

        } catch (InterruptedException e) {

            Thread.currentThread().interrupt();
        }
    }
}
class Producer extends Thread {

    private final SharedResource resource;
    private final int[] items;

    Producer(SharedResource resource, int[] items) {
        this.resource = resource;
        this.items = items;
    }

    @Override
    public void run() {

        try {

            while (true) {

                Integer item = resource.getNextItem(items);

                if (item == null) {
                    break;
                }

                resource.produce(item);
            }

        } catch (InterruptedException e) {

            Thread.currentThread().interrupt();

        } finally {

            resource.producerFinished();
        }
    }
}


class Codechef
{
    public static void main(String[] args)
            throws InterruptedException
    {
        Scanner sc = new Scanner(System.in);

        int capacity = sc.nextInt();
        int producerCount = sc.nextInt();
        int consumerCount = sc.nextInt();

        int n = sc.nextInt();

        int[] items = new int[n];

        for (int i = 0; i < n; i++)
        {
            items[i] = sc.nextInt();
        }

        SharedResource resource =
                new SharedResource(
                        capacity,
                        producerCount
                );

        Producer[] producers =
                new Producer[producerCount];

        Consumer[] consumers =
                new Consumer[consumerCount];

        for (int i = 0; i < producerCount; i++)
        {
            producers[i] =
                    new Producer(resource, items);

            producers[i].start();
        }

        for (int i = 0; i < consumerCount; i++)
        {
            consumers[i] =
                    new Consumer(resource);

            consumers[i].start();
        }

        for (Producer producer : producers)
        {
            producer.join();
        }

        for (Consumer consumer : consumers)
        {
            consumer.join();
        }

        System.out.println(
                "Produced Count: " +
                resource.getProducedCount()
        );

        System.out.println(
                "Consumed Count: " +
                resource.getConsumedCount()
        );

        System.out.println(
                "Produced Sum: " +
                resource.getProducedSum()
        );

        System.out.println(
                "Consumed Sum: " +
                resource.getConsumedSum()
        );

        System.out.println(
                "Buffer Empty: " +
                resource.isEmpty()
        );

        sc.close();
    }
}