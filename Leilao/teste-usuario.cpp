#include "catch.hpp"
#include "Usuario.hpp"

TEST_CASE("usuario deve saber informar o primeiro nome")
{
	Usuario pedro("Pedro Abra Cadabra");

	std::string primeiroNome = pedro.recuperaPrimeiroNome();

	REQUIRE("Pedro" == primeiroNome);
}
