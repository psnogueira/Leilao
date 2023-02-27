#include "catch.hpp"
#include "Leilao.hpp"
#include "Usuario.hpp"

TEST_CASE("Leilao nao deve receber lances consecutivos do mesmo usuario")
{
	// Arrange
	Leilao leilao("Broinha 1554 Premium");
	Usuario pedro("Pedro pedro");

	Lance primeiroLance(pedro, 1000);
	Lance segundoLance(pedro, 1500);

	// Act
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);

	//Assert
	REQUIRE(1 == leilao.recuperaLances().size());
	REQUIRE(1000 == leilao.recuperaLances()[0].recuperaValor());
}