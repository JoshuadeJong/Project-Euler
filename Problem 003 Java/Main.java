import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        int number = 13;

        ArrayList<Integer> factors = PollardRho(number);

        System.out.println(factors.get(0));
        System.out.println(factors.get(1));

    }

    // Pollard Rho Algorithm
    public static ArrayList<Integer> PollardRho(int number){
        ArrayList<Integer> factors = new ArrayList<Integer>();

        int x_0 = 2;
        int cycle_size = 2;
        int x = 2;
        int factor = 1;

        while( 1 == factor){
            int count = 1;
            while(count <= cycle_size && factor <= 1){
                x = mod(x*x + 1,  number);
                factor = gcd(x - x_0, number);
                count++;
            }
            cycle_size *= 2;
            x_0 = x;
        }

        factor = Math.abs(factor);
        number /= factor;

        factors.add(factor);




        return factors;
    }

    // GCD
    public static int gcd(int a, int b){

        if(b > a){
            int temp = a;
            a = b;
            b = temp;
        }

        while(b != 0){
            int r = a % b;
            a = b;
            b = r;
        }

        return a;
    }

    // Mod function
    public static int mod(int a, int m){

        if( a > 0){
            while(a > m){
                a -= m;
            }
        } else if ( a < 0){
            while(a < 0){
                a += m;
            }
        }

        return a;
    }

}
