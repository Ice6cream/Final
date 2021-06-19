// mario.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include "fnk.h"
#include <SFML/Graphics.hpp>

using namespace sf;


/// \ - спавн объектов на карте.
class TXTR {
public:
	Texture TaleWall, PinkManFall, PinkManStop, PinkManRun, PinkManJump, PinkManDoubleJump,
		NinjaFrogFall, NinjaFrogStop, NinjaFrogRun, NinjaFrogJump, NinjaFrogDoubleJump,
		MaskDudeFall, MaskDudeStop, MaskDudeRun, MaskDudeJump, MaskDudeDoubleJump,
		VirtualGuyFall, VirtualGuyStop, VirtualGuyRun, VirtualGuyJump, VirtualGuyDoubleJump,
		MainSceneBrown, MainSceneBlue, MainSceneGray, MainSceneGreen,
		MainScenePink, MainScenePurple, MainSceneYellow, StartN, Confetti;
	/// <summary>
	/// загрузка текстур
	/// </summary>
	void txtr() {

		MainSceneBrown.loadFromFile("pichi\\Background\\Brown.png");
		MainSceneBlue.loadFromFile("pichi\\Background\\Blue.png");
		MainSceneGray.loadFromFile("pichi\\Background\\Gray.png");
		MainSceneGreen.loadFromFile("pichi\\Background\\Green.png");
		MainScenePink.loadFromFile("pichi\\Background\\Pink.png");
		MainScenePurple.loadFromFile("pichi\\Background\\Purple.png");
		MainSceneYellow.loadFromFile("pichi\\Background\\Yellow.png");


		TaleWall.loadFromFile("pichi\\Terrain\\Terrain (16x16).png");


		NinjaFrogFall.loadFromFile("pichi\\Ninja Frog\\Fall (32x32).png");
		NinjaFrogStop.loadFromFile("pichi\\Ninja Frog\\Idle (32x32).png");
		NinjaFrogRun.loadFromFile("pichi\\Ninja Frog\\Run (32x32).png");
		NinjaFrogJump.loadFromFile("pichi\\Ninja Frog\\Jump (32x32).png");
		NinjaFrogDoubleJump.loadFromFile("pichi\\Ninja Frog\\Double Jump (32x32).png");

		PinkManFall.loadFromFile("pichi\\Pink Man\\Fall.png");
		PinkManStop.loadFromFile("pichi\\Pink Man\\Idle (32x32).png");
		PinkManRun.loadFromFile("pichi\\Pink Man\\Run (32x32).png");
		PinkManJump.loadFromFile("pichi\\Pink Man\\Jump (32x32).png");
		PinkManDoubleJump.loadFromFile("pichi\\Pink Man\\Double Jump (32x32).png");

		MaskDudeFall.loadFromFile("pichi\\Mask Dude\\Fall (32x32).png");
		MaskDudeStop.loadFromFile("pichi\\Mask Dude\\Idle (32x32).png");
		MaskDudeRun.loadFromFile("pichi\\Mask Dude\\Run (32x32).png");
		MaskDudeJump.loadFromFile("pichi\\Mask Dude\\Jump (32x32).png");
		MaskDudeDoubleJump.loadFromFile("pichi\\Mask Dude\\Double Jump (32x32).png");

		VirtualGuyFall.loadFromFile("pichi\\Virtual Guy\\Fall (32x32).png");
		VirtualGuyStop.loadFromFile("pichi\\Virtual Guy\\Idle (32x32).png");
		VirtualGuyRun.loadFromFile("pichi\\Virtual Guy\\Run (32x32).png");
		VirtualGuyJump.loadFromFile("pichi\\Virtual Guy\\Jump (32x32).png");
		VirtualGuyDoubleJump.loadFromFile("pichi\\Virtual Guy\\Double Jump (32x32).png");


		StartN.loadFromFile("pichi\\Items\\Checkpoints\\Start\\Start (idle).png");
		Confetti.loadFromFile("pichi\\Other\\Confetti (16x16).png");
	}

};

/// \ - движение персонажа.
class MainPerson
{
public:
	float x; /// <param name="x"> -  координата персонажа по Х </param>
	float y; /// <param name="y"> - координата персонажа по Y </param>
	float u_x; /// <param name="u_x"> - скорость по Х </param>
	float u_y; /// <param name="u_y"> - скорость по Y </param> 
	bool ground; /// <param name="ground"> - определение земли </param> 

	/// <summary>
	/// функция движения объекта
	/// </summary>
	/// <param name="time"> прошедшее время</param>
	void move(float time) {
		x += u_x * time; 
		if (!ground) u_y = u_y + 0.0012 * time; 
		y += u_y * time;

		ground = false;

		if (y > 352) {  
			y = 352;
			u_y = 0;
			ground = true;
		}
	}
};