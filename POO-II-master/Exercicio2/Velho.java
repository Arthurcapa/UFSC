
public class Velho extends Imovel { //o desconto nas casas velhas � de 15%
	protected int valorFinal;
	
	public Velho() {
		
	}
	
	public Velho(String endereco, int preco) {
		super(endereco, preco);
		this.valorFinal = (int)(preco*0.85);
	}

	public int getValorFinal() {
		return (int) (preco*0.85);
	}

	public void setValorFinal(int preco) {
		this.valorFinal = (int) (preco*0.85);
	}
	
	public void imprimeValorFinal() {
		System.out.println("O valor final da casa, j� com o desconto, � " +this.valorFinal);
	}
	
	
	

}
