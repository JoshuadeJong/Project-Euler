public class Main {

    public static void main(String[] args) {
        int maxValue =  4000000;

        // Fibonacci Elements
        int F_0 = 1;
        int F_1 = 1;
        int F_2;

        // Sum
        int sum = 0;

        while(true){

            if(maxValue < F_1){
                break;
            }else if(0 == F_1%2){
                sum += F_1;
            }

            // Fibonacci Sequence
            F_2 = F_1 + F_0;

            // Shift Index Down
            F_0 = F_1;
            F_1 = F_2;

        }

        System.out.println("" + sum);
    }
}
