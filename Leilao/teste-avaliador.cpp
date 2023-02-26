#include "Avaliador.hpp"
#include <iostream>

int main() {
	Lance primeirolance(Usuario("Pedro"), 1000);
	Lance segundolance(Usuario("Ana Maria"), 2000);
	Leilao leilao("Broinha 1554 Premium");
	leilao.recebeLance(primeirolance);
	leilao.recebeLance(segundolance);

	Avaliador leiloeiro;
	leiloeiro.avalia(leilao);

	std::cout << leiloeiro.recuperaMaiorValor() << 
		std::endl;

	return 0;
}
