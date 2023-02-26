#include "Avaliador.hpp"
#include <iostream>

int main() {
	// Arrange - Given (Preparando ambiente)
	Lance primeirolance(Usuario("Pedro"), 1000);
	Lance segundolance(Usuario("Ana Maria"), 2000);
	Lance terceirolance(Usuario("Sophia"), 1500);
	Leilao leilao("Broinha 1554 Premium");
	leilao.recebeLance(segundolance);
	leilao.recebeLance(terceirolance);
	leilao.recebeLance(primeirolance);
	
	Avaliador leiloeiro;

	// Act - When (Excutando o código a ser testado)
	leiloeiro.avalia(leilao);

	// Assert - Then (Verificando se tudo deu certo)
	float valorEsperado = 2000;

	if (valorEsperado == leiloeiro.recuperaMaiorValor())
	{
		std::cout << "TESTE OK" << std::endl;
	}
	else
	{
		std::cout << "TESTE FALHOU" << std::endl;
	}

	return 0;
}
