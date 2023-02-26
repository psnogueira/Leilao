#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Avaliador.hpp"

TEST_CASE("Deve recuperar maior lance de leilao em ordem crescente") {
	// Arrange - Given (Preparando ambiente)
	Lance primeirolance(Usuario("Pedro"), 1000);
	Lance segundolance(Usuario("Ana Maria"), 1500);
	Lance terceirolance(Usuario("Sophia"), 2000);
	Leilao leilao("Broinha 1554 Premium");
	leilao.recebeLance(primeirolance);
	leilao.recebeLance(segundolance);
	leilao.recebeLance(terceirolance);
	
	Avaliador leiloeiro;

	// Act - When (Excutando o código a ser testado)
	leiloeiro.avalia(leilao);

	// Assert - Then (Verificando se tudo deu certo)
	REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar maior lance de leilao em ordem decrescente") {
	// Arrange - Given (Preparando ambiente)
	Lance primeirolance(Usuario("Pedro"), 1000);
	Lance segundolance(Usuario("Ana Maria"), 1500);
	Lance terceirolance(Usuario("Sophia"), 2000);
	Leilao leilao("Broinha 1554 Premium");
	leilao.recebeLance(terceirolance);
	leilao.recebeLance(segundolance);
	leilao.recebeLance(primeirolance);

	Avaliador leiloeiro;

	// Act - When (Excutando o código a ser testado)
	leiloeiro.avalia(leilao);

	// Assert - Then (Verificando se tudo deu certo)
	REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}


