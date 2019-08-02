import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        File file = new File("D:\\Dropbox\\Code Projects\\Project Euler\\Problem 013 Java\\resources\\number.txt");
        System.out.println(file.canRead());

        try{
            Scanner reader = new Scanner(file);

            // Grab First Number
            ArrayInt x = new ArrayInt(reader.nextLine());
            x.print();

            // Grab the rest
            while(reader.hasNextLine()){
                ArrayInt y = new ArrayInt(reader.nextLine());

                x.add(y);
            }

            reader.close();

            x.print();

       } catch (FileNotFoundException ex){
            System.out.println("File Not Found.");
        }
    }
}
