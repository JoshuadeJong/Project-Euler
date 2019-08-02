import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        int min = 1;
        int max = 20;

        ArrayList<Integer> list = range(min, max, 1);

        for(int i = 1; i < list.size(); i++){
            list.set(i, lcm(list.get(i), list.get(i - 1)));
        }

        System.out.println("" + list.get(list.size()-1));

    }

    private static ArrayList<Integer> range(int min, int max, int delta){

        ArrayList<Integer> list = new ArrayList<Integer>();

        // Zero delta
        if(delta == 0){
            return list;
        } else if(delta < 0){
            int temp = min;
            min = max;
            max = temp;
        }

        for(int i = min; i < max; i += delta){
            list.add(i);
        }

        return list;
    }

    private static int gcd(int n, int m){

        do{
            while(m >= n){
                m -= n;
            }

            int temp = m;
            m = n;
            n = temp;

        }while( n > 0);

        return m;
    }

    private static int lcm(int n, int m){
        return (n*m)/gcd(n,m);
    }

}
