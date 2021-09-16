import java.util.Scanner;

import java.io.IOException;
import java.util.Scanner;
public class ex1010 {
        public static void main(String[] args) throws IOException {
            Scanner ler = new Scanner(System.in);
             double R, pi, volume;
             R = ler.nextDouble();
             pi = 3.14159;
             volume = (4 * pi * (R * R * R)) / 3;    
             System.out.printf("VOLUME = %.3f\n", volume);
    }
}
