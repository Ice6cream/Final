#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest/doctest.h"
#include "fnk.h"
#include "mario.h"

TEST_CASE("Проверка стояния :)") {
	MainPerson abc;
	abc.x = 50;
	abc.y = 100;
	abc.u_x = 0;
	abc.u_y = 0;
	abc.ground = true;
	abc.move(5);
	CHECK(abc.x == 50);
	CHECK(abc.y == 100);
}

TEST_CASE("Проверка движения вправо") {
	MainPerson abc;
	abc.x = 50;
	abc.y = 100;
	abc.u_x = 0.2;
	abc.u_y = 0;
	abc.ground = true;
	abc.move(5);
	CHECK(abc.x == 51);
}

TEST_CASE("Проверка движения влево") {
	MainPerson abc;
	abc.x = 50;
	abc.y = 100;
	abc.u_x = -0.2;
	abc.u_y = 0;
	abc.ground = true;
	abc.move(5);
	CHECK(abc.x == 49);
}

TEST_CASE("Проверка падения") {
	MainPerson abc;
	abc.x = 50;
	abc.y = 100;
	abc.u_x = 0;
	abc.u_y = 0;
	abc.ground = false;
	abc.move(100);
	CHECK(abc.y == 112);
}

TEST_CASE("Проверка движения в падение") {
	MainPerson abc;
	abc.x = 50;
	abc.y = 100;
	abc.u_x = 0.2;
	abc.u_y = 0;
	abc.ground = false;
	abc.move(100);
	CHECK(abc.y == 112);
	CHECK(abc.x == 70);
}

TEST_CASE("Проверка прыжка") {
	MainPerson abc;
	abc.x = 50;
	abc.y = 100;
	abc.u_x = 0;
	abc.u_y = -0.5;
	abc.ground = true;
	abc.move(100);
	CHECK(abc.y == 50);
}

TEST_CASE("Проверка движения в прыжке") {
	MainPerson abc;
	abc.x = 50;
	abc.y = 100;
	abc.u_x = -0.2;
	abc.u_y = -0.5;
	abc.ground = true;
	abc.move(100);
	CHECK(abc.y == 50);
	CHECK(abc.x == 30);
}
TEST_CASE("Проверка падения в прыжке") {
	MainPerson abc;
	abc.x = 50;
	abc.y = 100;
	abc.u_x = -0.2;
	abc.u_y = -0.5;
	abc.ground = false;
	abc.move(100);
	CHECK(abc.y == 62);
	CHECK(abc.x == 30);
}

TEST_CASE("Разбиение параметров окна на области для спрайтов") {
	CHECK(BackgroungSpritesQuantity(624) == 9);
	CHECK(BackgroungSpritesQuantity(432) == 6);
	CHECK(BackgroungSpritesQuantity(700) == 10);
	CHECK(BackgroungSpritesQuantity(256) == 4);
	CHECK(BackgroungSpritesQuantity(80) == 1);
}


