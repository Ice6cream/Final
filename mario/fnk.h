#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;
/// <summary>
/// ��������� ���������� ���� �� ������� ��� ��������
/// </summary>
/// <param name="WindowSideSize">������ ����</param>
/// <returns>���������� ������������ �������� ����������</returns>
int BackgroungSpritesQuantity(int WindowSideSize) {
	WindowSideSize = WindowSideSize / 64;
	return WindowSideSize;
}

