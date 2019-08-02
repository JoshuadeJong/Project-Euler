import java.util.ArrayList;
import java.util.Collections;

public class Main {

    public static void main(String[] args) {

        int max_int = 999;
        int min_min = 800;
        int i = max_int;
        int j = max_int;

        int max_pal = 0;

        while(true){

            int num = i*j;
            if(palindromeCheck(num2Array(num))){
                if(max_pal < num){
                    max_pal = num;
                }
            }

            j--;

            if( j < min_min){
                i--;
                j = i;
            }

            if( i < min_min){
                break;
            }
        }

        System.out.println("Largest palindrome found was " + max_pal);

    }


    private static ArrayList<Integer> num2Array(int num){

        // Create a new Array
        ArrayList<Integer> num_Array = new ArrayList<>();

        // Put each digit of num into ArrayList output
        while(num > 0){
            num_Array.add(num%10);
            num /= 10;
        }

        // Reverse output to get correct order
        Collections.reverse(num_Array);

        return num_Array;
    }


    private static boolean palindromeCheck(ArrayList<Integer> list){

        for(int i = 0; i < list.size()/2; i++){

            if( !list.get(i).equals(list.get(list.size() - 1 - i)) ){
                return false;
            }
        }

        return true;
    }

}
