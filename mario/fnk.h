#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;
/// <summary>
/// Разбиение параметров окна на области для спрайтов
/// </summary>
/// <param name="WindowSideSize">размер окна</param>
/// <returns>количество помещающихся спрайтов бэкграунда</returns>
int BackgroungSpritesQuantity(int WindowSideSize) {
	WindowSideSize = WindowSideSize / 64;
	return WindowSideSize;
}

