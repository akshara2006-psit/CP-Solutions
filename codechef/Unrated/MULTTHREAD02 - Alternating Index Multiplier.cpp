import java.util.*;

class Multiplier extends Thread
{
    // Complete the Multiplier class
    List<Integer> input;
    List<Integer> output;
    int start;
    int factor;

    Multiplier(List<Integer> input, List<Integer> output,
               int start, int factor) {

        this.input = input;
        this.output = output;
        this.start = start;
        this.factor = factor;
    }

    @Override
    public void run() {

        for (int i = start; i < input.size(); i += 2) {

            int value = input.get(i) * factor;

            output.set(i, value);

            Thread.yield();
        }
    }
}

class Codechef
{
    public static void main(String[] args)
            throws InterruptedException
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int factor = sc.nextInt();

        List<Integer> input = new ArrayList<>();

        for (int i = 0; i < n; i++)
        {
            input.add(sc.nextInt());
        }

        List<Integer> output =
                Collections.synchronizedList(
                    new ArrayList<>(
                        Collections.nCopies(n, 0)
                    )
                );

        Multiplier evenThread =
                new Multiplier(
                    input,
                    output,
                    0,
                    factor
                );

        Multiplier oddThread =
                new Multiplier(
                    input,
                    output,
                    1,
                    factor
                );

        evenThread.start();
        oddThread.start();

        evenThread.join();
        oddThread.join();

        System.out.println(
            "Output List: " + output
        );

        sc.close();
    }
}