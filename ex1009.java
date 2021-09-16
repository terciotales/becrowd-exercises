import java.util.Scanner;
class Main{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		String nome;
		double salario, vendas;
		nome = ler.next();
		salario = ler.nextDouble();
		vendas = ler.nextDouble();
		salario = salario + (vendas * 0.15);
		System.out.println("TOTAL = R$ ", salario + "\n");
	}
}