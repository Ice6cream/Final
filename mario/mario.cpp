#include <SFML/Graphics.hpp>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include "mario.h" 
#include <SFML/Audio.hpp>
#include "fnk.h"
using namespace sf;
using namespace std;


int main()
{

	MainPerson PMan; 
	PMan.u_x = 0;
	PMan.u_y = 0;
	PMan.x = 50;
	PMan.y = 150;

	TXTR texture;
	texture.txtr(); //Загрука всех текстур

	int W_Length = 624; /// <param name="W_Lenght"> - длина окна </param>
	int W_Width = 432; /// <param name="W_Width"> - ширина окна </param>

	bool Rotation = 1; /// <param name="Rotation"> - поворот спрайта </param>

	Clock clock; /// <param name="clock"> - время </param>

	float frame = 0; /// <param name="frame"> - кадры </param>

	float frame2 = 0; /// <param name="frame2"> - доп.переменная кадров </param>

	bool Ground = false; /// <param name="Ground"> - определение земли </param> 


	/// <param name="MapLVL"> - игровая карта </param> 
	String MapLVL[13] = { // S - стартовый флажок
	"         ",          // N - платформа1
	"      SN ",		  // C - Confetti
	"       N ",
	"   N     ",
	"         ",
	"         ",
	"    FN   ",
	"     N M ",
	"    CN   ",
	"      N  ",
	"         ",
	" VN      ",
	"         ",
	};


	RenderWindow LVLwindow(VideoMode(W_Length, W_Width), "Mario_no_net"); //Создание объекта класса RenderWindow, в котором отображается 2d графика

	/// <param name="Conft"> - бонус </param> 
	Sprite Conft;
	Conft.setTexture(texture.Confetti);

	/// <param name="PinkMan"> - главный персонаж </param> 
	Sprite PinkMan;
	PinkMan.setTexture(texture.PinkManStop);
	PinkMan.setTextureRect(IntRect(0, 0, 32, 32));

	/// <param name="NF"> - дп персонаж </param> 
	Sprite NF;
	NF.setTexture(texture.NinjaFrogStop);
	NF.setTextureRect(IntRect(0, 0, 32, 32));

	/// <param name="MD"> - доп персонаж </param> 
	Sprite MD;
	MD.setTexture(texture.MaskDudeStop);
	MD.setTextureRect(IntRect(0, 0, 32, 32));

	/// <param name="VG"> - доп персонаж </param> 
	Sprite VG;
	VG.setTexture(texture.VirtualGuyStop);
	VG.setTextureRect(IntRect(0, 0, 32, 32));

	/// <param name="Background"> - задний фон </param> 
	Sprite Background;
	Background.setTexture(texture.MainSceneBrown);

	/// <param name="TaleMap"> - рамка </param> 
	Sprite TaleMap;
	TaleMap.setTexture(texture.TaleWall);
	TaleMap.setTextureRect(IntRect(0, 64, 48, 48));

	/// <param name="Platform"> - платформа </param> 
	Sprite Platform;
	Platform.setTexture(texture.TaleWall);
	Platform.setTextureRect(IntRect(96, 64, 48, 48));

	/// <param name="Start"> - стартовый флажок </param> 
	Sprite Start;
	Start.setTexture(texture.StartN);


	//Цикл, работающий пока окно открыто
	while (LVLwindow.isOpen())
	{
		/*Идея с взята с форума(честно, не помню какого). Код ниже, до "------------" взят оттуда*/
		float time = clock.getElapsedTime().asMilliseconds(); //Переменная, считывающая время с последнего тика
		clock.restart(); //Рестарт переменной время

		frame += 0.02 * time; //Счетчик кадров
		/*------------*/

		frame2 += 0.005 * time; //Дополнительный счетчик кадров

		/*Условия для смены кадров анимации покоя*/
		if (int(frame2) % 5 == 0) Conft.setTextureRect(IntRect(0, 0, 16, 16));
		if (int(frame2) % 5 == 1) Conft.setTextureRect(IntRect(16, 0, 16, 16));
		if (int(frame2) % 5 == 2) Conft.setTextureRect(IntRect(32, 0, 16, 16));
		if (int(frame2) % 5 == 3) Conft.setTextureRect(IntRect(48, 0, 16, 16));
		if (int(frame2) % 5 == 4) Conft.setTextureRect(IntRect(64, 0, 16, 16));

		Event event; /// <param name="event"> - событие в окне </param> 
		while (LVLwindow.pollEvent(event)) //Метод pollEvent(event) перебирает собития, происходящие в окне
		{
			if (event.type == Event::Closed) //Закрытие окна
				LVLwindow.close();
		}

		//Условие для анимации покоя
		if (frame > 11) frame = frame - 11;
		PinkMan.setTexture(texture.PinkManStop);
		if (Rotation) {
			PinkMan.setTextureRect(IntRect(0 + 32 * int(frame), 0, 32, 32));
			NF.setTextureRect(IntRect(0 + 32 * int(frame), 0, 32, 32));
			MD.setTextureRect(IntRect(0 + 32 * int(frame), 0, 32, 32));
			VG.setTextureRect(IntRect(0 + 32 * int(frame), 0, 32, 32));
		}
		else PinkMan.setTextureRect(IntRect(32 + 32 * int(frame), 0, -32, 32));


		//Keyboard::isKeyPressed - обработка события "нажатие клавиши"
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			///PinkMan.move(-0.2*time, 0);
			PMan.u_x = -0.2; //передача отрицательной проекции скорости по x

			Rotation = 0; //Установка поворота

			//Анимация движения влево
			if (frame > 12) frame = frame - 12;
			PinkMan.setTexture(texture.PinkManRun);
			PinkMan.setTextureRect(IntRect(32 + 32 * int(frame), 0, -32, 32));
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			///PinkMan.move(0.2*time, 0);
			PMan.u_x = 0.2; //передача положительной проекции скорости по x

			Rotation = 1;//Установка поворота

			//Анимация движения вправо
			if (frame > 12) frame = frame - 12;
			PinkMan.setTexture(texture.PinkManRun);
			PinkMan.setTextureRect(IntRect(0 + 32 * int(frame), 0, 32, 32));
		}



		if (Keyboard::isKeyPressed(Keyboard::W)) {

			if (PMan.ground) { //условие прыжка: если перс на земле, можно прыгать
				
				PMan.u_y = -0.5;// установка проекции скорости по y
				PMan.ground = false;
			}

		}

		LVLwindow.clear(); //Отчистка окна

		//установка бэкграунда окна 
		for (int i = 0; i < BackgroungSpritesQuantity(W_Length); i++) {
			for (int k = 0; k < BackgroungSpritesQuantity(W_Width); k++) {
				Background.setPosition(i * 64, k * 64);
				LVLwindow.draw(Background);
			};



		}

		//Установка стенок лвла
		for (int i = 0; i < W_Length / 48; i++) {
			for (int k = 0; k < W_Width / 48; k++) {
				TaleMap.setPosition(i * 48, k * 48);
				if (i == 0 || i == W_Length / 48 - 1 || k == 0 || k == W_Width / 48 - 1) LVLwindow.draw(TaleMap);
			};
		}

		for (int i = 0; i < 13; i++) {
			for (int k = 0; k < 9; k++) {
				Platform.setPosition(i * 48, k * 48);
				Start.setPosition(i * 48, k * 48);
				Conft.setPosition(i * 48, k * 48);
				NF.setPosition(i * 48, k * 48 + 16);
				MD.setPosition(i * 48, k * 48 + 16);
				VG.setPosition(i * 48, k * 48 + 16);
				if (MapLVL[i][k] == 'N') LVLwindow.draw(Platform);
				if (MapLVL[i][k] == 'S') LVLwindow.draw(Start);
				if (MapLVL[i][k] == 'C') LVLwindow.draw(Conft);
				if (MapLVL[i][k] == 'F') LVLwindow.draw(NF);
				if (MapLVL[i][k] == 'M') LVLwindow.draw(MD);
				if (MapLVL[i][k] == 'V') LVLwindow.draw(VG);
			};
		}
		PMan.move(time); //запуск функции передвижения
		PinkMan.setPosition(PMan.x, PMan.y); //перемещение персонажа
		PMan.u_x = 0;
		/*Расчитывание столкновения с объектами
		Происходит проверка, находится персонаж хотя бы частитчно в клеткеб
		где есть игровой объект*/
		
		for (int i = (PMan.x + 1) / 48; i < (PMan.x + 31) / 48; i++) {
			for (int k = (PMan.y + 1) / 48; k < (PMan.y + 31) / 48; k++) {
				if (MapLVL[i][k] == 'N') //Проверка столкновения с платформой
				{
					{

						if (PMan.u_x > 0) {PMan.x = i * 48 - 33;}
						if (PMan.u_x < 0) {PMan.x = i * 48 + 33;}
						if (PMan.u_y > 0) { PMan.y = (k) * 48 - 32;   PMan.u_y = 0;   PMan.ground = true; }
						if(PMan.u_y < 0) { PMan.y = (k + 1) * 48;   PMan.u_y = 0; }
						
		

					}
				}
				if (MapLVL[i][k] == 'C') //Проверка столкновения с бонусом
				{
					MapLVL[i][k] = ' ';
				}
			}
		}

		LVLwindow.draw(PinkMan); //Отрисовка персонажа
		LVLwindow.display(); //Отричсовка окна
	}

	return 0;
}