import java.util.*;

class Student {
    private String name;
    private int age;
    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
}
class Codechef {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList < Student > students = new ArrayList < > ();
        for (int i = 0; i < n; i++) {
            String name = sc.next();
            int age = sc.nextInt();
            students.add(new Student(name, age));
        } 
        
         System.out.println("Eligible Students:");

        int minorCount = 0;
        Student oldest = students.get(0);

        for (Student s : students) {
            if (s.getAge() >= 18) {
                System.out.println(s.getName());
            }

            if (s.getAge() < 18) {
                minorCount++;
            }

            if (s.getAge() > oldest.getAge()) {
                oldest = s;
            }
        }

        // Print minor count
        System.out.println(
                "Minor Count: " + minorCount
        );

        // Print oldest student
        System.out.println(
                "Oldest Student: " +
                oldest.getName() +
                " " +
                oldest.getAge()
        );
        sc.close();
    }

}