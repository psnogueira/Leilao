#include "catch.hpp"
#include "Avaliador.hpp"

Leilao emOrdemCrescente()
{
	Lance primeirolance(Usuario("Pedro"), 1000);
	Lance segundolance(Usuario("Ana Maria"), 1500);
	Lance terceirolance(Usuario("Sophia"), 2000);
	Leilao leilao("Broinha 1554 Premium");
	leilao.recebeLance(primeirolance);
	leilao.recebeLance(segundolance);
	leilao.recebeLance(terceirolance);

	return leilao;
}

Leilao emOrdemDecrescente()
{
	Lance primeirolance(Usuario("Pedro"), 1000);
	Lance segundolance(Usuario("Ana Maria"), 1500);
	Lance terceirolance(Usuario("Sophia"), 2000);
	Leilao leilao("Broinha 1554 Premium");
	leilao.recebeLance(terceirolance);
	leilao.recebeLance(segundolance);
	leilao.recebeLance(primeirolance);

	return leilao;
}

TEST_CASE("Avaliador")
{
	// Arrange - Given (Preparando ambiente)
	Avaliador leiloeiro;

	SECTION("Leiloes ordenados")
	{
		Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());

		SECTION("Deve recuperar maior lance de leilao") {
			// Act - When (Excutando o código a ser testado)
			leiloeiro.avalia(leilao);

			// Assert - Then (Verificando se tudo deu certo)
			REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
		}

		SECTION("Deve recuperar menor lance de leilao") {
			// Act - When (Excutando o código a ser testado)
			leiloeiro.avalia(leilao);

			// Assert - Then (Verificando se tudo deu certo)
			REQUIRE(1000 == leiloeiro.recuperaMenorValor());
		}
	}

	SECTION("Deve recuperar os 3 maiores lances") {
		// Arrange - Given (Preparando ambiente)
		Lance primeirolance(Usuario("Pedro Joao"), 1000);
		Lance segundolance(Usuario("Ana Maria"), 2000);
		Lance terceirolance(Usuario("Sophia Vilhena"), 1500);
		Lance quartolance(Usuario("Matheus Soares"), 2500);

		Leilao leilao("Broinha 1554 Premium");
		leilao.recebeLance(primeirolance);
		leilao.recebeLance(segundolance);
		leilao.recebeLance(terceirolance);
		leilao.recebeLance(quartolance);

		// Act - When (Excutando o código a ser testado)
		leiloeiro.avalia(leilao);

		// Assert - Then (Verificando se tudo deu certo)
		std::vector<Lance> maiores3lances = leiloeiro.recupera3MaioresLances();
		REQUIRE(3 == maiores3lances.size());
		REQUIRE(2500 == maiores3lances[0].recuperaValor());
		REQUIRE(2000 == maiores3lances[1].recuperaValor());
		REQUIRE(1500 == maiores3lances[2].recuperaValor());
	}
}

