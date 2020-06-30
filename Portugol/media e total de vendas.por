programa
{
	funcao inicio()
	{
		cadeia vendedor
		real jan, fev, mar, abr, total, media
		
		escreva("Informe o nome do vendedor:")
		leia(vendedor)
		escreva("Informe o resultado de vendas em Janeiro:")
		leia(jan)
		escreva("Informe o resultado de vendas em Fevereiro:")
		leia(fev)
		escreva("Informe o resultado de vendas em Março:")
		leia(mar)
		escreva("Informe o resultado de vendas em Abril:")
		leia(abr)

		total = jan + fev + mar + abr
		media = total/4

		escreva(vendedor + " vendeu no tota: R$ " + total + " com média de: R$ " + media)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 491; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */