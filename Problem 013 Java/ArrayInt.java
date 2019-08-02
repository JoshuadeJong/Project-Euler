import java.util.ArrayList;

public class ArrayInt {

    private ArrayList<Integer> number;
    private int length;

    // Constructor
    public ArrayInt(int num){

        this.number = new ArrayList<>();
        this.length = 0;

        int2Array(num);
    }

    public ArrayInt(String num){

        this.number = new ArrayList<>();
        this.length = num.length();

        String2Array(num);
    }

    // Methods
    public void int2Array(int num){

        int index = 0;

        do{
            int r = num%10; // Find remainder

            if(this.length > index) { // Add remainder to the correct digit position
                this.number.set(index, r);
            } else {
                this.number.add(r);
                this.length++;
            }

            num = num/10;   // Remove the ones digit from the number
            index++; // Increase the index
        }while(0 < num);

    }

    public void String2Array(String num){

        for(int index = 0; index < num.length(); index++){
            int temp = Character.getNumericValue(num.charAt( num.length() - 1 - index));
            this.number.add(temp);
        }
    }

    public int array2Int(){

        int num = 0;

        for(int i = 0; i < this.length; i++){
            num += this.number.get(i)*Math.pow(10, i);
        }

        return num;
    }

    public void add(ArrayInt A){

        int index = 0;
        while(index < A.length){

            if(index <= this.length){

                // Calculations
                int x = this.number.get(index) + A.number.get(index);
                int r = x%10;
                x = (x-r)/10;

                // Place digits
                this.number.set(index, r);

                if(0 != x) {
                    if (index + 1 >= this.length) {
                        this.number.add(x);
                        this.length++;
                    } else {
                        this.number.set(index + 1, this.number.get(index + 1) + x);
                    }
                }

            } else {
                this.number.add(A.number.get(index));
            }

            index++;
        }

    }

    // Gets

    // Print
    public void print(){
        for(int index = this.length - 1; index >= 0; index--){
            System.out.printf("%d", this.number.get(index));
        }

        System.out.println();
    }


}
