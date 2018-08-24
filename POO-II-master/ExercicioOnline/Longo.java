/*Alunos de cursos longos: matr�cula, nome, ano de entrada, nota1, nota2 e nota3.
 * A m�dia final para esta categoria � representada atrav�s de conceito
 * (A se m�dia est� entre 9.01 e 10, B se a m�dia est� 7.01 e 9, C se a m�dia est� entre 5.01 e 7, E se a m�dia for menor que 5),
 * a m�dia para convers�o � obtida pela m�dia aritm�tica simples das 3 notas do aluno. O aluno desta categoria � considerado aprovado
 * se possuir conceito A ou B;
 */

public class Longo extends Aluno{
	double nota1, nota2, nota3;
	
	public Longo() {
		
	}
	
	public Longo(double matricula, String nome, int ano, double nota1, double nota2, double nota3) {
		super(matricula, nome, ano);
		this.nota1 = nota1;
		this.nota2 = nota2;
		this.nota3 = nota3;
	}
	
	public Longo criarLongo(double matricula, String nome, int ano, double nota1, double nota2, double nota3) {
		Longo longo = new Longo(matricula, nome, ano, nota1, nota2, nota3);
		Aluno[] matriz = Aluno.matrizalunos;
		matriz[Aluno.getContagem()] = longo;
		Aluno.setMatriz(matriz);
		return longo;
		
	}
	
	public double calculaMedia() {
		double media = (nota1 + nota2 + nota3)/3;
		return media;
		
	}
	
	public char calculaConceito() {
		double media = calculaMedia();
		char conceito = 'E';
		if(media>5) {
			conceito = 'C';
			if(media > 7) {
				conceito = 'B';
				if(media > 9) {
					conceito = 'A';
				}
			}
		}
		
		return conceito;
		
	}
	
	public boolean checaAprovado() {
		boolean aprovado = false;
		char conceito = calculaConceito();
		if(conceito == 'A' || conceito == 'B') {
			aprovado = true;
		}
		return aprovado;
		
	}

}
