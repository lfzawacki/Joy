#ifndef __JOY_H_
#define __JOY_H_

#include "stringEx.h"
#include "fileUtils.h"

#define DEFAULT_JOY "joy"

enum {
		BUTTON_1 = 0,
		BUTTON_2,
		BUTTON_3,
		BUTTON_4,
		BUTTON_5,
		BUTTON_6,
		BUTTON_7,
		BUTTON_8,
		BUTTON_9,
		BUTTON_10,
		BUTTONS_TOTAL
};

static int buttons[BUTTONS_TOTAL] = { 1, 2, 4, 8, 16, 32, 64, 128, 256,512};

static string buttonStrings[BUTTONS_TOTAL] = { "BUTTON_1","BUTTON_2","BUTTON_3",
																							 "BUTTON_4","BUTTON_5","BUTTON_6",
																			 				 "BUTTON_7","BUTTON_8","BUTTON_9",
																							 "BUTTON_10"};

enum {
		KICK = 0,
		PASS,
		CHIP_KICK,
		DRIVE,
		BRAKE,

		HADOUKEN,
		SHORYUKEN,
		MEGABUSTER,
		Z_SABER,
		JUMP,
		ACTIONS_TOTAL
};

static string actionStrings[ACTIONS_TOTAL] = { "KICK", "PASS", "CHIP_KICK",
											   "DRIVE", "BRAKE", "HADOUKEN", "SHORYUKEN", "MEGABUSTER", "Z-SABER", "JUMP"
		 };

class Joystick {

		public:
			Joystick();
			Joystick(string joyname);

			~Joystick();
			bool isConfigured();
			void saveConfig();
			void loadConfig();
			void configureButtons();
			void mapButton(int action, int button);
			void printStatus();
			void receiveInput(int mask, int x, int y, int z);
			bool keyPressed();
			bool axesMoved();

			vector<int>  getAxes();
			vector<bool> getButtonsPressed();
			vector<int> getAll();
			//getters
			int getX();
			int getY();
			int getZ();
			int getMask();

			//setters
			void setX(int newx);
			void setY(int newy);
			void setZ(int newz);

		private:
			string name;
			int x,y,z;

			//cada ação está associada ao seu botão respectivo
			int buttonMapping[ACTIONS_TOTAL];
			//array das ações atuais;
			bool currentActions[ACTIONS_TOTAL];


			//Métodos Privados
			//retorna o índice de uma ação dada como uma string
			int getActionIndex(string action);
			//retorna o índice de um botão dado como uma string
			int getButtonIndex(string button);

			void printActions();
			void setAxes(int x, int y, int z);

};

#endif
