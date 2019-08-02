public class Main {

    public static void main(String[] args) {

        int numMax = 1000;
        int[] divisors = { 3, 5};
        int sum = 0;

        for(int i = 0; i < numMax; i++){
            if(OR_divCheck( i, divisors)){
                sum = sum + i;
            }
        }

        System.out.println("The sum of all the multiples of " + toString(divisors)
                + " below " + numMax + " is " + sum);

    }

    public static boolean OR_divCheck(int num, int[] divisors){

        boolean flag = false;

        for(int i = 0; i < divisors.length; i++){
            if( 0 == num % divisors[i]){
                flag = true;
            }
        }

        return flag;
    }

    public static boolean AND_divCheck(int num, int[] divisors){

        for(int i = 0; i < divisors.length; i++){
            if( 0 != num % divisors[i]){
                return false;
            }
        }

        return true;
    }

    public static String toString(int[] divisors){
        String output = "[";

        for(int i = 0; i < divisors.length; i++){
            if(divisors.length - 1 == i){
                output += divisors[i] + "]";
            } else {
                output += divisors[i] + ", ";
            }
        }

        return output;
    }

}
