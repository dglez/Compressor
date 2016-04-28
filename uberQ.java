import java.util.Random;
import java.util.HashMap;
public class uberQ {
	public static void main(String[] args){
		String [] elements = {"a", "b", "c"};
		int [] weights = {10, 2, 3};

        //loop 600 times
        //count when is a, b, or c
        //print times counted for each element
       

	}
	public static String choose(String[] elements, int[] weights){
		Random r = new Random();
		int base = 0;
		int seed = 0;

		for (int x : weights ) {
		 	base += x;
		 } 

		seed = r.nextInt(base);
		int temp = weights[0];

		for (int i = 0; i < weights.length ; i++ ) {

			if (seed <= temp) {
				return elements[i];
			}
			temp += weights[i + 1];

			
		}
		return "not here";



	}

}