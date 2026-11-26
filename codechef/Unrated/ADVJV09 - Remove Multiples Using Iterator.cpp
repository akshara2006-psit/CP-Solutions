import java.util.*;

class Codechef
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        List<Integer> numbers = new ArrayList<>();

        for (int i = 0; i < n; i++)
        {
            numbers.add(sc.nextInt());
        }

        Iterator<Integer> iterator = numbers.iterator();

        while (iterator.hasNext())
        {
            // TODO: Remove values divisible by k
            // using Iterator.remove()
            int num=iterator.next();
            if(num%k==0)
            iterator.remove();

            
        }

        if (numbers.isEmpty())
        {
            System.out.println("Empty");
        }
        else
        {
            for (int i = 0; i < numbers.size(); i++)
            {
                if (i > 0)
                {
                    System.out.print(" ");
                }

                System.out.print(numbers.get(i));
            }

            System.out.println();
        }

        sc.close();
    }
}